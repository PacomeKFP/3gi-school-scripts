#include "header.h"

int main(int argc, char const *argv[])
{
    int number[] = {1, 0, 4};
    int initial_len = sizeof(number) / sizeof(int);
    array final = (array)malloc(sizeof(int));
    int final_len;
    int initial_base = 8;
    int final_base = 9;

    convert_to_base(number, initial_len, initial_base, final, &final_len, final_base);
    printf("\n");
    display_list_content(final, final_len, true);

    return 0;
}
