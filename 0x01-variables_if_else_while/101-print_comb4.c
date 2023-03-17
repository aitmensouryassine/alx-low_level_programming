#include <stdio.h>
/**
 * main - Entry point
 *
 * Return: Always 0
*/
int main(void)
{
	int i = 0;
	int j = 0;
	int k = 0;

	for (i = 0; i <= 9; i++)
	{
		for (j = 0; j <= 9; j++)
		{
			for (k = 0; k <= 9; k++)
			{
				if (i == j || j == k || i == k || j <= i ||  k <= j)
					continue;

				putchar('0' + i);
				putchar('0' + j);
				putchar('0' + k);

				if (i >= 7)
					break;

				putchar(',');
				putchar(' ');
			}
		}
	}
	putchar('\n');

	return (0);
}
