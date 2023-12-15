#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

int is_freed(void *p);

int main( void ) {
    Node *root = new_node("First!");
    if (root->next == NULL) {
        printf("%s\n", root->value);
    }
    delete_node(root);
    printf("Memory freed: %d\n", is_freed(root));
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