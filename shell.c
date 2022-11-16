#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>

void *get_input(char *buffer)
{
	int characters;
	size_t size;
	char buf[1024] = 0;

	
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
	
	strcpy(buf, buffer);
	free(buffer);
	return (buf);
}



int main(int ac, char **av, char **env)
{
	char *buffer, **ptr, *str3, buf[1024];
	pid_t child_pid;
	int characters;
	unsigned int args;
	
	
	

	
	buf = get_input(buffer);
	
	

	

	
		
		printf("your input wa");
	
	
	
	
	free(str3);
	
	
	return (0);
	
}
