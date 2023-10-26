#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "types.h"
#include "system.h"
#include "screen.h"
string read_string()
{
    char buff;
    string buffstr;
    uint8 i = 0;
    uint8 reading = 1;
    while (reading)
    {
        if (inportb(0x64) & 0x1)
        {
            char key;
            switch (inportb(0x60))
            {
                /*case 1:
                          print_character('(char)27, 0x0F);           Escape button
                          buffstr[i] = (char)27;
                          i++;
                          break;*/
            case 2:
                print_character('1', 0x0F);
                buffstr[i] = '1';
                i++;
                break;
            case 3:
                print_character('2', 0x0F);
                buffstr[i] = '2';
                i++;
                break;
            case 4:
                print_character('3', 0x0F);
                buffstr[i] = '3';
                i++;
                break;
            case 5:
                print_character('4', 0x0F);
                buffstr[i] = '4';
                i++;
                break;
            case 6:
                print_character('5', 0x0F);
                buffstr[i] = '5';
                i++;
                break;
            case 7:
                print_character('6', 0x0F);
                buffstr[i] = '6';
                i++;
                break;
            case 8:
                print_character('7', 0x0F);
                buffstr[i] = '7';
                i++;
                break;
            case 9:
                print_character('8', 0x0F);
                buffstr[i] = '8';
                i++;
                break;
            case 10:
                print_character('9', 0x0F);
                buffstr[i] = '9';
                i++;
                break;
            case 11:
                print_character('0', 0x0F);
                buffstr[i] = '0';
                i++;
                break;
            case 12:
                print_character('-', 0x0F);
                buffstr[i] = '-';
                i++;
                break;
            case 13:
                print_character('=', 0x0F);
                buffstr[i] = '=';
                i++;
                break;
            case 14:
                print_character('\b', 0x0F);
                i--;
                buffstr[i] = 0;
                break;
            case 15:
                print_character('\t', 0x0F); // Tab button
                buffstr[i] = '\t';
                i++;
                break;
            case 16:
                print_character('q', 0x0F);
                buffstr[i] = 'q';
                i++;
                break;
            case 17:
                print_character('w', 0x0F);
                buffstr[i] = 'w';
                i++;
                break;
            case 18:
                print_character('e', 0x0F);
                buffstr[i] = 'e';
                i++;
                break;
            case 19:
                print_character('r', 0x0F);
                buffstr[i] = 'r';
                i++;
                break;
            case 20:
                print_character('t', 0x0F);
                buffstr[i] = 't';
                i++;
                break;
            case 21:
                print_character('y', 0x0F);
                buffstr[i] = 'y';
                i++;
                break;
            case 22:
                print_character('u', 0x0F);
                buffstr[i] = 'u';
                i++;
                break;
            case 23:
                print_character('i', 0x0F);
                buffstr[i] = 'i';
                i++;
                break;
            case 24:
                print_character('o', 0x0F);
                buffstr[i] = 'o';
                i++;
                break;
            case 25:
                print_character('p', 0x0F);
                buffstr[i] = 'p';
                i++;
                break;
            case 26:
                print_character('[', 0x0F);
                buffstr[i] = '[';
                i++;
                break;
            case 27:
                print_character(']', 0x0F);
                buffstr[i] = ']';
                i++;
                break;
            case 28:
                // print_character('\n', 0x0F);
                // buffstr[i] = '\n';
                i++;
                reading = 0;
                break;
                /*  case 29:
                          print_character('q', 0x0F);           Left Control
                          buffstr[i] = 'q';
                          i++;
                          break;*/
            case 30:
                print_character('a', 0x0F);
                buffstr[i] = 'a';
                i++;
                break;
            case 31:
                print_character('s', 0x0F);
                buffstr[i] = 's';
                i++;
                break;
            case 32:
                print_character('d', 0x0F);
                buffstr[i] = 'd';
                i++;
                break;
            case 33:
                print_character('f', 0x0F);
                buffstr[i] = 'f';
                i++;
                break;
            case 34:
                print_character('g', 0x0F);
                buffstr[i] = 'g';
                i++;
                break;
            case 35:
                print_character('h', 0x0F);
                buffstr[i] = 'h';
                i++;
                break;
            case 36:
                print_character('j', 0x0F);
                buffstr[i] = 'j';
                i++;
                break;
            case 37:
                print_character('k', 0x0F);
                buffstr[i] = 'k';
                i++;
                break;
            case 38:
                print_character('l', 0x0F);
                buffstr[i] = 'l';
                i++;
                break;
            case 39:
                print_character(';', 0x0F);
                buffstr[i] = ';';
                i++;
                break;
            case 40:
                print_character((char)44, 0x0F); //   Single quote (')
                buffstr[i] = (char)44;
                i++;
                break;
            case 41:
                print_character((char)44, 0x0F); // Back tick (`)
                buffstr[i] = (char)44;
                i++;
                break;
                /* case 42:                                 Left shift
                           print_character('q', 0x0F);
                           buffstr[i] = 'q';
                           i++;
                           break;
                   case 43:                                 \ (< for somekeyboards)
                           print_character((char)92, 0x0F);
                           buffstr[i] = 'q';
                           i++;
                           break;*/
            case 44:
                print_character('z', 0x0F);
                buffstr[i] = 'z';
                i++;
                break;
            case 45:
                print_character('x', 0x0F);
                buffstr[i] = 'x';
                i++;
                break;
            case 46:
                print_character('c', 0x0F);
                buffstr[i] = 'c';
                i++;
                break;
            case 47:
                print_character('v', 0x0F);
                buffstr[i] = 'v';
                i++;
                break;
            case 48:
                print_character('b', 0x0F);
                buffstr[i] = 'b';
                i++;
                break;
            case 49:
                print_character('n', 0x0F);
                buffstr[i] = 'n';
                i++;
                break;
            case 50:
                print_character('m', 0x0F);
                buffstr[i] = 'm';
                i++;
                break;
            case 51:
                print_character(',', 0x0F);
                buffstr[i] = ',';
                i++;
                break;
            case 52:
                print_character('.', 0x0F);
                buffstr[i] = '.';
                i++;
                break;
            case 53:
                print_character('/', 0x0F);
                buffstr[i] = '/';
                i++;
                break;
            case 54:
                print_character('.', 0x0F);
                buffstr[i] = '.';
                i++;
                break;
            case 55:
                print_character('/', 0x0F);
                buffstr[i] = '/';
                i++;
                break;
                /*case 56:
                          print_character(' ', 0x0F);           Right shift
                          buffstr[i] = ' ';
                          i++;
                          break;*/
            case 57:
                print_character(' ', 0x0F);
                buffstr[i] = ' ';
                i++;
                break;
            }
        }
    }
    buffstr[i] = 0;
    return buffstr;
}

// char bind_scan_code_to_char(uint8 scan_code)
// {

//     return
// }

#endif // KEYBOARD_H