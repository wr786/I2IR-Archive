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
            deltaYaw += 6.28 - abs(yaw) - abs(lastYaw)
        else:
            deltaYaw += abs(yaw - lastYaw)
        lastYaw = yaw
    print(f"[INFO] deltaYaw / actualRot = {deltaYaw / actualRot}")