#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * wordcount - counts words in a string
 * @str: the string
 * @l: string length
 * Return: number of words as an integer
 */
int wordcount(char *str, int l)
{
	int wc = 0, i;

	for (i = 0; i <= l; i++)
		if (str[i] != 32 && (str[i + 1] == 32 || str[i + 1] == '\0'))
			wc++;

	return (wc);
}

/**
 * allocate2D - allocate the second dimension of a 2D array
 * @arr: the arr
 * @str: the string
 * @l: string length
 * Return: return NULL on failure, 0 on success
 */
int *allocate2D(char **arr, char *str, int l)
{
	int i, j = 0, k, cc = 0;

	for (i = 0; i <= l; i++)
	{
		if (str[i] == 32 || str[i] == '\0')
		{
			if (cc > 0)
			{
				*(arr + j) = (char *)malloc(sizeof(char) * cc + 1);
				if (*(arr + j) == NULL)
				{
					for (k = 0; k <= j; k++)
					{
						free(*(arr + k));
					}
					free(arr);
					return (NULL);
				}
				j++;
			}
			cc = 0;
		}

		if (str[i] != 32)
			cc++;
	}

	return (0);
}

/**
 * _strtow - fill a 2d array with words from a string
 * @arr: the arr
 * @str: the string
 * @l: string length
 * Return: nothing
 */
void _strtow(char **arr, char *str, int l)
{
	int j = 0, k = 0, i;

	for (i = 0; i < l; i++)
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
}
/**
 * strtow - splits a string into words
 * @str: the string
 * Return: pointer to an array of strings (words) on success
 * and NULL on failure
 */
char **strtow(char *str)
{
	char **arr;
	int wc, l = strlen(str);

	if (str == NULL || l == 0)
		return (NULL);

	wc = wordcount(str, l);

	if (wc == 0)
		return (NULL);

	arr = (char **)malloc(sizeof(char *) * wc + 1);
	if (arr == NULL)
		return (NULL);

	allocate2D(arr, str, l);

	*(arr + wc) = NULL;

	_strtow(arr, str, l);

	return (arr);
}
