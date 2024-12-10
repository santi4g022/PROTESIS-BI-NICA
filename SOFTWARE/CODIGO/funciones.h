#ifndef FUNCIONES_H
#define FUNCIONES_H

//DECLARACION DE PMACROS
#include <Servo.h>
#define PINSENAL    A0
#define PINBTN      2
#define SERVOPIN    3
#define BAUDRATE    9600
#define TIMEREAD    100
#define UMBRAL      100
#define POSMAX      170
#define POSMIN      0
#define DELAY       250

//VARIABLE DEL SERVO
Servo servomotor;

//CABECERAS DE FUNCIONES
void pines();
void lecturaEMG();
void escrituraServo();
void onOffIddle();

//VARIABLES
int valorAct;
int grados;
volatile unsigned long lasttime = 0;
volatile unsigned long debounceDelay = 80;

#endif
