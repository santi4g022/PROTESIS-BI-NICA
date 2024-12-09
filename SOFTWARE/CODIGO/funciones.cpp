#include "funciones.h"
#include <Arduino.h>

//DECLARACIÓN DE PINES
void pines(){
    pinMode(PINSENAL, INPUT);
    pinMode(PINBTN, INPUT_PULLUP);
    servomotor.attach(SERVOPIN);
}

//ESPERA PARA EL BOTON IDDLE
void esperaboton(){
    bool BOTON_PRESIONADO = digitalRead(PINBTN);
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