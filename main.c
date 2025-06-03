#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "words.h"

int main() {
    int t = read_int("Enter the subtask number (1 or 2): ");

    if (t == 1) {
        Polynomial* poly1 = NULL;
        Polynomial* poly2 = NULL;
        
        // Ввод первого полинома
        printf("=== Polynomial 1 ===\n");
        int n1 = read_int("Enter the number of terms in polynomial 1: ");
        
        for (int i = 0; i < n1; i++) {
            printf("Term %d:\n", i+1);
            int coeff = read_int("  Coefficient: ");
            int power = read_int("  Power: ");
            
            if (coeff != 0) {
                poly1 = add(poly1, coeff, power);
            }
        }
        
        // Ввод второго полинома
        printf("\n=== Polynomial 2 ===\n");
        int n2 = read_int("Enter the number of terms in polynomial 2: ");
        
        for (int i = 0; i < n2; i++) {
            printf("Term %d:\n", i+1);
            int coeff = read_int("  Coefficient: ");
            int power = read_int("  Power: ");
            
            if (coeff != 0) {
                poly2 = add(poly2, coeff, power);
            }
        }
        
        Polynomial* res = unite(poly1, poly2);
        // Вывод результатов
        printf("\nResult:\n");
        printf("Polynomial 1: "); show(poly1); printf("\n");
        printf("Polynomial 2: "); show(poly2); printf("\n");
        printf("Polynomial united: "); show(res); printf("\n");
        // Очистка памяти
        free_polynomial(poly1);
        free_polynomial(poly2);
        free_polynomial(res);
    } else if (t == 2) {
        Word *head = NULL;
        Word *tail = NULL;
        Word *res_head = NULL;
        Word *res_tail = NULL;

        read_words(&head, &tail);
        printf("Your list: \n");
        show_words(head);

        change_words(&res_head, &res_tail, head);
        printf("\nRes list: \n");
        show_words(res_head);

        free_words(head);
        free_words(res_head);
    } else {
        printf("Error! Unknown parameter!\n");
    }
    return 0;
}