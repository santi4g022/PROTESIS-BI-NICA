typedef enum{
    IDDLE,
    LFAEMG,;
    ADCeInterpretacion;
    Servo;
}fsm;

fsm maquina=IDDLE;

int variable=valor;

void setup(){
    pines();
}

void loop(){
    switch(maquina){
        case IDDLE:
            esperaboton();
            if(BOTON_PRESIONADO){
                maquina=REMG;
                break;
            }
        case LFAEMG:
            esperaboton();
            if(BOTON_PRESIONADO==false){
                delay(DELAY);
                maquina=ADCeInterpretacion;
                break;
            }else{
                maquina=IDDLE;
                break;
            }
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