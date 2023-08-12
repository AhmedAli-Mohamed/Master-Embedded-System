#ifndef US_H
#define US_H

#include "state.h"

//API functions
STATE_DEF(US_INIT);
STATE_DEF(US_BUSY);

//global state
void (*US_STATE)();
#endif