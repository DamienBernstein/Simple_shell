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
 * @delimeter: indicates beginning or end of string
 * Return: numbers of arguements
 */
unsigned int count_args(char *str, char *delimeter)
{
unsigned int count;
char *buffer;
char *token;

buffer = malloc(sizeof(str));
strcpy(buffer, str);
count = 0;
token = strtok(buffer, delimeter);

while (token != NULL)
{
++count;
token = strtok(NULL, " ");
}
free(buffer);
return (count + 1);
}

/**
 * break_string - breaks a string
 * @str: string
 * @delimeter: indicates beginning or end of string
 * @ptr: points to a string
 * Return: a broken string
 */
void break_string(char *str, char *delimeter, char **ptr)
{
char *token, *str2;
int i, j;

i = 0;
j = 0;
str2 = malloc(sizeof(char) * (strlen(str) - 1));
while (str[j] != '\n' && str[j] != '\0')
{
str2[j] = str[j];
++j;
}
token = strtok(str2, delimeter);
while (token != NULL)
{
ptr[i] = malloc(sizeof(char) * strlen(token));
strcpy(ptr[i], token);
token = strtok(NULL, delimeter);
++i;
}
free(str2);
free(ptr[i]);
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
char *buffer, **str, *path, *oldpath, **str2;
size_t size;
int j, status, exists, pathtrue, characters, slashcount;
unsigned int count;
pid_t child_pid;

slashcount = 0, pathtrue = 0, j = 0;
size = 32;
oldpath = "/bin/";
buffer = malloc(sizeof(char) * size);

do  {
printf("$ ");
characters = getline(&buffer, &size, stdin);
if (characters == -1)
{
printf("\n");
return (0);
}
} while (characters == 1);

count = count_args(buffer, " ");
str = malloc(sizeof(char *) * count);
break_string(buffer, " ", str);
if (strcmp(str[0], "exit") == 0)
{
exit(0);
free(buffer);
free(str);
return (0);
}

while (str[0][j] != '\0')
{
if (str[0][j] == '/')
{
++slashcount;
pathtrue = 1;
}
++j;
}

if (pathtrue == 1)
{
str2  = malloc(sizeof(char *) * (slashcount + 2));
break_string(str[0], "/", str2);
exists = searchforfunction(str2[slashcount - 1], "/bin/");

if (exists == 1)
{
child_pid = fork();
if (child_pid == 0)
{
execve(str[0], str, env);
}
if (child_pid != 0)
{
wait(&status);
free(buffer);
free(str);
free(str2);
main(ac, av, env);
}
}
else
{
printf("%s: not found\n", str[0]);

if (child_pid == 0)
{
execve(str[0], str, env);
}




