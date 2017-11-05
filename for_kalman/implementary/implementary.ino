/*
 * This sketch assume attitude of Genuino nano by kalman filter
 */

#include "CurieIMU.h"

void setup() {
  Serial.begin(9600); // initialize Serial communication
  while (!Serial);  //wait for the serial port to open
    
    //initialize device
    Serial.println("Initializing IMU device...");
    CurieIMU.begin();
    
    // Set the gyro accelerometer range to 250 degrees/second
    CurieIMU.setGyroRange(250);
    
    // Set the accelerometerRange to 2G
    CurieIMU.setAccelerometerRange(2);
    }

void loop() {
  float gx, gy, gz;  //scaled Gyro values 
  float ax, ay, az;  //scaled accelerometer values
  const dt=0.005;
  float angleX, angleY, angleZ;
  float angleXaccel, angleYaccel, angleZaccel;

  // read gyro measurements from device, scaled to the configured range
  CurieIMU.readGyroScaled(gx, gy, gz);
  
  // calculation of angle by accelometer
  
  // read accelerometer measurements from device, scaled to the configured range
  CurieIMU.readAccelerometerScaled(ax, ay, az);

  // calculation of angle by accelometer
  angleXaccel = atan((double)ax/sqrt(pow((double)ay,2)+pow((double)az,2)));
  angleYaccel = atan((double)ay/sqrt(pow((double)ax,2)+pow((double)az,2)));
  angleZaccel = atan((double)az/sqrt(pow((double)ax,2)+pow((double)ay,2)));


  // simpified implementary filter 
  angleX = 0.95*(angleX+gx*dt)+0.05*angleXaccel;
  angleY = 0.95*(angleY+gy*dt)+0.05*angleYaccel;
  angleZ = 0.95*(angleZ+gz*dt)+0.05*angleZaccel;

//dispaly sensored values

  char outs[32];
  sprintf(outs, "angleX = %f, angleY = %f, angZ = %f\n", angleX, angleY, angleZ);  Serial.print(outs);
  delay(100);

/*Serial.print("g:\t");
  Serial.print(gx);
  Serial.print("g:\t");
  Serial.print(gy);
  Serial.print("g:\t");
  Serial.print(gz);
  Serial.println();

  Serial.print("a:\t");
  Serial.print(ax);
  Serial.print("a:\t");
  Serial.print(ay);
  Serial.print("a:\t");
  Serial.print(az);
  Serial.println();
*/
}
