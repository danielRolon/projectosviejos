#include <iostream>
#include <tools/handleText.h>

char** split(const char* string, char div)
{
    size_t length = strlen(string);
    size_t k_length = 0;

    for (size_t i = 0; i < length; ++i)
    {
        if (string[i] == div)
        {
            ++k_length;  
        }
    }

    char** strings = new char*[k_length+1];
    size_t k = 0;
    size_t last_div = 0;

    for (size_t i = 0; i < length; ++i)
    {
        if (string[i] == div)
        {
            if (k == 0)
            {   
                size_t tam_k_str = i-last_div;
                strings[k] = new char[tam_k_str];
                memcpy(strings[k], &string[last_div], tam_k_str);
                strings[k][tam_k_str] = '\0';
            }
            else
            {
                size_t tam_k_str = i-last_div;
                strings[k] = new char[tam_k_str];
                memcpy(strings[k], &string[last_div+1], tam_k_str);
            }
            
            ++k;
            last_div = i;

            if (k == k_length)
            {
                size_t tam_k_str = length-last_div-1;

                strings[k] = new char[tam_k_str];
                memcpy(strings[k], &string[last_div+1], tam_k_str);
                strings[k][tam_k_str] = '\0';
                break;
            }
        }
    }

    return strings;
}