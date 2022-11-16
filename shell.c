#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>

	

void break_string(char *str, char *delimeter, char **ptr)
{
	char *token, *str2;
	unsigned int i, j, count;

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
	
			
}



int main(int ac, char **av, char **env)
{
	char *buffer, **ptr;
	pid_t child_pid;
	int characters;
	unsigned int args, i;
	size_t size;
	

		
	size = 32;
	ptr = NULL;
	buffer = NULL;
	printf("$ ");

	characters = getline(&buffer, &size, stdin);

	break_string(buffer, " ", ptr);
	
	printf("pointer %s", ptr[0]);
	
	


	
	free(ptr);
	
	
	free(buffer);
	
	return (0);
	
}
