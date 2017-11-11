#include "Actions.h"

void foward(float _speed,int setPoint, bool isBrake){

  // Motor m1 --> trás esquerda
  // Motor m2 --> frente esquerda
  // Motor m3 --> trás direita
  // Motor m4 --> frente direita
  // waitDegrees(QEI &enc, Motor &motor,float speed = 0.5, int setPoint = 360, bool isBrake = true)

    _expectedRPS = (MOTOR_RPM/60.0)*abs(_speed);
    setPointInRotarion = setPoint/360.0;
    timeOut = (setPointInRotarion/_expectedRPS) * (1.0 + _tolerance);

    _localTime.start();

    encA.reset();
    encB.reset();
    encC.reset();
    encD.reset();

    m1.speed(_speed);
    m2.speed(_speed);
    m3.speed(_speed);
    m4.speed(_speed);

    while(!(m1_finish||m3_finish) && !(m2_finish||m4_finish)){ //_degrees<setPoint
      // _pulses  = enc.getPulses();
      _pulses_m1 = encA.getPulses();
      _pulses_m2 = encB.getPulses();
      _pulses_m3 = encC.getPulses();
      _pulses_m4 = encD.getPulses();

      // _degrees = (_pulses /(.5*COUNTS_PER_REV))*360;
      _degrees_m1 = (_pulses_m1/(.5*COUNTS_PER_REV))*360;
      _degrees_m2 = (_pulses_m2/(.5*COUNTS_PER_REV))*360;
      _degrees_m3 = (_pulses_m3/(.5*COUNTS_PER_REV))*360;
      _degrees_m4 = (_pulses_m4/(.5*COUNTS_PER_REV))*360;

      // _degrees = abs(_degrees);
      _degrees_m1 = abs(_degrees_m1);
      _degrees_m2 = abs(_degrees_m2);
      _degrees_m3 = abs(_degrees_m3);
      _degrees_m4 = abs(_degrees_m4);

      // (_degrees<setPoint)? : ;
      (_degrees_m1>=setPoint)?m1_finish = !m1_finish : m1_finish = m1_finish;
      (_degrees_m2>=setPoint)?m2_finish = !m2_finish : m2_finish = m2_finish;
      (_degrees_m3>=setPoint)?m3_finish = !m3_finish : m3_finish = m3_finish;
      (_degrees_m4>=setPoint)?m4_finish = !m4_finish : m4_finish = m4_finish;

      // pc.printf("\nDegrees: %d", _degrees);
      // pc.printf("\nTimeOUT: %.3f",timeOut );
      //pc.printf("\n Pulses : %f", ((setPoint*_tolerance)));

       if(_localTime >timeOut){
         break;
       }
      }

    if(isBrake){
      m1.brake();
      m2.brake();
      m3.brake();
      m4.brake();
    }else{
      m1.coast();
      m2.coast();
      m3.coast();
      m4.coast();
    }

    _localTime.stop();
    _localTime.reset();

    // return(true);


}
