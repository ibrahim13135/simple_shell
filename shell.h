#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>

extern char **environ;

int buildincmds(char *or);

char **toknizer(char *or, int *r);
char *genv(char *variable, char **env);
char *ph(char *or, char **env);
char *readline(void);
int _execve(char **orwo, int l, char **av, char **env, int status1);
char *ph(char *or, char **env);
char *readline(void);
int _execve(char **orwo, int l, char **av, char **env, int status1);
char *_itoa(unsigned int n);
void arrayrev(char *s, int len);
int intlength(unsigned int n);
void freear(char **ar);
void fckerrors(char *fex, char *cmd, int num);

#endif
