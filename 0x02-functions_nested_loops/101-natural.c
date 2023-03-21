#include "main.h"
#include <stdio.h>
/**
 * print_sum_of_multiples_of_3_and_5 - computes and prints the
 * sum of all the multiples of 3 or 5 below 1024
 * @n: number below which we calculate the sum of multiples of 3 and 5
 * Return: nothing
 */
void print_sum_of_multiples_of_3_and_5(int n)
{
	int sum = 0;

	n--;
	while (n >= 0)
	{
		if (n % 5 == 0)
		{
			sum += n;
			n--;
			continue;
		}
		if (n % 3 == 0)
		{
			sum += n;
			n--;
			continue;
		}
		n--;
	}
	printf("%d\n", sum);
}
/**
 * main - netry point
 *
 * Return: Always 0
 */
int main(void)
{
	print_sum_of_multiples_of_3_and_5(1024);

	return (0);
}
