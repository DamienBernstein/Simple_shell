#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>

void get_input(char *buffer)
{
	int characters;
	size_t size;
	
	size = 32;
	
	buffer = malloc(sizeof(char) * size);
	
	do {
		printf("$ ");
		characters = getline(&buffer, &size, stdin);
		if (characters == -1)
		{
		printf("\n");
		}
		
	} while (characters == 1);
	
	
}

unsigned int count_args(char *str, char *delimeter)
{
unsigned int count;
char *buffer;
char *token;

buffer = malloc(sizeof(str));
strcpy(buffer, str);
count = 0;
token = strtok(buffer, delimeter);

while (token != NULL)
{
++count;
token = strtok(NULL, " ");
}
free(buffer);
return (count + 1);
}

void break_string(char *str, char *delimeter, char **ptr)
{
char *token, *str2;
int i, j;

i = 0;
j = 0;
str2 = malloc(sizeof(char) * (strlen(str) - 1));
while (str[j] != '\n' && str[j] != '\0')
{
str2[j] = str[j];
++j;
}
token = strtok(str2, delimeter);
while (token != NULL)
{
ptr[i] = malloc(sizeof(char) * strlen(token));
strcpy(ptr[i], token);
token = strtok(NULL, delimeter);
++i;
}
free(str2);  
}



int main(int ac, char **av, char **env)
{
	char *buffer, **ptr;
	pid_t child_pid;
	int status, characters;
	unsigned int args;
	

	
	get_input(buffer);
	args = count_args(buffer, " ");
	
	ptr = malloc(sizeof(char *) * (args + 1));

	
	break_string(buffer, " ", ptr);
	

	
	child_pid = fork();
	if (child_pid == 0)
{
execve("/bin/", ptr, env);
}
	else
	{
		wait(&status);
	}
	
	
	free(buffer);
	
	return (0);
	
}
