#include <algorithm>
#include "PIDControler.h"
#include "ProcessorMulti_Processor_Core_Vars.h"

void PIDControler::set_ks(double kp, double ki, double kd) {
    k_p = kp;
    k_i = ki;
    k_d = kd;
}

void PIDControler::reset() {
    err_prev = 0;
    err_integrate = 0;
}

double PIDControler::step(double err) {
    err_integrate += err;
    double u_control = k_p * err + k_i * err_integrate + k_d * (err - err_prev);    // using the PID equation
    err_prev = err;
    return u_control;
}

std::pair<short, short>
calc_steer(double dis, double yaw, int laserSize, short *laserData, double laserUnit,
                 ProcessorMulti_Processor_Core_Params *params, ProcessorMulti_Processor_Core_Vars *vars) {

    short span = 3; // 180 / 3 == 60
    int leftSum = 0, rightSum = 0;
//    bool leftMono = true, rightMono = true;

    std::replace(laserData, laserData+laserSize, 0, vars->infDistance);

   // laserSize == 361

   // sum 60 degrees
   for(size_t i = 0; i <= 120; i+=2) {
       leftSum += *std::min_element(laserData + i, laserData + i + 1);
   }
   for(size_t i = 240; i <= laserSize; i += 2) {
       rightSum += *std::min_element(laserData + i, laserData + i + 1);
   }

   int sumDelta = leftSum - rightSum;
   double err = (double)sumDelta / (double)(laserSize/2 / span);
//   err = err>=0 ? sqrt(abs(err)) : -sqrt(abs(err)); // try to rm this?
   err /= 9;    // make the plot more reasonable
   err = err >= 0 ? err * err : -err * err;
//   qDebug() << err << endl;

   // notice that its all turning right
   int detectRange = vars->forwardDetectRange;
   if(*std::min_element(laserData - detectRange, laserData + detectRange + 1) != 0 && sumDelta < 0) {
       // if here is a right corner and there is a wall ahead
       err += 5;   // then turn right!
   }

   qDebug() << err << " ";

   int steer = vars->pid.step(err);
   int speed = 150; // turning should be a bit slower

   if(abs(steer) < vars->straightThreshold) {
       speed = vars->straightSpeed;
   }

   // cope with overflow
   int steerMax = 600;
   int speedMax = 180;
   steer = std::max(steer, -steerMax);
   steer = std::min(steer, steerMax);
   speed = std::max(speed, -speedMax);
   speed = std::min(speed, speedMax);

//   int filt = vars->filterRange * 2;
   short* laserMid = laserData + (laserSize - 1) / 2;
   int safeRange = vars->safeAngle * 2;

   if(vars->reverse && vars->prev_odom - dis > vars->backwardDistance / laserUnit) {
       vars->reverse = false;
   }

   if((*std::min_element(laserMid - safeRange, laserMid + safeRange + 1) < vars->safeDistance) || vars->reverse) {
       qDebug() << *std::min_element(laserMid - safeRange, laserMid + safeRange + 1) << " ";
       speed = -100;
       steer = vars->baseSteer;
       if(!vars->reverse) {
           vars->reverse = true;
           vars->prev_odom = dis;
       }
   }


   return {speed, steer};
}
