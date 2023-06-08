#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wordle.h"

/* Wordle clone function definitions */



/* Replaces last instance of a newline character (\n) with a null terminator. */
void destroy_trailing_newline(char *str)
{
    int len = strlen(str);
    for (int i = len - 1; i >= 0; i--) {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
    }
    return;
}


