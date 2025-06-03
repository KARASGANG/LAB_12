#include "struct.h"

Polynomial* create(int data, int num) {
    Polynomial* p = (Polynomial*)malloc(sizeof(Polynomial));
    if (!p) return NULL;
    p->data = data;
    p->num = num;
    p->next = NULL;
    return p;
}

Polynomial* add(Polynomial* head, int data, int num) {
    Polynomial* new_node = create(data, num);

    if (!new_node) return NULL;

    if (!head) return new_node;

    if (head->num < new_node->num) {
        new_node->next = head;
        return new_node;
    }

    Polynomial* current = head;
    while (current->next && (current->next->num >= new_node->num)) {
        current = current->next;
    }
    if (current->num == num){
        current->data += data;
        return head;
    }
    new_node->next = current->next;
    current->next = new_node;
    return head;
}

void show(Polynomial* head) {
    if (!head) {
        printf("0");
        return;
    }
    
    Polynomial* current = head;
    while (current) {
        if (current->data != 0){
        if (current->num == 1) {
            if (current->data == 1)
                printf("x");
            else printf("%dx", current->data);
        }
        if (current->num == 0) {printf("%d", current->data);}
        if (current->num != 0 && current->num != 1) {printf("%dx^%d", current->data, current->num);}

        if (current->next && current->next->data!=0) printf(" + ");}
        current = current->next;
    }
}

void free_polynomial(Polynomial* head) {
    while (head) {
        Polynomial* temp = head;
        head = head->next;
        free(temp);
    }
}

int read_int(const char* prompt) {
    int value;
    char buffer[100];
    
    while (1) {
        printf("%s", prompt);
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("Input error!\n");
            continue;
        }
        
        if (sscanf(buffer, "%d", &value) == 1) {
            return value;
        }
        
        printf("Invalid input. Please enter an integer.\n");
    }
}

// Функция для проверки наличия степени в другом многочлене
int degree_exists(Polynomial* poly, int degree) {
    while (poly) {
        if (poly->num == degree) return 1;
        poly = poly->next;
    }
    return 0;
}

int find_degree(Polynomial * p, int i) {
    while (p){
        if (p->num == i) return p->data;
        p = p->next;
    }
    return 0;
}


Polynomial * unite(Polynomial * head1, Polynomial * head2) {
    Polynomial * res = NULL;

    int max1, max2, max, x1, x2, y1, y2;
    max1 = head1->num;
    max2 = head2->num;

    for (int i=0; i <= (max1 > max2 ? max1 : max2); ++i){
        x1 = degree_exists(head1, i);
        x2 = degree_exists(head2, i);
        if (x1 && x2) {
            y1 = find_degree(head1, i);
            y2 = find_degree(head2, i);
            res = add(res, (y1 > y2 ? y1 : y2), i);
        }
    }
    return res;
}