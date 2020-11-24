#ifndef PIDCONTROLER_H
#define PIDCONTROLER_H

class ProcessorMulti_Processor_Core_Params;
class ProcessorMulti_Processor_Core_Vars;   // DECLARE

class PIDControler {
public:
    void set_ks(double kp, double ki, double kd);
    void reset();
    double step(double err);

private:
    double err_prev;
    double err_integrate;
    double k_p, k_i, k_d;
};

std::pair<short, short> calc_steer(double dis, double yaw, int laserSize, short* laserData, double laserUnit,
                ProcessorMulti_Processor_Core_Params* params,
                ProcessorMulti_Processor_Core_Vars* vars);

#endif // PIDCONTROLER_H
