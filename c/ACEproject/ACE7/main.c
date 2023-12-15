#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

// This function will test if the pointer p has been freed
int is_freed(void *p);

int main( void ) {
    List list = new_list();
    print_list(list);

    push(list, "One");
    print_list(list);

    // I will need this later to check for destruction of nodes
    void *test = &(**list);

    push(list, "Two");
    push(list, "Three");
    push(list, "Four");

    print_list(list);

    for (int i = 0 ; i < 6 ; i++) {
        printf("Popping %s\n", pop(list));
    }

    print_list(list);

    printf("Memory freed? %s\n", (is_freed(test)) ? "Yes! :)": "No! :(");

    return 0;
}

int is_freed(void *p) {
    void *q;
    char p_addr[50];
    char q_addr[50];
    sprintf(p_addr, "%p", p);
    q = malloc (1);
    sprintf(q_addr, "%p", q);
    free(q);
    return !strcmp(q_addr, p_addr);
}