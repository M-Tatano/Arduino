#include "CurieIMU.h"

int accX = 0, accY = 0, accZ = 0;
int gyrX = 0, gyrY = 0, gyrZ = 0;
double angX = 0.0, angY = 0.0, angZ = 0.0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  CurieIMU.begin();
  CurieIMU.setAccelerometerRange(2);
  CurieIMU.setGyroRange(250);
}

void loop() {
  // put your main code here, to run repeatedly:
  CurieIMU.readMotionSensor(accX, accY, accZ, gyrX, gyrY, gyrZ);
  angX = atan((double)accX/sqrt(pow((double)accY,2) + pow((double)accZ,2)))*180.0/PI;
  angY = atan((double)accY/sqrt(pow((double)accX,2) + pow((double)accZ,2)))*180.0/PI;
  angZ = atan((double)accZ/sqrt(pow((double)accX,2) + pow((double)accY,2)))*180.0/PI;
  char outs[32];
  sprintf(outs, "angX = %f, angY = %f, angZ = %f\n", angX, angY, angZ);
  Serial.print(outs);
  delay(1000);
}
