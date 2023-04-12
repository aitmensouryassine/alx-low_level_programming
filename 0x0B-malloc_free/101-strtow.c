#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * strtow - splits a string into words
 * @str: the string
 * Return: pointer to an array of strings (words) on success
 * and NULL on failure
 */
char **strtow(char *str)
{
	char **arr;
	int wc = 0, cc = 0, i, j, k, l = strlen(str);

	if (str == NULL || l == 0)
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == 32)
			continue;

		if (str[i] != 32 && str[i - 1] == 32)
			wc++;
	}

	arr = (char **)malloc(sizeof(char *) * wc + 1);

	j = 0;
	for (i = 0; i <= l; i++)
	{
		if (str[i] == 32 || str[i] == '\0')
		{
			if (cc != 0)
			{
				*(arr + j) = (char *)malloc(sizeof(char) * cc + 1);
				j++;
			}
			cc = 0;
		}

		if (str[i] != 32)
			cc++;
	}

	j = 0;
	k = 0;
	for (i = 0; i <= l; i++)
	{
		if (str[i] == 32)
		{
			if (k > 0)
			{
				*(*(arr + j) + k) = '\0';
				j++;
				k = 0;
			}
		}

		if (str[i] != 32)
		{
			*(*(arr + j) + k) = str[i];
			k++;
		}
	}

	return (arr);
}
