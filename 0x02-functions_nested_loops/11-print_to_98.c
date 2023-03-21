#include "main.h"
#include <stdio.h>
/**
 * print_to_98 - prints all natural numbers from n to 98
 * @n: the integer from which to start printing nutural numbers
 * Return: Nothing
 */
void print_to_98(int n)
{
	int to = 98;

	if (n < to)
	{
		while (n <= to)
		{
			printf("%d", n);

			if (n != to)
			{
				putchar(',');
				putchar(' ');
			}
			n++;
		}
	} else
	{
		while (n >= to)
		{
			printf("%d", n);

			if (n != to)
			{
				putchar(',');
				putchar(' ');
			}
			n--;
		}
	}
	putchar('\n');
}
