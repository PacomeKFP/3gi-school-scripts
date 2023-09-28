void add(int *number1, int size_1, int *number2, int size_2)
{

    if (size_1 < size_2)
        return add(number2, size_2, number1, size_1);
    
    int rest = 0;
}