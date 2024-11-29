#include "funciones.h"
#include <Arduino.h>

void pines(){
    pinMode(PINSENAL, INPUT);
    pinMode(PINBTN, INPUT_PULLUP);
    pinMode(SERVOPIN, OUTPUT);
}

void esperaboton(){
    bool BOTON_PRESIONADO = digitalRead(PINBTN);
}

void lectura(){
    if(PINSENAL.analogRead()>UMBRAL){
        servomotor.write(100);
    }else if(PINSENAL.analogRead()==UMBRAL){
        servomotor.write(0);
    }
}