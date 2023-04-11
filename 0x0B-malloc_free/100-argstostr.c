#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * argstostr - concatenates all the arguments of your program
 * @ac: the arguments count
 * @av: the argument vector
 * Return: a pointer to a new string on success, or NULL on failure
*/
char *argstostr(int ac, char **av)
{
	char *str;
	int l = 0, i = 0, c = ac, j = 0, k;
	char *tmp;

	if (ac == 0 || av == NULL)
		return (NULL);

	while (c--)
	{
		l += (int)strlen(av[i]) + 1;
		i++;
	}

	str = (char *)malloc(sizeof(char) * l + 1);

	if (str == NULL)
		return (NULL);

	i = 0;
	k = 0;
	c = ac;
	while (c--)
	{
		tmp = av[i];
		l = (int)strlen(tmp);
		j = 0;
		while (j < l)
		{
			str[k] = tmp[j];
			j++;
			k++;
		}
		str[k] = '\n';
		k++;
		i++;
	}
	str[k] = '\0';

	return (str);
}
