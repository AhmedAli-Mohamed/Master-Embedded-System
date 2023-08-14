#include"LED.h"


void LED_Init()
{
    void GPIO_INITIALIZATION ();

}

void LED_ON(void)
{
    Set_Alarm_actuator(0);
}

void LED_OFF(void)
{
    Set_Alarm_actuator(1);
}