#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
 * print_all - prints anything.
 * @format: list of types of arguments passed to the function
 */
void print_all(const char *const format, ...)
{
	int i = 0;
	char *tmp, *sep = "";
	va_list args;

	va_start(args, format);
	while (format && format[i])
	{
		switch (format[i])
		{
		case 'c':
			printf("%s%c", sep, va_arg(args, int));
			break;

		case 'i':
			printf("%s%d", sep, va_arg(args, int));
			break;

		case 'f':
			printf("%s%f", sep, va_arg(args, double));
			break;

		case 's':
			tmp = va_arg(args, char *);
			if (tmp)
			{
				printf("%s%s", sep, tmp);
				break;
			}
			printf("%s(nil)", sep);
			break;

		default:
			i++;
			continue;
		}
		sep = ", ";
		i++;
	}
	printf("\n");
	va_end(args);
}
