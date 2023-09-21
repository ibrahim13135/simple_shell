#include "shell.h"
/**
 * ph - finds the full path of a command
 * @or: the original command
 * @env: the environment variables
 * Return: the full path of the command or NULL if not found
 */
char *ph(char *or, char **env)
{
	char *pe, *cmd, *dir;
	int i;
	struct stat buf;

	for (i = 0; or[i]; i++)
	{
	if (or[i] == '/')
	{
		if (stat(or, &buf) == 0)
		{
			return (strdup(or));
		}
		return (NULL);
	}
	}
	pe = genv("PATH", env);
	if (!pe)
		return (NULL);
		dir = strtok(pe, ":");
	while (dir)
	{
	cmd = malloc(strlen(dir) + strlen(or) + 2);
	strcpy(cmd, dir);
	strcat(cmd, "/");
	strcat(cmd, or);
	if (stat(cmd, &buf) == 0 && S_ISREG(buf.st_mode) && (buf.st_mode & S_IXUSR))
	{
		free(pe);
		return (strdup(cmd));
	}
	if (stat(cmd, &buf) == 0)
	{
		free(pe);
		return (cmd);
	} free(cmd);
	cmd = NULL;
	dir = strtok(NULL, ":");
	} free(pe);
	pe = NULL;
	return (NULL);
}
/**
 * readline - reads a line from the standard input
 * Return: the line read or NULL if error or EOF
 */
char *readline(void)
{
	char *wo = NULL;
	size_t n = BUFSIZ;
	ssize_t len;

	if (isatty(STDOUT_FILENO))
	{
		fflush(STDIN_FILENO);
		write(STDOUT_FILENO, "$ ", 2);
	}
	len = getline(&wo, &n, stdin);
	if (len == -1)
	{
		free(wo);
		wo = NULL;
		return (NULL);
	}
	wo[len - 1] = '\0';
	return (wo);
}
/**
 * _execve - executes a command
 * @orwo: the array of tokens
 * @l: the number of tokens
 * @av: the program name
 * @env: the environment variables
 * @status1: the previous exit status
 * Return: 0 on success, 127 on failure
 */
int _execve(char **orwo, int l, char **av, char **env, int status1)
{
	char *cmd;
	pid_t mypid;
	int status2;

	if (strcmp(orwo[0], "exit") == 0)
	{
	char *b;
	int x = 0;

	if (l >= 2)
	{
		b = strdup(orwo[1]);
		x = atoi(b);
		free(b);
		b = NULL;
	} else if (status1 > 1)
		x = status1;

	freear(orwo);
	exit(x);
	} cmd = ph(orwo[0], environ);
	if (!cmd)
	{
	fckerrors(av[0], orwo[0], status1);
	free(orwo);
	return (127);
	} mypid = fork();
	if (mypid == 0)
	{
	if (execve(cmd, orwo, env) == -1)
		free(cmd);
		cmd = NULL;
		freear(orwo);
	} else
	{
	waitpid(mypid, &status2, 0);
	freear(orwo);
	free(cmd);
	cmd = NULL;
	} return (0);
}
