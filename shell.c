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
	
	
	
	

		printf("$ ");
		characters = getline(&buffer, &size, stdin);

		
}



int main(int ac, char **av, char **env)
{
	char *buffer, **ptr, *str3, buf[1024];
	pid_t child_pid;
	int characters;
	unsigned int args;
	
	
	buffer = NULL;

	
	get_input(buffer);
	
	

	

	
		
		printf("your input wa");
	
	
	
	
	
	free(buffer);
	
	return (0);
	
}
