/*
Title: MotorSet.cpp
Author: Christine Cabero, Ben Pauka, Matthew VonWahlde, Cameron Zheng
Date Created: 11/12/22
Date Modified: 11/12/22
Description: Function file for MotorSet

*/

#include "MotorSet.h"

/*
Function: MotorSet()
Input: N/A
Output: N/A
Description: Constructor for MotorSet, initializes variables
*/
MotorSet::MotorSet(){
    // Setting the total number of current motors to 0
    numMotors = 0;
}

/*
Function: ~MotorSet()
Input: N/A
Output: N/A
Description: Destructor for MotorSet, deletes all variables and objects used
*/
MotorSet::~MotorSet(){
    // Deleting all MotorController instances that each element of set is pointing to
    for(int i = 0; i < numMotors; i++){
        delete[] set[i];
    }

    // Deleting the set and numMotors
    delete[] set;
    delete numMotors;
}

/*
Function: addMotor()
Input: pin 1, pin 2, enable pin, and what side the motor is on (left = 'l', right = 'r')
Output: N/A
Description: Adds an instance of MotorController to the set array
*/
void MotorSet::addMotor(int pin1, int pin2, int pinEn, int pwmChannel, char side{
    // If the max number of motors has not been reached
    if(numMotors < maxMotors){
        // increment the number of motors
        numMotors++;

        // add a new motor to the set
        set[numMotors - 1] = new MotorController(pin1, pin2, pinEn, pwmChannel, side);
    }
}

/*
Function: driveForwards()
Input: A speed to go forwards
Output: Changes all motors to the value
Description: Spins the wheels forwards
*/
void MotorSet::driveForwards(double speed){
    for (int i; i < numMotors; i++) {
        set[i]->motorForwards(speed);
    }
}

/*
Function: driveBackwards()
Input: A speed to go backwards
Output: Changes all motors to the value
Description:
*/
void MotorSet::driveBackwards(double speed){
    for (int i; i < numMotors; i++) {
        set[i]->motorBackwards(speed);
    }
}

/*
Function: stop()
Input: N/A
Output: N/A
Description: Stops motors
*/
void MotorSet::stop(){
    for (int i; i < numMotors; i++) {
        set[i]->motorStop();
    }
}

/*
Function: spinLeft()
Input: Turning speed
Output: Rover spins left
Description: Spins left
*/
void MotorSet::spinLeft(double speed)){
    for (int i; i < numMotors; i++) {
        if (set[i]->getSide() == 'l') {
            set[i]->motorBackwards(speed);
        } else {
            set[i]->motorForwards(speed);
        }
    }
}

/*
Function: spinRight()
Input: Turning speed
Output: Rover spins right
Description: Spins right
*/
void MotorSet::spinRight(double speed){
    for (int i; i < numMotors; i++) {
        if (set[i]->getSide() == 'r') {
            set[i]->motorBackwards(speed);
        } else {
            set[i]->motorForwards(speed);
        }
    }
}