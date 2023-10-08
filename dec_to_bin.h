#ifndef DEC_TO_BIN_H
#define DEC_TO_BIN_H

#define BITS_IN_BYTE 8

std::string DecToBin(int value)
{
    int bit_count = sizeof(value) * BITS_IN_BYTE;

    std::string str;
    int digid_index = 0;
    for (int i = bit_count - 1; i >= 0; --i)
    {
        int bit = (value >> i) & 1;

        if ((bit == 1 || i == 0) && str.size() == 0) // first 1 or last digit
            str.resize((size_t)i + 1);

        if (str.size() > 0)
        {
            str[digid_index] = bit == 1 ? '1' : '0';
            ++digid_index;
        }
    }

    return str;
}

#endif

