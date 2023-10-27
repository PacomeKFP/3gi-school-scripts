#include "header.h"
int kmain()
{
       clear_screen();
       print("Hello guys, Welcome on IKnowOS\nPlease enter a command\n", false);
       while (1)
       {
              print("\n IKnowOS > ", false);
              string command = read_string();
              if (str_equal(command, "cmd"))
                     print("\nYou are already in a terminal\n", false);
              if (str_equal(command, "cls"))
                     clear_screen();
              else
                     print("\nBad Command", true);
       }
}
