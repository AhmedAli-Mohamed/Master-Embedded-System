#include"driver.h"
#include"alarm.h"

void (*ALARM_STATE)();
int threshold = 20;


void PS_SEND(int pressure_level)
{
    (pressure_level > threshold) ? (ALARM_STATE = ALARM_ON) : (ALARM_STATE = ALARM_OFF);
}

void ALARM_ON()
{
    LED_ON();
    Delay(4000);
    LED_OFF();
    ALARM_STATE = ALARM_OFF;

}
void ALARM_OFF()
{
    LED_OFF();

}