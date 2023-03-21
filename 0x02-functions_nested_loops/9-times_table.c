#include "main.h"
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
	int i, res;

	while (n <= num)
	{
		i = 0;
		while (i <= times)
		{
			res = n * i;

			_putchar(res + '0');

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
