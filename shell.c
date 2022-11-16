#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>

char *get_input(char *buffer)
{
	int characters;
	size_t size;
	char *str3;
	
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
	
	strcpy(str3, buffer);
	free(buffer);
	return (str3);
}



int main(int ac, char **av, char **env)
{
	char *buffer, **ptr, *str3;
	pid_t child_pid;
	int characters;
	unsigned int args;
	
	
	

	
	str3 = get_input(buffer);
	
	

	

	
		
		printf("your input wa");
	
	
	
	
	
	
	
	return (0);
	
}
