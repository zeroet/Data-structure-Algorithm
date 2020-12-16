#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INIT_CAPCITY 100

typedef struct t_list
{
	char *name;
	char *number;
	char *emial;
	char *group;
}	Person;

Person **directory;
int capacity;
int n;

void init()
{
	directory = (Person *)malloc(INIT_CAPACITY * sizeof(Person *));
	capacity = INIT_CAPACITY;
	n = 0;
}


