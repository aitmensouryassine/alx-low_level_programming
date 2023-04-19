#include "function_pointers.h"

/**
 * print_name - prints a name
 * @name: the name (string) to print
 * @f: a function pointer
 */

void print_name(char *name, void (*f)(char *))
{
	f(name);
}
