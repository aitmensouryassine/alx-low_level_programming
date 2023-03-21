#include "main.h"
/**
 * print_ints_less_than_100 - prints ints that are less than 100 with
 * putchar, prints in format XX e.g. ' 5', ' 8', '18'
 *
 * @n: integer to print
 *
 * Return: nothing
 */
void print_ints_less_than_100(int n)
{
	if (n < 10)
	{
		_putchar(' ');
		_putchar(n + '0');
	} else
	{
		_putchar(n / 10 + '0');
		_putchar(n % 10 + '0');

	}
}
/**
 * times_table - prints the 9 times table, starting with 0.
 *
 * Return: nothing
 */
void times_table(void)
{
	int num = 9;
	int times = 9;
	int n = 0;
	int i;

	while (n <= num)
	{
		i = 0;
		while (i <= times)
		{
			print_ints_less_than_100(n * i);

			if (i == times)
			{
				_putchar('\n');
			} else
			{
				_putchar(',');
				_putchar(' ');
			}
			i++;
		}
		n++;
	}
}
