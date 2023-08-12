#ifndef CA_H
#define CA_H

#include"state.h"

//API functions
STATE_DEF(CA_WAITING);
STATE_DEF(CA_DRIVING);

//global state
void (*CA_STATE)();

#endif
