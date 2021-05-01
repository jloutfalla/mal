#ifndef BASE_H
#define BASE_H

#include <stdio.h>
#include <stdlib.h>

#define MALLOC(X, NB)                                           \
  do                                                            \
    {                                                           \
      if ((X = malloc(sizeof(*(X)) * (NB))) == NULL)            \
        {                                                       \
          fputs("ERROR: Can't allocate memory.\n", stderr);     \
          exit(EXIT_FAILURE);                                   \
        }                                                       \
    } while (0)

#define REALLOC(X, NB)                                          \
    do                                                          \
      {                                                         \
        if ((X = realloc((X), sizeof(*(X)) * (NB))) == NULL)    \
          {                                                     \
            fputs("ERROR: Can't allocate memory.\n", stderr);   \
            exit(EXIT_FAILURE);                                 \
          }                                                     \
      } while (0)

#endif /* BASE_H */
