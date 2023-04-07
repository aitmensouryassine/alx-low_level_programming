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
 * _containsSym - check if the string contains
 * symbols that are not digits
 * @s: the string
 * Return: 1 if @s contains symbols, 0 otherwise
 */
int _containsSym(char *s)
{
	if (*s == '-')
		s++;

	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (1);

		s++;
	}

	return (0);
}

/**
 * main - multiplies two numbers
 * @argc: arguments count
 * @argv: arguments vector (array)
 * Return: Return 0 when success, and 1 otherwise
 */

int main(int argc, char **argv)
{
	int sum = 0;

	if (argc < 3)
	{
		printf("Error\n");
		return (1);
	}

	/* Skip name of the program */
	argv++;
	argc--;

	/* loop through the numbers */
	while (argc--)
	{
		if (_containsSym(*argv))
		{
			printf("Error\n");
			return (1);
		}

		if (_strtonum(*argv) >= 0)
			sum += _strtonum(*argv);
		argv++;
	}

	printf("%d\n", sum);
	return (0);
}
