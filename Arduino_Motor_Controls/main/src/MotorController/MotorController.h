/*
Title: MotorController.h
Author: Christine Cabero, Ben Pauka, Matthew VonWahlde, Cameron Zheng
Date Created: 11/12/22
Date Modified: 2/2/23
Description: Header file for MotorController
*/

#ifndef MOTOR_CONTROLLER_H
#define MOTOR_CONTROLLER_H

//#include <Arduino.h>


/*
Class: MotorController
Input: pin 1, pin 2, enable pin, pwm channel, and the side the motor is on (left = 'l', right = 'r')
Output: N/A
Description: This class represents one motor controller on the board. MotorSet uses and instance of this class for each of its motors

*/

class MotorController{
    public:
        MotorController(int pin1, int pin2, int pinEn, int pwmChannel, char side);

        void motorForwards(float speed);
        void motorBackwards(float speed);
        //void motorMove(float speed);
        void motorStop();

        char getSide();
    private:
        int pin1;
        int pin2;
        int pinEn;
        int pwmChannel;
        char side;

        int freq = 500;
        int resolution = 8;
        int maxDutyCycle = 150;

        float returnAbs(float);
};

#endif
