#ifndef DEC_TO_BIN_H
#define DEC_TO_BIN_H

#define BITS_IN_BYTE 8

std::string DecToBin(int value)
{
    int bitCount = sizeof(value) * BITS_IN_BYTE;
   
    std::string str;
    int digidIndex = 0;
    for (int i = bitCount - 1; i >= 0; --i)
    {
        int bit = (value >> i) & 1;

        if ((bit == 1 || i == 0) && str.size() == 0) // first 1 or last digit
            str.resize((size_t)i + 1);

        if (str.size() > 0)
        {
            str[digidIndex] = bit == 1 ? '1' : '0';
            ++digidIndex;
        }
    }

    return str;
}

#endif

