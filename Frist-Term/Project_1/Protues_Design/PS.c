#include"PS.h"

int pressure_level=0;

void (*PS_STATE)();

void PS_init()
{
    GPIO_INITIALIZATION();
    
}

void PS_READ()
{
    pressure_level = getPressureVal();
    
    PS_SEND(pressure_level);
     Delay(5000);
     PS_STATE = PS_READ ;
}