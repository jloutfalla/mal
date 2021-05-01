#ifndef REPL_H
#define REPL_H

#include <stdio.h>

char *READ(FILE *, char *);
char *EVAL(char *, void *);
char *PRINT(char *);

#endif /* REPL_H */
