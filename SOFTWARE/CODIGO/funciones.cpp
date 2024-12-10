#include "funciones.h"
#include <Arduino.h>

//DECLARACIÓN DE PINES
void pines(){
    attachInterrupt(digitalPinToInterrupt(PINBTN),onOffIddle(),FALLING);
    pinMode(PINSENAL, INPUT);
    pinMode(PINBTN, INPUT_PULLUP);
    servomotor.attach(SERVOPIN);
}

//CAMBIA ESTADO A IDDLE
void onOffIddle(){
    if (millis() - lasttime > debounceDelay) {
    if (maquina==IDDLE){
        maquina = LFAEMG;
    }else{
        maquina = IDDLE;  
    }
    lasttime = millis();
  }
  break;
}

//LEE Y ADMITE LA SEÑAL SI ES EFECTIVA
void lecturaEMG(bool lecEfectiva){
    valorAct = analogRead(PINSENAL);
    if(valorAct>UMBRAL){
        lecEfectiva = true;
        return;
    }else{
        lecEfectiva = false;
        return;
    } 
}

//MAPEA LA SEÑAL Y LA CONVIERTE EN GRADOS
void escrituraServo(){
    grados = map(valorAct,0,1023,POSMIN,POSMAX);
    servomotor.write(grados);
}