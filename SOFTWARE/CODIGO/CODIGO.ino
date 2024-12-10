//DECLARACIÓN DE ESTADOS
typedef enum{
    IDDLE,
    LFAEMG,
    ADCeInterpretacion,
    Servo
}fsm;

#include "funciones.h"

fsm maquina=IDDLE;

void setup(){
    pines();
}

void loop(){
    switch(maquina){
        //ESTADO DE REPOSO
        case IDDLE:
            
        //ESTADO DE LECTURA, FILTRADO Y AMPLIFICACION DE SEÑAL EMG
        case LFAEMG:
                delay(DELAY);
                maquina=ADCeInterpretacion;
                break;
        //ESTADO DE CONVERSIÓN ADC E INTERPRETACIÓN DEL CÓDIGO
        case ADCeInterpretacion:
                if(lecturaEMG()==true){
                    maquina=Servo;
                    break;
                }else{
                    maquina=LFAEMG;
                    break;
                }
        //ESTADO DE ESCRITURA AL SERVO
        case Servo:
                escrituraServo();
                maquina=REMG;
                break;
    }

}