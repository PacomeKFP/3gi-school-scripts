#include "header.h"

/**
 * Converts a number from one base to another base.
 *
 * @param initial_number array  containing the digits of the initial number
 * @param initial_number_len Length of the initial number array
 * @param initial_base Base the initial number is in
 * @param final_number Output array  to contain the digits of the final converted number
 * @param final_number_len Output parameter for the length of the final number array
 * @param final_base Target base to convert the number to. \n
 *
 * This function takes a number represented in one base (initial_base) and converts it
 * to another base (final_base). It processes each digit of the initial number, divides
 * by the target base to get the converted digit, and builds up the output final number
 * array  digit-by-digit. Remainders are tracked and added to the next digit.
 */
void convert_to_base(array initial_number, int initial_number_len, int initial_base, array final_number, int *final_number_len, int final_base)
{
    /**
     * Duplication of the initial number, we will make all caculations on it
     * This will help avoiding to avoid side-effects
     */
    array quotients = (array)malloc(sizeof(int));
    duplicate_number(initial_number, quotients, initial_number_len);

    *final_number_len = 0;

    int remain = 0;            // where we will store the remain of each successive division
    int last_null = -1;        // The index of the last 0 in the quotient (going from left to right)
    int index = 0;             // The 'pointer' we will use to know the digit of the quotient which we are dividing
    int extended_digit_10 = 0; // The value of the digit of the quotient we are dividing in decimal base
    // loop to make successive divisions
    while (last_null != initial_number_len - 1)
    {
        index = last_null + 1;
        remain = 0;
        // Start a division round
        while (index != initial_number_len)
        {
            extended_digit_10 = quotients[index] + remain * initial_base;
            // ensure that the extended_digit is divisible by the final_base
            while (extended_digit_10 < final_base)
            {
                quotients[index] = 0;
                last_null = index;
                index++;
                if (index == initial_number_len)
                {
                    final_number[*final_number_len] = extended_digit_10;
                    *final_number_len++;
                    return reverse_array(final_number, *final_number_len);
                }

                extended_digit_10 = extended_digit_10 * initial_base + quotients[index];
            }

            /**After the previous while loop we are sure that:
             * - The extended digit in base 10 is equal or greather than the final_base
             * - If the initial number (in base 10) was less than the `final_base`, the result is given
             */
            quotients[index] = extended_digit_10 / final_base; // final_base
            remain = extended_digit_10 % final_base;
            index++;
        }
        final_number[*final_number_len] = extended_digit_10;
        *final_number_len++;
    }
    return reverse_array(final_number, *final_number_len);
}

void ensure_digit_greather_than_final_base() {}