#include "main.h"
#include <stdio.h>

/**
 * _strtonum - converts a string to a number
 * @s: the string
 * Return: integer
 */
int _strtonum(char *s)
{
	int res = 0, sign = 1;

	if (*s == '-')
	{
		sign = -1;
		s++;
	}

	while (*s)
	{
		res = (res * 10) + (*s - '0');
		s++;
	}

	return (res * sign);
}

/**
 * main - multiplies two numbers
 * @argc: arguments count
 * @argv: arguments vector (array)
 * Return: Return 0 when success, and 1 otherwise
 */

int main(int argc, char **argv)
{
	if (argc < 3)
	{
		printf("Error\n");
		return (1);
	}

	printf("%d\n", _strtonum(argv[1]) * _strtonum(argv[2]));
	return (0);
}
