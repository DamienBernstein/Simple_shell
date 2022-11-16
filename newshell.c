#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>

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



int main(int ac, char **av, char **env)
{
	char *buffer, **ptr, *PATH, **paths, buffer_path[1024];
	
	int characters, j;
	unsigned int args, i, count, countpaths;
	size_t size;
	pid_t process_id;
	
	PATH = getenv("PATH");
	
	
	
	countpaths = count_args(PATH, ':');
	
	paths = calloc((countpaths + 1), sizeof(char *));
	break_string(PATH, ":", paths);
	


		
	size = 32;
	
	buffer = malloc(sizeof(char) * size);
	
	printf("$ ");

	characters = getline(&buffer, &size, stdin);
	
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
				buffer_path = path[j] + '/' + ptr[0];
				if (access(buffer_path, X_OK) == 0)
					execve(buffer, ptr, env);
				++j;
			}
			printf("function not found");
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
