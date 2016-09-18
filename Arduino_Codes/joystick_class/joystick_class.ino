#define USE_USBCON
#include <ros.h>
#include <ArduinoHardware.h>
#include <std_msgs/Float64MultiArray.h>
#include <std_msgs/Float64.h>
#include "BMSerial.h"
#include "RoboClaw.h"

//Roboclaw Address
#define address1 0x80
#define address2 0x81

//Setup communications with roboclaw. Use pins 10 and 11 with 10ms timeout
RoboClaw roboclaw1(19,18,10000);
RoboClaw roboclaw2(19,18,10000);

int Rm = 2;
int Lm = 5;

class Rover {

private:
  float targetAngle1;
  float targetAngle2;
  float targetAngle3;
  float targetAngle4;
  float motorspeed;
  int motorleftdir;
  int motorrightdir;
  ros::NodeHandle nh;
  ros::Subscriber<std_msgs::Float64MultiArray> mob_sub("/rover/ard_directives", Rover::mobCallback, 100);;
  std_msgs::Float64 feedback_msg;
  ros::Publisher fb_pub;

public:
  Rover() {
    nh.initMode();
    nh.subscribe(mob_sub);
    fb_pub = ros::Publisher("/rover/ard_feedback", &feedback_msg);
    nh.publish(fb_pub);
    targetAngle1 = 0;
    targetAngle2 = 0;
    targetAngle3 = 0;
    targetAngle4 = 0;
    motorspeed = 0;
    motorleftdir = 0;
    motorrightdir = 0;
  }

  void mobCallback() {

  }
};

void setup() {
  pinMode(2, OUTPUT);
  pinMode(22, OUTPUT);
  pinMode(23, OUTPUT);

  pinMode(5, OUTPUT);
  pinMode(28, OUTPUT);
  pinMode(29, OUTPUT);

  roboclaw1.begin(9600);
  roboclaw2.begin(9600);
  
  Rover r;
}

void loop() {
}

