#include "MF_Shield.h"

// main() runs in its own thread in the OS
int main()
{
    DigitalIn Taster[3] = { PA_1, PA_4,	PB_0 };
    MF_Shield Shield;
    int process = 0;

    while (true) {

        switch(process){
            case 1:
                Shield.sosBlinken();
                break;
            case 2:
                Shield.zaehleBis15();
                break;
            case 3:
                if(Taster[0]==0) Shield.zaehlerMitTaster(Taster[0]);
                else if(Taster[1]) Shield.zaehlerMitTaster(Taster[1]);
                Shield.waitFor();
                break;
        }

    }
};