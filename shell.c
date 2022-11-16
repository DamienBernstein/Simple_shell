#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>

int get_input(char *buffer, size_t size)
{
	do {
		printf("$ ");
		characters = getline(&buffer, &size, stdin);
	if (characters == -1)
	{
		printf("\n");
		return (-1);
	}
		} while (characters == 1);
	return (1);
	
}

int main(int ac, char **av, char **env)
{
	char *buffer;
	size_t size;
	pid_t child_pid;
	int status;
	
	size = 32;
	buffer = malloc(sizeof(char) * size);
	
	child_pid = fork();
	if (child_pid == 0)
{
execve(buffer, buffer, env);
}
	else
	{
		wait(&status);
	}
	
	
	free(buffer);
	
	return (0);
	
}
