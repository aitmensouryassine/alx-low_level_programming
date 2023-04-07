#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints the minimum number of coins to make
 * change for an amount of money.
 * @argc: arguments count
 * @argv: arguments vector (array)
 * Return: Amount of cents to give back, or
 * if argc == 1 : return 1
 */

int main(int argc, char **argv)
{
	int cents[] = {25, 10, 5, 2, 1};
	int amount, count, i, size = sizeof(cents) / sizeof(int);

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	amount = atoi(argv[1]);
	count = 0;

	if (amount < 0)
	{
		printf("0\n");
		return (0);
	}

	while (amount)
	{
		for (i = 0; i < size; i++)
		{
			if (amount - cents[i] >= 0)
			{
				amount -= cents[i];
				count++;
				break;
			}
		}
	}

	printf("%d\n", count);
	return (0);
}
