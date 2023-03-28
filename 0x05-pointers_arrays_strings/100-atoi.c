#include "main.h"
#include "string.h"

/**
 * _atoi - convert a string to an integer.
 * @s: The string to convert
 * Return: an integer
 */

int _atoi(char *s)
{
	int i, j, len, sign;
	unsigned int result;

	result = 0;
	sign = 1;
	len = strlen(s);

	for (i = 0; i < len; i++)
	{
		if (s[i] == '-')
			sign *= -1;
		if (s[j] >= '0' && s[j] <= '9')
			break;
	}

	for (j = 0; j < len; j++)
	{
		if (s[j] >= '0' && s[j] <= '9')
		{
			result = (result * 10) + (s[j] - '0');

			if (s[j + 1] < '0' || s[j + 1] > '9')
				break;
		}
	}

	return (result * sign);
}
