#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define CAPACITY 100
#define BUF_SIZE 20

char *names[CAPACITY];
char *numbers[CAPACITY];
int n = 0;


static int search(char *name)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (strcmp(name,names[i]) == 0)
			return (i);
	}
	return (-1);
}

static void		load()
{
	char filename[BUF_SIZE];
	char buf1[BUF_SIZE];
	char buf2[BUF_SIZE];

	scanf("%s", filename);

	FILE *fp = fopen(filename, "r");
	if (fp==NULL)
	{
		printf("Open failed.\n");
		return ;
	}
	while ((fscanf(fp, "%s", buf1) != EOF))
	{
		fscanf(fp, "%s", buf2);
		names[n] = strdup(buf1);
		numbers[n] = strdup(buf2);
		n++;
	}
	fclose(fp);
}

static void ft_save()
{
	int i;
	char filename[BUF_SIZE];
	char tmp[BUF_SIZE];

	scanf("%s", tmp);
	scanf("%s", filename);

	FILE *fp = fopen(filename, "w");
	if (fp == NULL)
	{
		printf("Open failed.\n");
		return ;
	}
	for (i = 0; i < n; i++)
	{
		fprintf(fp, "%s %s\n", names[i], numbers[i]);
	}
	fclose(fp);
}

static void add()
{
	char buf1[BUF_SIZE], buf2[BUF_SIZE];
	scanf("%s", buf1);
	scanf("%s", buf2);

	int i = n -1 ;
	while (i >= 0 && strcmp(names[i], buf1) > 0)
	{
		names[i+1] = names[i];
		numbers[i+1] = numbers[i];
		i--;
	}
	names[i + 1] = strdup(buf1);
	numbers[i + 1] = strdup(buf2);
	n++;
	printf("%s was added successfully.\n", buf1);
}

static void		ft_remove()
{
	char buf[BUF_SIZE];
	scanf("%s", buf);

	int index = search(buf);
	if (index == -1)
	{
		printf("No person named '%s' exists.\n", buf);
		return ;
	}

	int j = index;
	for (; j < n - 1; j++)
	{
		names[j] = names[j + 1];
		numbers[j] = numbers[j + 1];
	}
	n--;
	printf("'%s' was deleted successfully. \n", buf);
}

static void	 find()
{
	char buf[BUF_SIZE]; 
	scanf("%s", buf);
	int index = search(buf);
	if (index == -1)
		printf("No person named '%s' exists.\n", buf);
	else
		printf("%s\n", numbers[index]);
}

static void status()
{
	int i;
	for (i = 0; i < n; i++)
		printf("%s, %s\n", names[i], numbers[i]);
	printf("Total %d person.\n", n);
}


int main()
{
	char buffer[BUF_SIZE];

	while (1)
	{
		printf("$ ");
		scanf("%s", buffer);
		if (strcmp(buffer, "read") == 0)
			load();
		else if (strcmp(buffer, "add") == 0)
			add();
		else if (strcmp(buffer, "find") == 0)
			find();
		else if (strcmp(buffer, "status") == 0)
			status();
		else if (strcmp(buffer, "delete") == 0)
			ft_remove();
		else if (strcmp(buffer, "save") == 0)
			ft_save();
		else if (strcmp(buffer, "exit") == 0)
			break;
	}
	return (0);
}
