#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * rev_string - reverse a string
 * @s: the string to reverse
 */
void rev_string(char *s)
{
	int i, len;
	char tmp;

	len = strlen(s);

	for (i = 0; i < len / 2; i++)
	{
		tmp = s[i];
		s[i] = s[len - i - 1];
		s[len - i - 1] = tmp;
	}
}

/**
 * _containsSym - check if the string contains
 * symbols that are not digits
 * @s: the string
 * Return: 1 if @s contains symbols, 0 otherwise
 */
int _containsSym(char *s)
{
	if (*s == '-')
		s++;

	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (1);

		s++;
	}

	return (0);
}

/**
 * _realloc - reallocates a memory block using malloc and free
 * @old: pointer to the old allocated memory
 * @size: is the new size, in bytes of the new memory block
 * Return: pointer to the new allocated memory, or NULL on failure
 */
char *_realloc(char *old, int size)
{
	char *new;
	int i = 0;

	new = malloc(sizeof(new) * size);
	if (new == NULL)
		return (NULL);

	while (i < (size - 1))
	{
		*(new + i) = *(old + i);
		i++;
	}

	free(old);
	return (new);
}

/**
 * add_zero_to_end - add zero to end of a string
 * @s: the string
 * @num: number of zeros to add
 * Return: pointer to the new allocated memory
 */
char *add_zero_to_end(char *s, int num)
{
	int i;
	char *newstr;
	int l = strlen(s);

	if (num == 0)
		return (s);

	newstr = malloc(sizeof(newstr) * (l + num));
	if (newstr == NULL)
		return (NULL);

	i = 0;
	while (i < l)
	{
		*(newstr + i) = *(s + i);
		i++;
	}

	for (i = l; i < (l + num); i++)
	{
		*(newstr + i) = '0';
	}
	*(newstr + i) = '\0';

	free(s);
	return (newstr);
}

/**
 * infinite_add - adds two numbers
 * @n1: first number (a string)
 * @n2: second number (a string)
 * Return: pointer to the resulting string
 */
char *infinite_add(char *n1, char *n2)
{
	int l1, l2, n1v, n2v, i, j, k, tmp;
	char *r = NULL;

	tmp = 0;
	l1 = n1 == NULL ? 0 : strlen(n1);
	l2 = n2 == NULL ? 0 : strlen(n2);
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

		r = _realloc(r, (k + 1));
		r[k] = tmp % 10 + '0';

		if (i <= 0 && j <= 0 && tmp / 10 != 0)
		{
			k++;
			r = _realloc(r, (k + 1));
			r[k] = tmp / 10 + '0';
		}
		tmp = tmp / 10;
	}
	r = _realloc(r, (k + 1));
	r[k] = '\0';

	free(n1), free(n2);

	rev_string(r);
	return (r);
}

/**
 * main - multiplies two positives numbers
 * @argc: arguments count
 * @argv: arguments vector
 * Return: always 0 (success)
 */
int main(int argc, char **argv)
{
	char *num1, *num2, *mul = NULL, *res = NULL;
	int l1, l2, i = 0, j = 0, k = 0, tmp = 0;

	if (argc != 3)
		printf("Error\n"), exit(98);

	num1 = argv[1], num2 = argv[2], l1 = strlen(num1), l2 = strlen(num2);

	if (_containsSym(num1) || _containsSym(num2))
		printf("Error\n"), exit(98);

	rev_string(num1), rev_string(num2);

	for (i = 0; i < l1; i++, k = 0)
	{
		for (j = 0; j < l2; j++, k++, tmp = tmp / 10)
		{
			tmp = (num1[i] - '0') * (num2[j] - '0') + tmp;
			mul = _realloc(mul, (k + 1));
			mul[k] = tmp % 10 + '0';

			if (!num2[j + 1] && tmp / 10 != 0)
			{
				k++, mul = _realloc(mul, (k + 1));
				mul[k] = tmp / 10 + '0';
			}
		}
		mul = _realloc(mul, (k + 1));
		mul[k] = '\0', tmp = 0;

		rev_string(mul);
		mul = add_zero_to_end(mul, i);
		res = infinite_add(mul, res);
		free(mul), mul = NULL;
	}

	printf("%s\n", res), free(res);
	return (0);
}
