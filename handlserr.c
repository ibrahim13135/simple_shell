#include "shell.h"
/**
 * fckerrors - prints an error message
 * @fex: the program name
 * @cmd: the command name
 * @num: the error number
 */
void fckerrors(char *fex, char *cmd, int num)
{
	char *flol = _itoa(num);

	write(STDERR_FILENO, fex, strlen(fex));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, flol, strlen(flol));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, strlen(cmd));
	write(STDERR_FILENO, ": not found\n", 12);
	free(flol);
}
