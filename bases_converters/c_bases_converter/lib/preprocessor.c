#include <header.h>

/**
 * This function helps converting a string like "7-2-4-8-9" into a list of integer representing a number like { 7, 2, 4, 8, 9}
 * 
 * @param str the initial string representing the number
 * @param numbers the array of int wich will store the final result
 * @param separator The list characters that can be used to separate digits of the number represented as a string (in str)
 * @param size the integet that will store the number of digit contained in the final number after the process.
 * 
 * This function parses the initial string, extract digits (element beetwen 2 separator) and inserts it into the numbes that is considered as the results. It also increment the size of the number 
 */
void str_to_number_list(string str, array numbers, string separator, int *size)
{
    *size = 0;
    string token = strtok(str, separator);
    while (token != NULL)
    {
        numbers[*size] = atoi(token);
        printf("%d", numbers[*size]);
        token = strtok(NULL, separator);
        *size += 1;
    }
    if (*size == -1)
        *size = 0;
}

/**
 * This function helps checking if a given number is valid in particular base
 * 
 * @param initial_number The list of int that represent the intfe
*/
Bool check_number_validity(array initial_number, int number_len, int initial_base)
{
    for (int index = 0; index < number_len; index++)
    {
        if (initial_number[index] >= initial_base)
        {
            printf("[❌] Desolé le nombre que vous avez entré n'est pas valide dans cette base");
            return false;
        }
    }
    printf("[✅] Le nombre est bien valide dans la base entrée");
    return true;
}

void display_list_content(array list, int size, Bool br)
{

    printf("[");
    for (int i = 0; i < size; i++)
        printf(" %d ", list[i]);
    br ? printf("]\n ") : printf("] ");
}
/**
 * this function helps duplicatin an array of integers
 * @param original_number The initial array we want to duplicate
 * @param number_copy the copy of the initial number
 * @param number_len The number of digit contained in the number to duplicate. \n \n
 *
 * This function parses the original array of int (the original_number)
 *  and copy each element in the number_copy
 */
void duplicate_number(array original_number, array number_copy, int number_len)
{
    for (int index = 0; index < number_len; index++)
        number_copy[index] = original_number[index];
}
/**
 * Prepends a new element to the front of a number array .
 *
 * @param number The number array  to prepend to
 * @param len Pointer to the length of the number array
 * @param new_element The new digit to prepend
 *
 * This shifts all existing digits right by 1 position to make room for the
 * new digit at the front. It increments the length after prepending.
 */
void push_front(array number, int *len, int new_element)
{
    int temp = number[0];
    int save;
    for (int i = 1; i < *len + 1; i++)
    {
        save = number[i];
        number[i] = temp;
        temp = save;
    }
    number[0] = new_element;
    (*len)++;
}
/**
 * Reverses the order of elements in an integer array .
 *
 * @param array  The array  to reverse
 * @param array _size The number of elements in the array
 *
 * This function swaps the elements at index i and
 * array _size - i - 1 for all indices from 0 to array _size/2.
 * This has the effect of reversing the order of the array .
 */
void reverse_array(array array, int _size)
{
    int temp;
    for (int index = 0; index < (int)(_size / 2); index++)
    {
        temp = array[index];
        array[index] = array[_size - index - 1];
        array[_size - index - 1] = temp;
    }
}
Bool verify_conversion(array initial_number, int initial_number_len, int initial_base, array final_number, int final_number_len, int final_base)
{
    // convert the initial number in base 10

    // convert the final number in base 10

    // compare the results
    return true;
}
