#include "header.h"
int main(int argc, char const *argv[])
{
    int number[] = {1, 2, 3};
    int initial_len = 3;
    int *final = (int *)malloc(sizeof(int));
    int final_len;
    int initial_base = 15;
    int final_base = 2;
    printf("%d", 15%4);
    // convert_to_base(number, initial_len, initial_base, final, &final_len, final_base);
    // display_list_content(final, final_len);
    return 0;
}
