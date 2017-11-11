#ifndef Actions_h
#include "_config.h"

class Actions{
void foward(float _speed,int setPoint, bool isBrake);
public:
    int _pulses_m1 = 0;
    int _pulses_m2 = 0;
    int _pulses_m3 = 0;
    int _pulses_m4 = 0;

    int _degrees_m1 = 0;
    int _degrees_m2 = 0;
    int _degrees_m3 = 0;
    int _degrees_m4 = 0;

    int _tolerance = 0.8;
    float _expectedRPS = 0.0;
    float setPointInRotarion = 0.0;
    float timeOut = 0.0;
    Timer _localTime;

    bool m1_finish = false;
    bool m2_finish = false;
    bool m3_finish = false;
    bool m4_finish = false;
};
#endif
