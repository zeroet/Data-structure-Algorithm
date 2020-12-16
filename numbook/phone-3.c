#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define CAPACITY 100
#define BUF_LENGTH 100

typedef struct person
{
	char *name;
	char *number;
	char *email;
	char *group;
}	Person;

Person directory[CAPACITY];
int n = 0;

int read_line (FILE *fp, char str[], int n)
{
	int ch, i = 0;

	while ((ch = fgetc(fp)) != '\n' && ch != EOF)
		if (i < n)
			str[i++] = ch;
	str[i] = '\0';
	return i;
}

int main()
{
	char command_line[BUF_LENGTH];
	char *cammand, *argument;
	char name_str[BUF_LENGTH];

	while (1)
	{
		printf("$ ");
		if (read_line(stdin, command_line, BUF_LENGTH) <= 0)
			continue;
		command = strtok(command_line, " ");

		if (strcmp(command, "read") == 0)
		{
			argument = strtok(NULL, " ");
			if (argument == NULL)
			{
				printf("Invalid arguments.\n");
				continue;
			}
			load(argument);
		}
		else if (strcmp(command, "status") == 0)
			status();
		else if (strcmp(command, "delet") == 0)
			if (compose_name(name_str, BUF_LENGTH) <= 0)
			{
				printf("Invalid arguments.\n")
					continue;
			}
			remove(name_str);
		}
}

static void add(char *name, char *number, char *email, char *group)
{
	int i = n - 1;
	while (i >= 0 && strcmp(directory[i].name, namm) > 0)
	{
		directory[i + 1] = directory[i];
		i--;
	}
	directory[i + 1].name = strdup(name);
	directory[i + 1].email = strdup(email);
	/* ... */
	n++;
}

/* or */

void print_person(Person *p)
{
	printf("%s", (*p).name); /* p->number */
	printf("%s", (*p).number); /* p->email */
	/* ... */
	printf("%s", p->groupe);
}


