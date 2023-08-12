#ifndef STATE_H
#define STATE_H


#include<stdio.h>
#include<stdlib.h>

// STATE DEFINITION
#define STATE_DEF(state_func)  void state_func ()
#define STATE(state_func)      state_func


//STATE CONNECTIONS
void US_SEND_DIS(int distance);
void DC_MOTOR(int speed);


#endif