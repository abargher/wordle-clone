#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <termios.h>
#include <unistd.h>
#include <ctype.h>
#include "wordle.h"

/* Psuedo code sketch of main gameplay loop: */

    // int tries = 0;
    // bool solved = false;
    // while (tries < 6) {
    //     display_board();
    //     accept_input();
    //     update_board();
    //     if (solved) {
    //         win_game();
    //     } 
    //     tries++;
    // }
    // return 0;

/* Return whether or not the given string contains only letters. For safety,
will only evaluate at most len characters. */
bool is_word(char *str, int len)
{
    for (int i = 0; i < len; i++) {
        if (str[i] == '\0' || str[i] == '\n') {
           break; 
        } else if (!isalpha(str[i])) {
            return false;
        }
    }
    return true;
}

void lowercase(char *str)
{
    int len = strlen(str);
    for (int i = 0; i < len; i++)
        str[i] = tolower(str[i]);
    return;
}

char *get_next_word(char *out_word)
{
    char input_buf[6] = {0};
    fgets(input_buf, 6, stdin);
    lowercase(input_buf);
    snprintf(out_word, 6, "%s", input_buf);
    return out_word;
}

int main(int argc, char *argv[])
{
    int tries = 0;
    char *word_in = (char *)calloc(6, sizeof(char));
    while (tries < 6) {
        get_next_word(word_in);
        fprintf(stderr, "your input was %s, which is%s a word.\n", word_in, is_word(word_in, 5) ? "" : " not");
        tries++;
        memset(word_in, 0, 6);
    }

}