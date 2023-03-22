#include <stdio.h>
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

	putchar(n % 10 + '0');
}
/**
 * fibonacci - prints first n Fibonacci numbers
 * @n: fibonacci numbers
 * Return: nothing
 */
void fibonacci(int n)
{
	int i = 0;
	unsigned long int fib = 1;
	unsigned long int first_fib = 0;
	unsigned long int sec_fib =  1;

	while (i < n)
	{
		_print_long_int(fib);
		if (i < n - 1)
			printf(", ");

		first_fib = sec_fib;
		sec_fib = fib;
		fib = first_fib + sec_fib;
		i++;
	}
	putchar('\n');
}
/**
 * main - netry point
 *
 * Return: Always 0
 */
int main(void)
{
	fibonacci(100);

	return (0);
}
