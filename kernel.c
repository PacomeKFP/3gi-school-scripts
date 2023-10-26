#include "include/screen.h"
#include "include/keyboard.h"

kmain()
{
       clear_screen();
       print("Hello guys, Welcome on IKnowOS\nPlease enter a command\n", false);
       while (1)
       {
              print("IKnowOS> ", true);
              string command = read_string();
              if (str_equal(command, "cmd"))
                     print("You are already in a terminal\n", false);
              if (str_equal(command, "cls"))
                     clear_screen();

              if (str_equal(command, "exit"))
                     exit();
              else
                     print("Bad Command\n", true);
       }
}
