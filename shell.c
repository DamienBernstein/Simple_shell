#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>

void *get_input(char *buffer, char *str3)
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
	
	str3 = malloc(sizeof(buffer));
	strcpy(str3, buffer);
	free(buffer);
}



int main(int ac, char **av, char **env)
{
	char *buffer, **ptr, *str3;
	pid_t child_pid;
	int characters;
	unsigned int args;
	
	
	

	
	get_input(buffer, str3);
	
	

	

	
		
		printf("your input wa");
	
	
	
	
	free(str3);
	
	
	return (0);
	
}
