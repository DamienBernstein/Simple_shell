#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>

	

void break_string(char *str, char *delimeter, char **ptr, char **env)
{
	char *token, *str2;
	unsigned int i, j, count;
	pid_t process_id;

	j = 0;
	count  = 1;
	str2 = malloc(sizeof(char) * (strlen(str) - 1));
	while (str[j] != '\n' && str[j] != '\0')
		{
			str2[j] = str[j];
			++j;
			if (str[j] == ' ')
			{				
				++count;
			}
		}

	
	ptr = malloc(sizeof(char *) * (count + 1));
	token = strtok(str2, delimeter);
	
	i = 0;
	while (token != NULL)
	{
		ptr[i] = malloc(sizeof(char) * (strlen(token) + 1));
		strcpy(ptr[i], token);
		token = strtok(NULL, delimeter);
		++i;
	}

	free(str2);  
	
	process_id = fork();
	
	if (process_id == 0)
	{
		execve(ptr[0], ptr, env); 
	}
	
	if (process_id > 0)
	{
		wait(NULL);
		i = 0;
	while (ptr[i] != NULL)
		free(ptr[i]);
	
	free(ptr);
		printf("task complete");
	}
	
	
}



int main(int ac, char **av, char **env)
{
	char *buffer, **ptr;
	
	int characters;
	unsigned int args, i;
	size_t size;
	

		
	size = 32;
	ptr = NULL;
	buffer = NULL;
	printf("$ ");

	characters = getline(&buffer, &size, stdin);

	break_string(buffer, " ", ptr, env);
	
	
	
	


	
		
	
	free(buffer);
	
	return (0);
	
}
