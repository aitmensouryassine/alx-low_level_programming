#include <stdlib.h>
#include "dog.h"

/**
 * init_dog - intializes a variable of type struct dog
 * @d: a pointer to the variable
 * @name: name of the dog
 * @age: age of the dog
 * @owner: name of the owner
*/
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	d->name = name;
	d->age = age;
	d->owner = owner;
}
