#include "main.h"
#include "string.h"

/**
 * _atoi - convert a string to an integer.
 * @s: The string to convert
 * Return: an integer
 */

int _atoi(char *s)
{
	int i, j, k, len, mul, sign, numbers, result;

	k = 1;
	result = 0;
	numbers = 9;
	sign = 0;
	len = strlen(s);

	for (i = len; i >= 0; i--)
	{
		if	(s[i] == '+')
		{
			sign++;
		} else if (s[i] == '-')
		{
			sign--;
		}

		for (j = 0; j <= numbers; j++)
		{
			if (s[i] - '0' == j)
			{
				result += k * j;
				k *= 10;
			}
		}
	}

	if (sign != 0)
	{
		result *= sign;
	}

	return (result);
}
