/* Wordle clone header file */
#ifndef _WORDLE_H_
#define _WORDLE_H_

#include <stdlib.h>
#include <stdbool.h>

enum letter_state {GRAY, YELLOW, GREEN};
typedef enum letter_state let_state_t;

struct cell {
    char letter;
    let_state_t state;
};
typedef struct cell cell_t;

struct word {
    cell_t *letters;
};
typedef struct word word_t;

struct board {
    word_t words[6];
    bool solved;
    char secret_word[6]; // string of length 5
};
typedef struct board board_t;


#endif // _WORDLE_H_