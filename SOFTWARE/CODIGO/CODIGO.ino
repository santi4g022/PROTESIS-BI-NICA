typedef enum{
    IDDLE,
    REMG,
    FilAmpEMG;
    ADC;
    Interpretacion;
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
        case REMG:
            esperaboton();
            if(BOTON_PRESIONADO==false){
                
                maquina=FilAmpEMG;
                break;
            }else{
                maquina=IDDLE;
                break;
            }
        case FilAmpEMG:
            esperaboton();
            if(BOTON_PRESIONADO==false){

                maquina=ADC;
                break;
            }else{
                maquina=IDDLE;
                break;
            }  
        case ADC:
            esperaboton();
            if(BOTON_PRESIONADO==false){

                maquina=Interpretacion;
                break;
            }else{
                maquina=IDDLE;
                break;
            }
        case Interpretacion:
            esperaboton();
            if(BOTON_PRESIONADO==false){
                lectura();
                maquina=Servo;
                break;
            }else{
                maquina=IDDLE;
                break;
            }
        case Servo:
            esperaboton();
            if(BOTON_PRESIONADO==false){
                delay(100);
                maquina=REMG;
                break;
            }else{
                maquina=IDDLE;
                break;
            }
    }

}