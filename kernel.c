#include "include/screen.h"

kmain()
{
       clear_screen();
       print("Hello guys, Welcome on IKnowOS\nPleasea enter a command\n", false);
       while (1)
       {
              print("IKnowOS> ", true);
              string command = read_string();
              if (str_equal(command, "cmd"))
                     print("You are already in a terminal", false);
              
       }
}
