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
	int i, j, count;

	i = 0;
	j = 0;
	count  = 1;
	str2 = malloc(sizeof(char) * (strlen(str) - 1));
	while (str[j] != '\n' && str[j] != '\0')
		{
			str2[j] = str[j];
			++j;
			if (str[j] == ' ')
			{
				printf("count %d ", count);
				++count;
			}
		}
	if (count > 1) 
		++count;
	
	ptr = malloc(sizeof(char *) * (count + 1));
	
	token = strtok(str2, delimeter);
	printf("first one: %s", token);
	while (token != NULL)
	{
		ptr[i] = malloc(sizeof(char) * strlen(token));
		strcpy(ptr[i], token);
		token = strtok(NULL, delimeter);
		++i;
	}
	free(str2);  
}



int main(int ac, char **av, char **env)
{
	char *buffer, **ptr, *str3, buf[1024];
	pid_t child_pid;
	int characters;
	unsigned int args;
	size_t size;
	

		
	size = 32;
	
	buffer = NULL;
	printf("$ ");
	characters = getline(&buffer, &size, stdin);
	
	break_string(buffer, " ", ptr);
	
	


	
	
	
	
	
	free(buffer);
	
	return (0);
	
}
