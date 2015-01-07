#include "robot_logic.h"

int global_speed = 0;

int abs(int v)
{
  return v * ( (v<0) * (-1) + (v>0));
  // simpler: v * ((v>0) - (v<0))   thanks Jens
}

void drive(int speed){  //speed is an integer between 0 en 100
    
    int uspeed = abs(speed);
    int sign = (speed < 0) *(-1);
    if(uspeed <= 0){
        global_speed = 0;
    }else{
        if(uspeed >= 100){
            global_speed = sign*1023;
        }else{
            global_speed = sign*(int)(uspeed/100 * 1023);
        }
    }
    setSpeedMotor1(global_speed);
    setSpeedMotor2(global_speed);
}


void turn(int turnspeed){ //turn according to a rotation 0 tot 100
    float ft = turnspeed/100;
    int newspeedMotor1 = global_speed;
    int newspeedMotor2 = global_speed;
    if(turnspeed >= 0){
        newspeedMotor1 = (int) (global_speed*(1+ft));
        newspeedMotor2 = (int) (global_speed*(1-ft));
    }else{
        newspeedMotor1 = (int) (global_speed*(1-ft));
        newspeedMotor2 = (int) (global_speed*(1+ft));
    }
    setSpeedMotor1(newspeedMotor1);
    setSpeedMotor2(newspeedMotor2);
}

void stop(){
    drive(0);
}

void lightsOn(){
    setHeadlights(LD1,TRUE);
    setHeadlights(LD2,TRUE);
}