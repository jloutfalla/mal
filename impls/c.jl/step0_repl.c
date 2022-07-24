#include <stdio.h>
#include <stdlib.h>

#include "repl.h"

int
main (int argc, char *argv[])
{
  (void)argc;  /* Warning */
  (void)*argv; /* Warning */

  char prompt[] = "user> ";
  char *ast, *expr;

  while (1)
    {
      ast = READ (stdin, prompt);
      if (ast == NULL)
        return 0;

      expr = EVAL (ast, NULL);
      puts (PRINT (expr));

      free (ast);
    }

  return 0;
}
