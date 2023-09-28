#include "header.h"
int main(int argc, char const *argv[])
{
    int number[] = {12, 20, 23, 12, 2, 4, 8};
    int initial_len = sizeof(number) / sizeof(int);
    int *final = (int *)malloc(sizeof(int));
    int final_len;
    int initial_base = 25;
    int final_base = 12;
    // printf("%f", (float)15/2);
    convert_to_base(number, initial_len, initial_base, final, &final_len, final_base);
    printf("\n");
    display_list_content(final, final_len, true);
    return 0;
}
