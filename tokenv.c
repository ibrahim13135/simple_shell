#include "shell.h"
/**
* toknizer - splits a string into tokens
* @or: the original string
* @r: the number of tokens
* Return: an array of tokens
*/
char **toknizer(char *or, int *r)
{
	char *wotok = NULL, *orcpy = NULL;
	char **orwo = NULL;
	int number = 0, i = 0;

	if (!or)
	{
		return (NULL);
	}
	orcpy = strdup(or);
	wotok = strtok(orcpy, " \n");
	if (!wotok)
	{
		free(or);
		or = NULL;
		free(orcpy);
		orcpy = NULL;
		return (NULL);
	} while (wotok)
	{
		number++;
		wotok = strtok(NULL, " \n");
	} free(orcpy);
	orcpy = NULL;
	*r = number;
	orwo = malloc(sizeof(char *) * (number + 1));
	if (!orwo)
	{
		free(orwo);
		or = NULL;
		return (NULL);
	} wotok = strtok(or, " \n");
	while (wotok)
	{
		orwo[i] = strdup(wotok);
		wotok = strtok(NULL, " \n");
		i++;
	} free(or);
	or = NULL;
	orwo[i] = NULL;
	return (orwo);
	}

/**
 * genv - gets the value of an environ variable
* @variable: Structure containing potential arguments. Used to maintain
* @env: env var name
*
* Return: the value
*/
char *genv(char *variable, char **env)
{
	char *vart, *vark, *varv, *enve;
	int lol;

	for (lol = 0; env[lol]; lol++)
	{
		vart = strdup(env[lol]);
		vark = strtok(vart, "=");
		if (strcmp(vark, variable) == 0)
		{
		varv = strtok(NULL, "\n");
		enve = strdup(varv);
		free(vart);
		vart = NULL;
		return (enve);
		}
		free(vart);
		vart = NULL;
	}
	return (NULL);
	}
