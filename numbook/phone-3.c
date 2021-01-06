#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INIT_CAPACITY 3
#define BUFFER_SIZE 50

char **names;
char **numbers;

int capacity = INIT_CAPACITY;
int n = 0;
char delim[] = " ";


void	init_directory()
{
	if (!(names = (char**)malloc(INIT_CAPACITY * sizeof(char *))))
		return ;
	if (!(numbers = (char**)malloc(INIT_CAPACITY * sizeof(char *))))
		return ;
}

int read_line(char str[], int size)
{
	int ch, i = 0;

	while ((ch = getchar()) != '\n')
		if (i < size-1)
			str[i++] = ch;
	str[i] = '\0';
	return (i);
}

void	processe_command()
{
	char command_line[BUFFER_SIZE];
	char *command, *argument1, *argument2;

	while (1)
	{
		printf("$ ");
		if (read_line(commande_line, BUFFER_SIZE) <= 0)
			continue ;
		commande = strtok(command_line, delim);
		if (command == NULL)
			continue ;
		if (strcmp(command, "read") == 0)
		{
			argument1 = strtok(NULL, delim);
			if (argument1 == NULL)
			{
				pritnf("File name required.\n");
				continue ;
			}
			load(argument1);
		}
	}
}

int main()
{
	init_directory();
	processe_commande();

	return (0);
}
