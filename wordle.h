/* Wordle clone header file */
#ifndef _WORDLE_H_
#define _WORDLE_H_

#include <stdlib.h>

typedef enum letter_state {GRAY, YELLOW, GREEN} let_state_t;

typedef struct cell {
    char letter;
    let_state_t state;
} cell_t;

typedef struct word {
    cell_t *letters;
} word_t;

typedef struct board {
    word_t words[6];
    bool solved;
    char secret_word[6] // string of length 5
} board_t;


#endif // _WORDLE_H_