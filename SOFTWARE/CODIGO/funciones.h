#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <Servo.h>
#define PINSENAL A0
#define PINBTN 3
#define SERVOPIN 5
#define BAUDRATE 9600
#define TIMEREAD 100
#define UMBRAL 100

Servo servomotor;

void pines();
void esperaboton();
void lectura();

