
#define INIT_CAPACITY 100

typedef struct {
	char *name;
	char *number;
	char *email;
	char *group;
}	Person;

Person **directory;
int capacity;
int n;

void init()
{
	directory = (Person **)malloc(INIT_CAPACITY * sizeof(Person *));	capacity = INIT_CAPACITY;
	n = 0;
}
/* add new Person contenu */
while (i >= 0 && strcmp(directory[i]->name, name) > 0)
{
	directory[i + 1] = directory[i];
	i--;
}
directory[i + 1] = (Person *)malloc(sizeof(Person));
n++;
}

/* remove Person contenu */
Person *p = directory[i];
for (int j=i; j<n-1; j++)
	directory[j] = directory[j+1];
n--;

void reallocate()
{
	capacity *= 2;
	Person **tmp = (Person **)malloc(capacity * sizeof(Person *));
	for (int i=0; i<n; i++)
		tmp[i] = directory[i];
	free(directory);
	directory = tmp;
}
