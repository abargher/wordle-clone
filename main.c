#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <termios.h>
#include <unistd.h>
#include <ctype.h>
#include "wordle.h"

    // static struct termios oldt, newt;
    // int c;
    // /*tcgetattr gets the parameters of the current terminal
    // STDIN_FILENO will tell tcgetattr that it should write the settings
    // of stdin to oldt*/
    // tcgetattr(STDIN_FILENO, &oldt);
    // /*now the settings will be copied*/
    // newt = oldt;

    // /*ICANON normally takes care that one line at a time will be processed
    // that means it will return if it sees a "\n" or an EOF or an EOL*/
    // newt.c_lflag &= ~(ICANON);          

    // /*Those new settings will be set to STDIN
    // TCSANOW tells tcsetattr to change attributes immediately. */
    // tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    // /*This is your part:
    // I choose 'e' to end input. Notice that EOF is also turned off
    // in the non-canonical mode*/
    // while((c=getchar())!= 'e')      
    //     printf("0x%x\n",c);
    //     // putchar(c);                 

    // /*restore the old settings*/
    // tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

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

int main (int argc, char *argv[])
{
    int tries = 0;
    char *word_in = (char *)calloc(6, sizeof(char));
    while (tries < 6) {
        char input_buf[256] = {0};
        fgets(input_buf, 256, stdin);
        destroy_trailing_newline(input_buf);
        printf("inputted: %s\n", input_buf);
        snprintf(word_in, 6, "%s", input_buf);
        printf("your input was %s, which is%s a word.\n", word_in, is_word(word_in, 5) ? "" : " not");
        tries++;
        memset(word_in, 0, 6);
    }
    

}