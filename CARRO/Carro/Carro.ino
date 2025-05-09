#include "MotorCC.h"
#include "SensorInfravermelho.h"
MotorCC motorA(4,5,3);
MotorCC motorB(9,10,11);
SensorInfravermelho sensorA(2);
SensorInfravermelho sensorB(12);
SensorInfravermelho sensorC(7);
void setup() {
    Serial.begin(9600);

}

void loop() {

 
  if(!sensorA.isReflect() && sensorB.isReflect()){
      while(true)
      {
      motorA.girarHorario(150);
      motorB.girarAntiHorario(60);
      if(sensorC.isReflect() && !sensorB.isReflect()){
        break;
      }
      }
  }else if(sensorA.isReflect() && !sensorB.isReflect()){
    while(true){
      motorA.girarAntiHorario(60);
      motorB.girarHorario(150);
       if(sensorC.isReflect() && !sensorA.isReflect()){
        break;
      }
    }
     }else if(!sensorA.isReflect() && !sensorB.isReflect() && sensorC.isReflect()){
    motorA.girarHorario(150);
    motorB.girarHorario(150);
  }
 
  /*Serial.println(sensorA.isReflect());
   Serial.println(sensorB.isReflect());
    Serial.println("-----------");
    delay(1000);
    */
}
