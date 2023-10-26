#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "types.h"
#include "system.h"
#include "screen.h"

string read_string(){
    char buff;
    string buffstring;
    uint8 i = 0;
    bool is_reading = true;
    
    while (is_reading)
    {
        switch (inportb(0x60))
        {
        case :
            /* code */
            break;
        
        default:
            break;
        }
    }
    
}

#endif //KEYBOARD_H