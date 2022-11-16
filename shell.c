#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>

	





int main(int ac, char **av, char **env)
{
	char *buffer, **ptr, *str3, buf[1024];
	pid_t child_pid;
	int characters;
	unsigned int args;
	int characters;
	size_t size;
		
	size = 32;
	
	buffer = NULL;
	printf("$ ");
	characters = getline(&buffer, &size, stdin);


	
	
		
	printf("your input wa");
	
	
	
	
	
	free(buffer);
	
	return (0);
	
}
