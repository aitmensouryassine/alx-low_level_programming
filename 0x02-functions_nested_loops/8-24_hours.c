#include "main.h"
/**
 * jack_bauer -  prints every minute of the day of Jack Bauer, starting fro
 * 00:00 to 23:59
 *
 * Return: nothing
 */
void jack_bauer(void)
{
	int hour = 24;
	int min = 60;

	int h = 0, m;

	while (h < hour)
	{
		m = 0;
		while (m < min)
		{
			_putchar(h / 10 + '0');
			_putchar(h % 10 + '0');
			_putchar(':');
			_putchar(m / 10 + '0');
			_putchar(m % 10 + '0');
			_putchar('\n');

			m++;
		}
		h++;
	}
}
