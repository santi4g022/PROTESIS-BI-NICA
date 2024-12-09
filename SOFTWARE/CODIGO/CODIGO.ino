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
            esperaboton();
            if(BOTON_PRESIONADO){
                maquina= LFAEMG;
                break;
            }
        //ESTADO DE LECTURA, FILTRADO Y AMPLIFICACION DE SEÑAL EMG
        case LFAEMG:
            esperaboton();
            if(BOTON_PRESIONADO==false){
                delay(DELAY);
                maquina=ADCeInterpretacion;
                break;
            }else{
                maquina=IDDLE ;
                break;
            }
        //ESTADO DE CONVERSIÓN ADC E INTERPRETACIÓN DEL CÓDIGO
        case ADCeInterpretacion:
            esperaboton();
            if(BOTON_PRESIONADO==false){
                if(lecturaEMG()==true){
                    maquina=Servo;
                    break;
                }else{
                    maquina=LFAEMG;
                    break;
                }
            }else{
                maquina=IDDLE;
                break;
            }
        //ESTADO DE ESCRITURA AL SERVO
        case Servo:
            esperaboton();
            if(BOTON_PRESIONADO==false){
                escrituraServo();
                maquina=REMG;
                break;
            }else{
                maquina=IDDLE;
                break;
            }
    }

}