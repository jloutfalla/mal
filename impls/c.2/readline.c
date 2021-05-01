#include "readline.h"

#include <stdlib.h>
#include "base.h"

char *
readline(FILE *f)
{
  size_t bytes = 0, capacity = 0;
  char c, *str = NULL;

  while ((c = fgetc(f)) != EOF && c != '\n' && c != '\r')
    {
      bytes++;
      if ((bytes + 1) >= capacity)
        {
          capacity = bytes * 2 + 1;
          REALLOC(str, capacity);
        }
      str[bytes - 1] = c;
    }

  if (c == '\r')
    {
      if ((c = fgetc(f)) != '\n')
        ungetc(c, f);
    }
  else if (str == NULL)
    {
      if (c == EOF)
        return NULL;

      MALLOC(str, 1);
    }

  str[bytes] = '\0';
  
  return str;
}
