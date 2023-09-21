#include "shell.h"
/**
 * buildincmds - executes a built-in command
 * @or: the command name
 * Return: 1 if the command is executed, 0 otherwise
 */
int buildincmds(char *or)
{
	int i = 0;

	if (strcmp(or, "env") == 0)
	{
		while (environ[i] != NULL)
		{
			if (i)
			{
				write(STDOUT_FILENO, "\n", 1);
			}
			write(STDOUT_FILENO, environ[i], strlen(environ[i]));
			i++;
		}
	return (1);
	}
	return (0);
}


/**
 * main - the main function of the shell
 * @ac: the number of arguments
 * @argv: the array of arguments
 * @env: the environment variables
 * Return: the exit status
 */
int main(int ac, char **argv, char **env)
{
	char *or = NULL;
	char **orwo = NULL;
	int status1 = 0, loop = 1, lol = 0, x, z;
	(void)ac;

	while (loop)
	{
	or = readline();
	if (!or)
	{
		if (isatty(STDOUT_FILENO))
		{
		fflush(STDIN_FILENO);
		write(STDOUT_FILENO, "\n", 1);
		}
		return (status1);
	}
	lol++;
	orwo = toknizer(or, &x);
	if (!orwo)
		continue;
	z = buildincmds(orwo[0]);
	if (z)
	{
		freear(orwo);
	}
	else
	{
		status1 = _execve(orwo, x, argv, env, lol);
	}
	}
	return (status1);
}
