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

void lecturaEMG(bool lecEfectiva){
    valorAct = analogRead(EMG_PIN);
    if(valorAct>UMBRAL){
        lecEfectiva = true;
        return;
    }else{
        lecEfectiva = false;
        return;
    } 
}

void escrituraServo(){
    grados = map(valorAct,0,1023,POSMIN,POSMAX);
    servomotor.write(grados);
}