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



int main(int ac, char **av, char **env)
{
	char *buffer, **ptr;
	pid_t child_pid;
	int characters;
	unsigned int args;
	
	

	
	get_input(buffer);
	
	

	
	child_pid = fork();
	if (child_pid == 0)
{
printf("child");
	
}
	if (child_pid != 0)
	{
		
		printf("parent");
	
		
	}
	
	
	
	return (0);
	
}
