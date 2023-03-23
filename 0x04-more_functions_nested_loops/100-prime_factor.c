#include "main.h"

/**
* main - finds and prints the largest prime factor of the
* number 612852475143, followed by a new line.
* Return: Always 0
*/

int main(void)
{
	unsigned long int n, i, max;

	n = 612852475143;
	i = 2;
	max = 0;

	while (i <= n)
	{
		if (n % i == 0)
		{
			max = max >= i ? max : i;
			n = n / i;
			i = 2;
		}
		i++;
	}
	printf("%lu\n", max);

	return (0);
}
