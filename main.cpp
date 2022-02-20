#include "MF_Shield.h"
#include "LcdController.h"

// main() runs in its own thread in the OS
int main()
{
    DigitalIn Taster[3] = { PA_1, PA_4,	PB_0 };
    MF_Shield Shield;

    int process = 0;
    int anzahlProcess = 4;

    LcdController Lcd;

    while (true) {


        for (int i=0; i<3; i++) {
            Shield.waitFor();

            if(Taster[2] == 0){
                if(process < anzahlProcess) process++;
                else process = 0;

                i = 0;
            }
        }


        switch(process){
            case 1:
                Shield.sosBlinken();
                process = 0;
                break;
            case 2:
                Shield.zaehleBis15();
                process = 0;
                break;
            case 3:
                if(Taster[0]==0) Shield.zaehlerMitTaster(Taster[0]);
                else if(Taster[1]==0) Shield.zaehlerMitTaster(Taster[1]);
                else if (Taster[2]==0) process = 0;
                break;
            case 4:
                Lcd.messageAnzeigen("Hello World!");
                process = 0;
                break;
        }

    }
};
