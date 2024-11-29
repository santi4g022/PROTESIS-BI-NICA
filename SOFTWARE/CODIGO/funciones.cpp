#include "funciones.h"
#include <Arduino.h>

void pines(){
    pinMode(PINSENAL, INPUT);
    pinMode(PINBTN, INPUT_PULLUP);
    servomotor.attach(SERVOPIN);
}

void esperaboton(){
    bool BOTON_PRESIONADO = digitalRead(PINBTN);
}

void lecturaEMG(){
    int valorAct = analogRead(EMG_PIN);
    if(valorAct>UMBRAL){
        actuador = true;
    }else{
        actuador = false;
    }
}

void escrituraServo(){
    if (actuador){
        servomotor.write(POSMAX);
    }else{
        servomotor.write(POSMIN);
    }
}