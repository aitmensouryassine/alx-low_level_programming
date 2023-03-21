#include "main.h"
/**
 * print_sum_of_multiples_of_3_and_5 - computes and prints the
 * sum of all the multiples of 3 or 5 below 1024
 *
 * Return: nothing
 */
void print_sum_of_multiples_of_3_and_5(void)
{
	int i = 1024;
	int sum = 0;

	i--;
	while (i >= 0)
	{
		if (i % 5 == 0)
		{
			sum += i;
			i--;
			continue;
		}
		if (i % 3 == 0)
		{
			sum += i;
			i--;
			continue;
		}
		i--;
	}
	printf("%d\n", sum);
}
