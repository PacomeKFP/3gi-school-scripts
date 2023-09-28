#include "header.h"

void convert_to_base(int *initial_number, int initial_number_len, int initial_base, int *final_number, int *final_number_len, int final_base)
{
    // Duplicate the initial number to avoid side-effects
    int *quotients = (int *)malloc(sizeof(int));
    duplicate_number(initial_number, quotients, initial_number_len);

    *final_number_len = 0;

    int remain = 0;
    int last_null = -1;
    int index = 0;
    int extended_digit_10 = 0;
    while (last_null != initial_number_len - 1)
    {
        printf("%d", index);
        display_list_content(quotients, initial_number_len);
        display_list_content(final_number, *final_number_len);
        extended_digit_10 = quotients[index] + remain * initial_base;
        while (extended_digit_10 < final_base)
        {
            quotients[index] = 0;
            last_null = index;
            index++;
            if (index == initial_number_len)
                return push_front(final_number, final_number_len, extended_digit_10);

            extended_digit_10 = extended_digit_10 * initial_base + quotients[index];
        }
        quotients[index] = extended_digit_10 / final_base; // final_base
        remain = extended_digit_10 % final_base;
        index++;
        if (index == initial_number_len)
        {
            push_front(final_number, final_number_len, remain);
            remain = 0;
            index = last_null+1;
        }
    }
}