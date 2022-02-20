#ifndef MF_SHIELD_H
#define MF_SHIELD_H

#include "mbed.h"

class MF_Shield{

    // Alle LEDs in ein Array
    DigitalOut LED[4] = {
        PA_5,   // LED 1
        PA_6,   // LED 2
        PA_7,   // LED 3
        PB_6    // LED 4
    };
    
    DigitalIn Taster[3] = {
        PA_1,   // Taster 1
	    PA_4,	// Taster 2
    	PB_0    // Taster 3
    };

    int LedZustands[16][4] = {
        { 0 , 0 , 0 , 0 } ,
        { 0 , 0 , 0 , 1 } ,
        { 0 , 0 , 1 , 0 } ,
        { 0 , 0 , 1 , 1 } ,
        { 0 , 1 , 0 , 0 } ,
        { 0 , 1 , 0 , 1 } ,
        { 0 , 1 , 1 , 0 } ,
        { 0 , 1 , 1 , 1 } ,
        { 1 , 0 , 0 , 0 } ,
        { 1 , 0 , 0 , 1 } ,
        { 1 , 0 , 1 , 0 } ,
        { 1 , 0 , 1 , 1 } ,
        { 1 , 1 , 0 , 0 } ,
        { 1 , 1 , 0 , 1 } ,
        { 1 , 1 , 1 , 0 } ,
        { 1 , 1 , 1 , 1 } 
    };
    
    // Zeit zwischen takt
    int taktZeit = 400; // ThisThread::sleep_for(std::chrono::milliseconds(taktZeit));

    public:
        // Standard Konstruktor ohne Parameters
        MF_Shield(){};

        // Konstruktor mit taktZeit parameter als int
        MF_Shield(int taktZeit){
            this->taktZeit = taktZeit;
        };

        // Warte für die gegebener Zeit oder Standard Takt
        void waitFor(int taktZeitInMs = -1);

        // SOS Methode
        void sosBlinken();
        
        // mithilfe der LEDs, 0 bis 15 zählen
        void zaehleBis15();

        // zeigt der gegebener Zahl zwischen 0 bis 15, mithilfe von 4 LEDs
        int zeigeZahlOnLEDs(int zahl = 0);

        // liest der aktuelle Zahl anhand der Zustand von LEDs
        int leseZahlAusLEDs();

        // Steuerung von Zahl durch den Taster, wenn kein Taster ist gegeben als Parameter, Taster 1 ist verwendet
        void zaehlerMitTaster(DigitalIn Taste = PA_1);

};

#endif