#include "repl.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readline.h"

char *
READ(FILE *f, char *prompt)
{  
  char *str = NULL;

  if (prompt != NULL)
    fputs(prompt, stdout);
  
  str = readline(f);
  
  return str;
}

char *
EVAL(char *ast, void *env)
{
  (void)sizeof(env); /* Warning */
  return ast;
}

char *
PRINT(char *expr)
{
  return expr;
}
