#ifndef UTILS_H
#define UTILS_H

template <typename T>
bool CheckRange0(const T& value, const T& max)
{
	return 0 <= value && value <= max;
}

#endif
