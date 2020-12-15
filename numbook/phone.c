#include <stdio.h>
#include <string.h>

#define CAPACITY 100
#define BUFFER_SIZE 20

int		n = 0;
char	*numbers[CAPACITY];
char	*names[CAPACITY];


static void		add()
{
	char buf1[BUFFER_SIZE], buf2[BUFFER_SIZE];
	
	scanf("%s", buf1);
	scanf("%s", buf2);
	names[n] = strdup(buf1);
	numbers[n] = strdup(buf2);
	n++;
	printf("%s was added successfully.\n", buf1);
} 

static void		find()
{
	char buf[BUFFER_SIZE];
	scanf("%s", buf);

	int i;
	for (i = 0; i < n; i++)
	{
		if (strcmp(buf, names[i]) == 0)
		{
			printf("%s\n", numbers[i]);
			return ;
		}
	}
	printf("No person named '%s' exists.\n", buf);
}

static void		status()
{
	int			i;
	for (i = 0; i < n; i++)
		printf("%s %s\n", names[i], numbers[i]);
	printf("Total %d persons.\n", n);
}

static void		ft_remove()
{
	char		buf[BUFFER_SIZE];
	scanf("%s", buf);

	int			i;
	for (i = 0; i < n; i++)
	{
		if (strcmp(buf, names[i]) == 0)
		{
			names[i] = names[n - 1]; /* last personne */
			numbers[i] = numbers[n - 1];
			n--;
			printf("'%s' was deleted successfully. \n", buf);
			return ;
		}
	}
	printf("No person named '%s' exists. \n", buf);
}

int				main(void)
{
	char		command[BUFFER_SIZE];
	while (1)
	{
		printf("$ ");
		scanf("%s", command);
		if (strcmp(command, "add") == 0)
			add();
		else if (strcmp(command, "find") == 0)
			find();
		else if (strcmp(command, "status") == 0)
			status();
		else if (strcmp(command, "delete") == 0)
			ft_remove();
		else if (strcmp(command, "exit") == 0)
			break;
	}
	return (0);
}

