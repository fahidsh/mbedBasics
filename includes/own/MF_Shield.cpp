#include "MF_Shield.h"

void MF_Shield::waitFor(int taktZeitInMs){

    if(taktZeitInMs == -1){
        taktZeitInMs = taktZeit;
    }

    ThisThread::sleep_for(std::chrono::milliseconds(taktZeitInMs));
}

// SOS Methode
void MF_Shield::sosBlinken(){
    /*
    SOS SIGNAL PATTERN
    ▄ ▄ ▄ ▄▄▄ ▄▄▄ ▄▄▄ ▄ ▄ ▄ 
    010101011101110111010101
    */
    int sos[24] = {0,1,0,1,0,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,0,1,0,1};

    for(int i = 0; i < sizeof(sos); i++){
        // Alle vie LEDs sollen SOS Signal geben
        // LEDs sind an bei Falsch und aus bei Wahr, deher muss man die Wert von SOS Array negieren
        LED[0] = LED[1] = LED[2] = LED[3] = !sos[i];

        waitFor(taktZeit);
    }

}

void MF_Shield::zaehleBis15(){
    
    for(int i=0; i < 16; i++){

        zeigeZahlOnLEDs(i);

        waitFor(taktZeit);
    }
}

int MF_Shield::zeigeZahlOnLEDs(int zahl){

    // wenn der gegebener Zahl großer als 15 ist
    if(zahl > 15){

        // subtractiere 15 bis der Zahl nicht mehr großer als 15 ist (Remainder)
        zahl = zahl % 15;
    }

    for(int i=0; i < 4; i++){
        
        LED[i] = ! LedZustands[zahl][i];
    }

    // gebe der Zahl zurück, normal soll es immer der gegebener Zahl sein
    // es kann aber auch anders sein, wenn der gegebener Zahl großer als 15 war
    return zahl;
}

int MF_Shield::leseZahlAusLEDs(){

    int geleseneZahle = -1;
    int ledZahl[4];
    
    for(int i=0; i < 4; i++){
        
        ledZahl[i] = ! LED[i];
    }

    for(int i=0; i < 15; i++){

        if (std::equal(std::begin(ledZahl), std::end(ledZahl), std::begin(LedZustands[i]))){
            geleseneZahle = i;
            i = 15; // Zahl ist gefunden, beende die Schleife
        }
    }

    return geleseneZahle;
}

void MF_Shield::zaehlerMitTaster(DigitalIn Taste){

    // Anfangszahl als 0
    int zahl = leseZahlAusLEDs();
    int maxZahle = 15;

    if(Taste == Taster[0]){
        zahl += 1;
    }else if (Taste == Taster[1]) {
        zahl -= 1;
    }

    if(zahl > maxZahle){
        zahl = 0;
    }else if (zahl < 0) {
        zahl = maxZahle;
    }

    // Zahl an die LEDs anzeigen
    zeigeZahlOnLEDs(zahl);
}
