#ifndef DC_H
#define DC_H

#include "state.h"


//API functions
STATE_DEF(DC_INIT);
STATE_DEF(DC_IDLE);
STATE_DEF(DC_BUSY);

//global state
void (*DC_STATE)();




#endif