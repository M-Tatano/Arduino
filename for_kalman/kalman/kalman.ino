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
    CurieIMU.setAccelerometerRange(250);
    }

void loop() {
  float gx, gy, gz;  //scaled Gyro values 
  float ax, ay, az;  //scaled accelerometer values
  
  // read gyro measurements from device, scaled to the configured range
  CurieIMU.readGyroScaled(gx, gy, gz);
  
  // read accelerometer measurements from device, scaled to the configured range
  CurieIMU.readAccelerometerScaled(ax, ay, az);

//dispaly sensored values

  Serial.print("g:\t");
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
  Serial.pirnt("a:\t");
  Serial.print(az);
  Serial.println();

}
