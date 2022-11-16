#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>

int count_args(char *str)
{
	int count, j;
	
	count = 1;
	j = 0;
	
	while (str[j] != '\n' && str[j] != '\0')
		{
			++j;
			if (str[j] == ' ')
			{				
				++count;
			}
		}
	return(count);

}

void break_string(char *str, char *delimeter, char **ptr)
{
	char *token, *str2;
	unsigned int i, j;

	j = 0;
	str2 = calloc((strlen(str)), sizeof(char));
	while (str[j] != '\n' && str[j] != '\0')
		{
			str2[j] = str[j];
			++j;
			
		}

	
	
	token = strtok(str2, delimeter);
	
	i = 0;
	while (token != NULL)
	{
		ptr[i] = calloc((strlen(token) + 1), sizeof(char));
		strcpy(ptr[i], token);
		token = strtok(NULL, delimeter);
		++i;
	}

	free(str2);  
	
}



int main(int ac, char **av, char **env)
{
	char *buffer, **ptr;
	
	int characters;
	unsigned int args, i, count;
	size_t size;
	pid_t process_id;
	

	do {	
	size = 32;
	
	buffer = malloc(sizeof(char) * size);
	
	printf("$ ");

	characters = getline(&buffer, &size, stdin);
	
	count = count_args(buffer);
	
	ptr = calloc((count + 1), sizeof(char *));

	break_string(buffer, " ", ptr);
	
	process_id = fork();
	
	if (process_id == 0)
	{
		execve(ptr[0], ptr, env);
	free(buffer);
	
	i = 0;
	while (ptr[i] != NULL)
	{
		free(ptr[i]);
		++i;
	}
		free(ptr);
	}
	if (process_id > 0)
	{
		wait(NULL);
		free(buffer);
	
	i = 0;
	while (ptr[i] != NULL)
	{
		free(ptr[i]);
		++i;
	}
		free(ptr);
	}
	
	} while (strcmp(ptr[0], "exit") != 0);
	return (0);
	
}
