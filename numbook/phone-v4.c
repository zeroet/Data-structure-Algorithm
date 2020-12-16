#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INIT_CAPCITY 100
#define BUF_SIZE 100
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

void load(char *fileName)
{
	char buffer[BUF_SIZE];
	char *name, *number, *email, *group;
	char *token;

	FILE *fp = fopen(fileName, "r");
	if (fp == 0)
	{
		printf("Open failed.\n");
		return (0);
	}
	while (1)
	{
		if (read_line(fp, buffer, BUF_LENGTH) <= 0)
			break ;
		name = strtok(buffer, "#");
		add(strdup(name), number, email, group);
		fclose(fp);
	}
}
