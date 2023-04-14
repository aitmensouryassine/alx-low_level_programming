#include <stdio.h>
#include <stdlib.h>
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
 * _realloc - reallocates a memory block using malloc and free
 * @oldstr: pointer to the old allocated memory
 * @new_size: is the new size, in bytes of the new memory block
 * Return: pointer to the new allocated memory, or NULL on failure
 */
char *_realloc(char *oldstr, unsigned int new_size)
{
	char *newptr;
	unsigned int i = 0;

	newptr = malloc(sizeof(char) * (new_size + 1));
	if (newptr == NULL)
		return (NULL);

	while (i < (new_size - 1))
	{
		*(newptr + i) = *(oldstr + i);
		i++;
	}
	*(newptr + new_size) = '\0';

	free(oldstr);
	return (newptr);
}

/**
 * infinite_add - adds two numbers
 * @n1: first number (a string)
 * @n2: second number (a string)
 * @r: result string
 * Return: pointer to the resulting string @r
 */
char *infinite_add(char *n1, char *n2, char *r)
{
	int l1, l2, n1v, n2v, i, j, k, tmp;

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
		if (i <= 0 && j <= 0)
		{
			r = _realloc(r, (k + 1));
			r[k++] = tmp % 10 + '0';
			if (tmp / 10)
			{
				r = _realloc(r, (k + 1));
				r[k] = tmp / 10 + '0';
			}
		}
		else
		{
			r = _realloc(r, (k + 1));
			r[k] = tmp % 10 + '0';
		}
		tmp = tmp / 10;
	}

	rev_string(r);
	return (r);
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

	newstr = malloc(sizeof(char) * (l + num + 1));
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
 * main - multiplies two positives numbers
 * @argc: arguments count
 * @argv: arguments vector
 * Return: always 0 (success)
 */
int main(int argc, char **argv)
{
	char *num1, *num2;
	unsigned int i, j;
	char *s = NULL, *r = NULL;
	int rest = 0;

	if (argc != 3)
		printf("Error\n"), exit(98);

	num1 = argv[1], num2 = argv[2];

	if (_containsSym(num1) || _containsSym(num2) || argc != 3)
		printf("Error\n"), exit(98);

	rev_string(num1), rev_string(num2);

	i = 0;
	while (num1[i])
	{
		j = 0;
		while (num2[j])
		{
			rest = (num1[i] - '0') * (num2[j] - '0') + rest;
			s = _realloc(s, (j + 1));
			s[j] = (rest % 10) + '0', rest = rest / 10;
			if (!num2[j + 1] && rest != 0)
			{
				s = _realloc(s, (j + 2)), s[j + 1] = rest + '0';
			}
			j++;
		}
		rev_string(s), s = add_zero_to_end(s, i), r = infinite_add(r, s, r);
		i++;
	}
	printf("%s\n", r);
	return (0);
}
