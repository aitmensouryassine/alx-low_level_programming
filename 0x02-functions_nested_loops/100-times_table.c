#include "main.h"
/**
 * print_long_int - print int > 9 with putchar
 *
 * @n: the number to print
 *
 * Return: nothing
 */
void print_long_int(int n)
{
	if (n / 10)
		print_long_int(n / 10);

	_putchar(n % 10 + '0');
}
/**
 * print_times_table - prints the n times table, starting with 0.
 *
 * @n: the number of times table
 *
 * Return: nothing
 */
void print_times_table(int n)
{
	int i = 0, j, res;

	if (n <= 15 && n >= 0)
	{
		while (i <= n)
		{
			j = 0;
			while (j <= n)
			{
				res = i * j;

				if (res < 10 && j != 0)
				{
					_putchar(',');
					_putchar(' ');
					_putchar(' ');
					_putchar(' ');
				} else if (res >= 10 && res < 100)
				{
					_putchar(',');
					_putchar(' ');
					_putchar(' ');
				} else if (res >= 100)
				{
					_putchar(',');
					_putchar(' ');
				}

				print_long_int(res);

				j++;
			}
			_putchar('\n');
			i++;
		}
	}
}
