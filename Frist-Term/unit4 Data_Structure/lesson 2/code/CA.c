#include"CA.h"

extern void (*CA_STATE)();
int CA_distance;
int CA_speed;
int CA_threshold=50;

void US_SEND_DIS(int distance)
{
    CA_distance = distance;
    CA_distance <= CA_threshold ? (CA_STATE =CA_WAITING) : (CA_STATE = CA_DRIVING);
    printf("US --------distance=%d---->CA\n",CA_distance);
}

STATE_DEF(CA_WAITING)
{
    //set speed to zero and send it to motor driver
    CA_speed=0;
    DC_MOTOR(CA_speed);
}

STATE_DEF(CA_DRIVING)
{
     //set speed to 30 and send it to motor driver
    CA_speed=30;
    DC_MOTOR(CA_speed);
}