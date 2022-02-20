
#ifndef LCD_CONTROLLER_H
#define LCD_CONTROLLER_H

#include "LCD.h"
#include <string>

class LcdController{

    lcd LcdDisplay; //Dispalyobjekt erstellen (kann auch global deklariert werden)



    public:

        LcdController(){};

        LcdController(std::string message){
            messageAnzeigen(message);
        }

        void messageAnzeigen(std::string msg = ""){
            LcdDisplay.clear(); //löscht das Display
            LcdDisplay.cursorpos(0); //plaziert den Cursor 0..15: 1.Zeile, 64..79 2.Zeile (64=0x40)
            LcdDisplay.printf("%s",msg.c_str()); //mylcd.printf(Formatstrinng,Werte); -> Ausgabe. Doku: Internet printf
        }
};

#endif
