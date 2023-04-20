#include <stdio.h>
#include <stdarg.h>

/**
 * print_strings - prints strings, followed by a new line.
 * @separator: a character to separate strings
 * @n: optional arguments count
 */

void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list args, cp_args;
	unsigned int i;

	va_copy(cp_args, args);

	va_start(args, n);
	va_start(cp_args, n);

	for (i = 0; i < n; i++)
	{
		if (va_arg(args, char *))
		{
			if (!separator || i == 0)
				printf("%s", va_arg(cp_args, char *));
			else
				printf("%s%s", separator, va_arg(cp_args, char *));
		}
		else
		{
			va_arg(cp_args, char *);
			if (!separator || i == 0)
				printf("(nil)");
			else
				printf("%s(nil)", separator);
		}
	}

	va_end(args);
	va_end(cp_args);

	printf("\n");
}
