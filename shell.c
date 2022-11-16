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
}
}
}
