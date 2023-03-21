#include <stdio.h>
/**
 * fibonacci - prints first n Fibonacci numbers
 * @n: fibonacci numbers
 * Return: nothing
 */
void fibonacci(int n)
{
	int fib = 1;
	int first_fib = 0;
	int sec_fib =  1;

	while (fib <= n)
	{
		printf("%d", fib);
		printf(", ");

		if (fib == 2)
		{
			printf("\n");
		}

		first_fib = sec_fib;
		sec_fib = fib;
		fib = first_fib + sec_fib;
	}
}
/**
 * main - netry point
 *
 * Return: Always 0
 */
int main(void)
{
	fibonacci(50);

	return (0);
}
