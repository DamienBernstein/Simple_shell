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
	str2 = calloc((strlen(str) - 1), sizeof(char));
	while (str[j] != '\n' && str[j] != '\0')
		{
			str2[j] = str[j];
			++j;
			if (str[j] == ' ')
			{				
				++count;
			}
		}

	
	ptr = calloc((count + 1), sizeof(char *));
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
	
	i = 0;
	while (ptr[i] != NULL)
	{
	free(ptr[0]);
		++i;
	}
	free(ptr);
		printf("task complete");
	
	
	
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