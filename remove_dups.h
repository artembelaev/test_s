#ifndef REMOVE_DUPS_H
#define REMOVE_DUPS_H


void RemoveDups(char * str)
{
    if (*str == '\0')
        return;
    
    char last_char = *str;
    char * new_str = str;
    ++str;
    while (*str != '\0')
    {
        if (last_char != *str)
        { 
            ++new_str;
            *new_str = *str;
            last_char = *str;
        }
        ++str;
    }

    ++new_str;
    *new_str = '\0';
}

#endif

