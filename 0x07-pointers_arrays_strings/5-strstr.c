#include "main.h"
#include <string.h>

/**
 * _strstr - locates a substring @needle in string @haystack
 * @haystack: string
 * @needle: string
 * Return: Returns a pointer to the beginning of the located substring,
 * or NULL if the substring is not found.
 */
char *_strstr(char *haystack, char *needle)
{
	int i, j, len1 = 0, len2 = strlen(needle);

	for (i = 0; *(haystack + i) != '\0'; i++)
	{
		len1 = 0;
		for (j = 0; *(needle + j) != '\0'; j++)
		{
			if (*(needle + j) != *(haystack + i))
			{
				i -= len1;
				break;
			}
			else
			{
				len1++;
				i++;
				if (len1 == len2)
					return (haystack + i - len1);
			}
		}
	}
	return (0);
}
