#include "DC.h"

int DC_speed;

void DC_MOTOR(int speed)
{
    DC_speed = speed;
    printf("CA---------speed = %d------->DC\n", DC_speed);
    DC_STATE =DC_BUSY;

}

STATE_DEF(DC_INIT)
{
    //init DC 
    printf("DC init");
}
STATE_DEF(DC_IDLE)
{
    //set pwm to last speed detected
    printf("DC IDLE speed = %d\n", DC_speed);
}

STATE_DEF(DC_BUSY)
{
    //set pwm to  speed detected
    DC_STATE = DC_IDLE;
    printf("DC BUSY speed = %d\n", DC_speed);

}