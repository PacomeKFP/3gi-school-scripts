#include "header.h"

    int main(int argc, char const *argv[])
    {
        INIT_SEPARATOR(separator);

        string str = "AEF51f";
        array number = (array)malloc(sizeof(int));
        int size = 0;
        str_to_number_list(str, number, "+-*/", &size, MEDIUM_CONVERSION);
        display_list_content(number, size, true);
        printf("\nAll is good");

        return 0;
    }
