#ifndef WORDS_H
#define WORDS_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Word {
    char * letters;
    struct Word * next;
    struct Word * prev;
} Word;

Word* create_words(char * letters, size_t len);
void append_word(Word ** head, Word ** tail, char * letters, size_t len);
void read_words(Word ** head, Word ** tail);
void show_words(Word * head);
void free_words(Word * head);
void change_words(Word ** res_head, Word ** res_tail, Word * head);

#endif // WORDS_H