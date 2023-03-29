#include "main.h"
#include <string.h>

/**
 * rev_string - reverse array
 * @c: string to reverse
 * Return: nothing
 */

void rev_string(char *c)
{
	int k, tmp, l;

	l = strlen(c);
	k = 0;
	for (k = 0; k < l; k++, l--)
	{
		tmp = c[k];
		c[k] = c[l - 1];
		c[l - 1] = tmp;
	}
}

/**
 * infinite_add - adds two numbers
 * @n1: first number (a string)
 * @n2: second number (a string)
 * @r: result string
 * @size_r: is the buffer size
 * Return: pointer to the resulting string @r
 */

char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int l1, l2, n1v, n2v, i, j, k, tmp, rlen;

	tmp = 0;
	l1 = strlen(n1);
	l2 = strlen(n2);
	k = 0;

	for (i = l1 - 1, j = l2 - 1; i >= 0 || j >= 0; i--, j--, k++)
	{
		if (j < 0)
			n2v = 0;
		else
			n2v = (n2[j] - '0');

		if (i < 0)
			n1v = 0;
		else
			n1v = (n1[i] - '0');

		tmp = tmp + n1v + n2v;
		if (i <= 0 && j <= 0)
		{
			r[k++] = tmp % 10 + '0';
			r[k] = tmp / 10 + '0';
		} else
				r[k] = tmp % 10 + '0';
		tmp = tmp / 10;
	}
	r[k] = '\0';

	rlen = strlen(r);
	if (rlen + 1 > size_r)
		return (0);

	rev_string(r);
	return (r);
}
