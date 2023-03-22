#include <stdio.h>
/**
 * fibonacci - prints first n Fibonacci numbers
 * @n: fibonacci numbers
 * Return: nothing
 */
void fibonacci(int n)
{
	int i = 1;
	unsigned long int first_fib_0, sec_fib_0, first_fib_1;
	unsigned long int first_fib_2, sec_fib_1, sec_fib_2;

	first_fib_0 = 1;
	sec_fib_0 = 2;

	printf("%lu", first_fib_0);

	while (i < 91)
	{
		printf(", %lu", sec_fib_0);
		sec_fib_0 = sec_fib_0 + first_fib_0;
		first_fib_0 = sec_fib_0 - first_fib_0;

		i++;
	}

	first_fib_1 = first_fib_0 / 1000000000;
	first_fib_2 = first_fib_0 % 1000000000;
	sec_fib_1 = sec_fib_0 / 1000000000;
	sec_fib_2 = sec_fib_0 % 1000000000;

	i = 92;
	while (i <= n)
	{
		printf(", %lu", sec_fib_1 + (sec_fib_2 / 1000000000));
		printf("%lu", sec_fib_2 % 1000000000);
		sec_fib_1 = sec_fib_1 + first_fib_1;
		first_fib_1 = sec_fib_1 - first_fib_1;
		sec_fib_2 = sec_fib_2 + first_fib_2;
		first_fib_2 = sec_fib_2 - first_fib_2;
		i++;
	}
	printf("\n");
}
/**
 * main - netry point
 *
 * Return: Always 0
 */
int main(void)
{
	fibonacci(98);

	return (0);
}
