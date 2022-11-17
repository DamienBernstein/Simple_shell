#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>


/**
 * count_args - counts arguments
 * @str: string
 * @c: character
 * Return: numbers of arguements
 */
int count_args(char *str, char c)
{
	int count, j;

	count = 1;
	j = 0;

	while (str[j] != '\n' && str[j] != '\0')
		{
			++j;
			if (str[j] == c)
			{				
				++count;
			}
		}
	return(count);

}

/**
 * break_string - breaks a string
 * @str: string
 * @delimeter: indicates beginning or end of string
 * @ptr: points to a string
 * Return: nothing
 */
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

/**
 * searchforfunction - searches for file/directory
 * @str: string
 * @directory: path
 * Return: 0
 */
int searchforfunction(char *str, char *directory)
{
struct dirent *de;
DIR *dr = opendir(directory);
if (dr == NULL)
{
printf("Could not open current directory");
return (0);
}

while ((de = readdir(dr)) != NULL)
{
if (strcmp(de->d_name, str) == 0)
{
closedir(dr);
return (1);
}
}
closedir(dr);
return (0);
}

/**
 * main - entry point
 * @ac: counts arguements
 * @av: number of arguements
 * @env: environment
 * Return: 0
 */
int main(int ac, char **av, char **env)
{
	char *buffer, **ptr, *PATH, **paths, buffer_path[1024] = {0};
	
	int characters, j, k;
	unsigned int i, count, countpaths;
	size_t size;
	pid_t process_id;
	
	if (isatty(STDIN_FILENO) == 1)
	{
		printf("this is a terminal");
		return (0);
	}
	
	PATH = getenv("PATH");
	
	
	
	countpaths = count_args(PATH, ':');
	
	paths = calloc((countpaths + 1), sizeof(char *));
	break_string(PATH, ":", paths);
	


		
	size = 32;
	
	buffer = malloc(sizeof(char) * size);
	
	printf("$ ");

	characters = getline(&buffer, &size, stdin);
	
	if (characters == -1)
	{
		printf("\n");
		return (0);
	}
	
	count = count_args(buffer, ' ');
	
	ptr = calloc((count + 1), sizeof(char *));

	break_string(buffer, " ", ptr);
	if (strcmp(ptr[0], "exit") == 0)
	{
		free(buffer);
	
		i = 0;
		while (ptr[i] != NULL)
		{
			free(ptr[i]);
			++i;
		}
		free(ptr);
		i = 0;
		while (paths[i] != NULL)
		{
			free(paths[i]);
			++i;
		}
		free(paths);
		return (0);
	}
	
	process_id = fork();
	
	if (process_id == 0)
	{
		if (access(ptr[0], X_OK) == 0)
		{
		execve(ptr[0], ptr, env);
		} else
		{
			j = 0;
			while (paths[j] != NULL)
			{
				strcat(buffer_path, paths[j]);
				strcat(buffer_path, "/");
				strcat(buffer_path, ptr[0]);
				
				if (access(buffer_path, X_OK) == 0)
				{
					execve(buffer_path, ptr, env);
				}
				else
				{
					for(k = 0; k < 1024; k++)
						buffer_path[k] = 0;
				}
				++j;
			}
			printf("%s: 1: %s: not found\n", av[0], ptr[0]);
		}
		free(buffer);
	
		i = 0;
		while (ptr[i] != NULL)
		{
			free(ptr[i]);
			++i;
		}
		free(ptr);
		i = 0;
		while (paths[i] != NULL)
		{
			free(paths[i]);
			++i;
		}
		free(paths);
		
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
		i = 0;
		while (paths[i] != NULL)
		{
			free(paths[i]);
			++i;
		}
		free(paths);
		main(ac, av, env);
	}
	
	
	return (0);
	
}
