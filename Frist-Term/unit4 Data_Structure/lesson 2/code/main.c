#include "US.h"
#include "DC.h"
#include"CA.h"

void main()
{
    //init ALL Drivers
    STATE(US_INIT);
    STATE(DC_INIT);

    //select first state
    US_STATE = US_BUSY;
    CA_STATE = CA_WAITING;
    DC_STATE = DC_BUSY;
    while (1)
    {
        US_STATE();
        CA_STATE();
        DC_STATE();
    }
    
}