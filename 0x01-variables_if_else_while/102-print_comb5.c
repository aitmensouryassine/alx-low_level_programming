
0;10;1c#include <stdio.h>
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
	int l = 0;

	for (i = 0; i <= 9; i++)
	{
		for (j = 0; j <= 9; j++)
		{
			for (k = 0; k <= 9; k++)
			{
				for (l = 0; l <= 9; l++)
				{
					if ((i == k && j == l) || l <= j)
						continue;

					putchar('0' + i);
					putchar('0' + j);
					putchar(' ');
					putchar('0' + i);
					putchar('0' + k);

					if (j >= 8 && k >= 9 && l >= 9)
						break;

					putchar(',');
					putchar(' ');
				}
			}
		}
	}
	putchar('\n');

	return (0);
}
