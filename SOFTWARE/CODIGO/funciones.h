#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <Servo.h>
#define PINSENAL A0
#define PINBTN 3
#define SERVOPIN 9
#define BAUDRATE 9600
#define TIMEREAD 100
#define UMBRAL 100
#define POSMAX 170
#define POSMIN 0
#define DELAY 250

Servo servomotor;

void pines();
void esperaboton();
void lecturaEMG();
void escrituraServo()

bool actuador;
