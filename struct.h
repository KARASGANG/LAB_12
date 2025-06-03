#ifndef STRUCT_H
#define STRUCT_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Polynomial {
    int num;
    int data;
    struct Polynomial * next;
}Polynomial;

Polynomial *create(int data, int num);
Polynomial *add(Polynomial * head, int data, int num);
void show(Polynomial * head);
void free_polynomial(Polynomial* head) ;
int read_int(const char* prompt);
int degree_exists(Polynomial* poly, int degree) ;
int find_degree(Polynomial * p, int i);
Polynomial *unite(Polynomial * head1, Polynomial * head2);

#endif // STRUCT_H