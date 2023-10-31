#include "header.h"

string read_string()
{
    string str;

    scanf("%s", str);

    return str;
}

string interprete_command()
{
}
string trim(string str)
{

    return "trim the string";
}
StringList split(string str)
{
    INIT_STRING_LIST(result);
    result[0] = "";
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == " ")
            result.size++;
        strcat(result.strings[result.size], str[i])
    }

    return result;
}