
// Helper functions
void duplicate_number(int *initial, int *quotients, int len)
{
    for (int i = 0; i < len; i++)
    {
        quotients[i] = initial[i];
    }
}

int extend_digit(int *quotients, int index, int remain, int base)
{
    int extended = digit;
    extended *= base;
    extended += quotients[index + 1];
    return extended;
}

void divide_extended_digit(int extended, int base, int *quotients, int index, int *remain)
{
    // Implementation
}

void reverse_array(int *array, int len)
{
    // Implementation
}

void convert_to_base(int *initial_number, int initial_number_len, int initial_base, int *final_number, int *final_number_len, int final_base)
{

    // 1. Duplicate initial number to avoid side effects
    int *quotients = malloc(sizeof(int) * initial_number_len);
    duplicate_number(initial_number, quotients, initial_number_len);

    // 2. Initialize variables
    int remain = 0;
    int index = 0;
    int extended_digit = 0;

    // 3. Main loop
    while (index < initial_number_len)
    {

        // 3.1 Extend digit
        extended_digit = extend_digit(quotients, index, remain, initial_base);

        // 3.2 Divide extended digit
        divide_extended_digit(extended_digit, final_base, quotients, index, remain);

        // 3.3 Update index and remain
        index++;
        if (index == initial_number_len)
        {
            index = 0;
            remain = 0;
        }
    }

    // 4. Reverse final number
    reverse_array(final_number, *final_number_len);
}
