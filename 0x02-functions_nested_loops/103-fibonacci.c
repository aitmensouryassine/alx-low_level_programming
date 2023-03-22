#include <stdio.h>
/**
 * sum_even_fibonacci - finds and prints the sum of the even-valued terms
 * @max: max fibonacci number
 * Return: nothing
 */
void sum_even_fibonacci(unsigned long int max)
{
	unsigned long int fib = 1;
	unsigned long int first_fib = 0;
	unsigned long int sec_fib =  1;
	unsigned long int sum = 0;

	while (fib < max)
	{
		if (fib % 2 == 0)
		{
			sum += fib;
		}

		first_fib = sec_fib;
		sec_fib = fib;
		fib = first_fib + sec_fib;
	}
	printf("%lu\n", sum);
}
/**
 * main - netry point
 *
 * Return: Always 0
 */
int main(void)
{
	sum_even_fibonacci(4000000);

	return (0);
}
