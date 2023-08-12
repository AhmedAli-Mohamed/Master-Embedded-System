#include "US.h"
extern void (*US_STATE)();


int get_rand (int l, int r , int count)
{
    int i;
    for(i=0; i<=count; i++)
    {
        int rand_val = (rand() % (r-l+1)) + l;
         return rand_val;
    }
   
}

STATE_DEF(US_INIT)
{
    //init US sensor
    printf("US_INIT\n");

}

STATE_DEF(US_BUSY)
{
int distance = get_rand(45,55,1);
US_SEND_DIS(distance);
US_STATE =STATE(US_BUSY);

}