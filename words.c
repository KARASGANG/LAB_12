#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "words.h"

Word * create_words(char * letters, size_t len)
{
    Word * word = (Word *)malloc(sizeof(Word));
    if (!word){
        fprintf(stderr, "Error allocating memory for Word\n");
        exit(EXIT_FAILURE);
    }
    word->letters = (char*)malloc(len + 1);
    if (!word->letters) {
        free(word);
        fprintf(stderr, "Error allocating memory for letters\n");
        return NULL;
    }
    
    word -> next = NULL;
    word -> prev = NULL;
    strncpy(word->letters, letters, len);
    word->letters[len] = '\0';
    return word;
}

void append_word(Word ** head, Word ** tail, char * letters, size_t len)
{
    Word * new = create_words(letters, len);
    if (!new) {
        fprintf(stderr, "Failed to create new word\n");
        return;
    }
    if (!(*head))
    {
        *head = new;
        *tail = new;
        return;
    }
    (*tail) -> next = new;
    new -> prev = (*tail);
    (*tail) = new;
}

void read_words(Word ** head, Word ** tail)
{
    printf("Enter a sentence, must end with a '.' \n");
    char buf[256];
    while (scanf("%255s", buf) == 1) {
        // Remove dots
        size_t len = strlen(buf);
        char *dot_pos = strchr(buf, '.');
        
        if (dot_pos) {
            // Handle the case where '.' is in the word
            *dot_pos = '\0';
            len = dot_pos - buf;
            
            if (len > 0) {
                append_word(head, tail, buf, len);
            }
            break;
        }
        append_word(head, tail, buf, len);
    }

}


void show_words(Word * word)
{
    while (word)
    {
        printf("%s ", word->letters);
        word = word ->next;
    }
    printf("\n");
}

void free_words(Word * head)
{
    while (head)
    {
        Word * temp = head;
        head = head -> next;
        free(temp -> letters);
        free(temp);

    }
}

void change_words(Word ** res_head, Word ** res_tail, Word * head)
{
    Word * tmp = head;
    char* best_word, *cur_word;
    int i = 0, best_i = 0;
    while (tmp) {
        cur_word = tmp->letters;
        if (i == 0) {
            best_word = cur_word;
        }
        int t = strcmp(best_word, cur_word);
        if (t > 0) {
            best_word = cur_word;
            best_i = i;
        }
        i++;
        tmp = tmp->next;
    }
    tmp = head;
    for (int i = 0; i < strlen(best_word) / 2; i++) {
        char t = best_word[i];
        best_word[i] = best_word[strlen(best_word) - 1 - i];
        best_word[strlen(best_word) - 1 - i] = t;
    }
    int j = 0;
    while (tmp) {
        if (j == best_i) {
            append_word(res_head, res_tail, best_word, strlen(best_word));
            for (int i = 0; i < strlen(best_word) / 2; i++) {
                char t = best_word[i];
                best_word[i] = best_word[strlen(best_word) - 1 - i];
                best_word[strlen(best_word) - 1 - i] = t;
            }
        }
        append_word(res_head, res_tail, tmp->letters, strlen(tmp->letters));
        j++;
        tmp = tmp->next;
    }
}