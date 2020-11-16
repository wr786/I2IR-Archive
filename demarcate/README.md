# 对数据标定的个人理解

首先，ppt只有7页，我们先筛选掉无用信息的几页。

显然，第1、2页是和数据标定无关的。第6、7页同理。

第5页看上去可能挺复杂的，但是仔细看看可以发现它其实是在说怎么用代码控制小车，而这正是实习课3中要做的，并非此次作业内容。

那么只剩第3页和第4页了，其中：

- 第4页说明了`.odom`文件中各列分别是什么意思
- 第3页告诉我们了要标定什么并且怎么标定。下面我们就该对这个进行分析。

## 编码器标定

> 1.编码器标定
>
>  数据格式：odom
>
>  采集方式：小车沿直线行驶指定长度（详细数值见标定数据文件夹下的readme）
>
>  标定操作：计算行驶中累计的编码器脉冲计数，计算每个脉冲对应的实际距离
>
>  （即DistancePerPulse变量，单位为m）

此外，再结合数据zip中的`readme.txt`：

> 文件夹名对应车名；
> dis.odom:小车直行一定距离产生的数据     注意： mini1、mini3、mini4直行1.0319米，mini7直行1.128米
> rot.odom:小车原地旋转两圈（720度）产生的数据
>
> .odom文件定义及标定任务见教学网“实习课3准备工作.pptx”

也就是说，我们已知：

- 这四辆车每辆实际走了多长
- 这四辆车每辆在路上的脉冲计数

要求：

- `DistancePerPulse`。也就是`实际距离/总脉冲数`

而求总脉冲数，需要注意的就是可能倒车情况以及溢出（这两个在`HW1`中应该都已经解决了）那么，我们可以写出如下的代码：

```python
# 标定编码器，DistancePerPulse与IMU
with open(f'./{filefolder}/dis.odom') as f: # 打开对应的dis.odom文件
    datas = f.readlines() 					# 读取所有行，并存到datas数组里
    pulses = [float(line[5]) for line in datas] # 单独拿出每行中的pulse放到数组
    accPulse = 0 			# 记录总脉冲数
    lastPulse = 0 			# 记录上一个脉冲数
    for pulse in pulses: 	# 遍历每一个pulse
        accPulse += pulse - lastPulse 	# 总脉冲数 += 新的pulse - 旧的pulse
        if abs(pulse - lastPulse) > maxPulse / 2:   # 处理溢出
            accPulse += 300 	# 查看过数据了，maxPulse仍然是300
        lastPulse = pulse 
    print(f"[INFO] DistancePerPulse = {actualDist[agentID] / accPulse}")
```

## IMU朝向角标定

> 2.IMU朝向角标定
>
>  数据格式：odom
>
>  采集方式：小车原地逆时针旋转指定圈数（详细数值见标定数据文件夹下的readme）
>
>  标定操作：防止IMU不完全水平带来的精度影响，计算yaw变化量与真值之间的线性系数

仍然结合数据zip中的`readme.txt`，我们知道每辆车都旋转了`4pi`的角度。

我们已知：

- 每辆车实际旋转了多大的角度
- 每辆车的yaw变化量

要求：

- “yaw变化量与真值之间的线性系数”，那么也就是`总yaw变化量 / 总实际旋转角度`

而求总yaw变化量，要考虑的是数据中会出现的从`6.2+`变到`-0.000x`或恰恰相反的情况，我**个人认为**这也是一种溢出，那么应该用`min(6.28 - abs(yaw) + abs(lastYaw), 6.28 + abs(yaw) - abs(lastYaw) )`来计算真实的变化量。

那么代码为：

```python
# 标定yaw变化量/真值
with open(f'./{filefolder}/rot.odom') as f:
    datas = f.readlines() 
    yaws = [float(line[3]) for line in datas] 	# 同上，读取每行的yaw并存到数组
    # 如果突变大于6，就可以认为是溢出
    deltaYaw = 0 	# 总变化量
    lastYaw = 0
    for yaw in yaws:
        if abs(yaw - lastYaw) > 6:
            deltaYaw += min(6.28 - abs(yaw) + abs(lastYaw), 6.28 + abs(yaw) - abs(lastYaw) )
        else:
            deltaYaw += abs(yaw - lastYaw) 	# 没溢出就这样算
        lastYaw = yaw
    print(f"[INFO] deltaYaw / actualRot = {deltaYaw / actualRot}")
```

## 运行结果

> 1
> [INFO] DistancePerPulse = 0.1289875
> [INFO] deltaYaw / actualRot = 0.7961783439490445
>
> 3
> [INFO] DistancePerPulse = 0.20638
> [INFO] deltaYaw / actualRot = 51.114649681528626
>
> 4
> [INFO] DistancePerPulse = 0.20638
> [INFO] deltaYaw / actualRot = 1.2738853503184713
>
> 7
> [INFO] DistancePerPulse = 0.282
> [INFO] deltaYaw / actualRot = 0.7961783439490445

可以看出，第三组数据的IMU朝向角标定明显有些问题，这是因为第三组中的数据中发生了`左右横跳`（比如在溢出的边缘先向左转一下再马上向右转），现有的程序并不能很好地处理这个情况。

但是我现在才发现，所以就先不修了（x

## 附录

完整的代码：

```python
#author: wr786

try:   
    agentID = int(input())
    if agentID not in (1, 3, 4, 7):
        print("[ERROR] Please input 1, 3, 4 or 7!")
        exit()
except:
    print("[ERROR] Please input 1, 3, 4 or 7!")
    exit()

filefolder = f'mini{agentID}'

# dis.odom:小车直行一定距离产生的数据     注意： mini1、mini3、mini4直行1.0319米，mini7直行1.128米
# rot.odom:小车原地旋转两圈（720度）产生的数据
actualDist = {1: 1.0319, 3: 1.0319, 4: 1.0319, 7: 1.128}
actualRot = 6.28    # rad
maxPulse = 30000

# 标定编码器，DistancePerPulse与IMU
with open(f'./{filefolder}/dis.odom') as f:
    datas = f.readlines()
    pulses = [float(line[5]) for line in datas]
    accPulse = 0
    lastPulse = 0
    for pulse in pulses:
        accPulse += pulse - lastPulse
        if abs(pulse - lastPulse) > maxPulse / 2:   # 处理溢出
            accPulse += 300
        lastPulse = pulse
    print(f"[INFO] DistancePerPulse = {actualDist[agentID] / accPulse}")

# 标定yaw变化量/真值
with open(f'./{filefolder}/rot.odom') as f:
    datas = f.readlines()
    yaws = [float(line[3]) for line in datas]
    # 如果突变大于6，就可以认为是溢出
    deltaYaw = 0
    lastYaw = 0
    for yaw in yaws:
        if abs(yaw - lastYaw) > 6:
            deltaYaw += min(6.28 - abs(yaw) + abs(lastYaw), 6.28 + abs(yaw) - abs(lastYaw) )
        else:
            deltaYaw += abs(yaw - lastYaw)
        lastYaw = yaw
    print(f"[INFO] deltaYaw / actualRot = {deltaYaw / actualRot}")
```

