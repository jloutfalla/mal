#include <stdio.h>
#include <stdlib.h>

#include "repl.h"

int
main(int argc, char *argv[])
{
  (void)sizeof(argc); /* Warning */
  (void)sizeof(*argv); /* Warning */
  
  char prompt[100];
  char *ast, *expr;

  snprintf(prompt, sizeof(prompt), "user> ");

  while (1)
    {
      ast = READ(stdin, prompt);
      if (ast == NULL)
        return 0;
      
      expr = EVAL(ast, NULL);
      puts(PRINT(expr));

      free(ast);
    }
  
  return 0;
}
