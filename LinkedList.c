#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    struct node *next;
    int key;
} Node;

extern Node *head, *tail;

int isEmpty() {
    return head == NULL;
}

void print(char *buffer, int *buffer_index) {
    // print all contents of list
    Node *temp_node = head;
    while(temp_node) {
        *buffer_index += sprintf(buffer + *buffer_index, "%d ", temp_node->key);
        temp_node = temp_node->next;
    }
    *buffer_index += sprintf(buffer + *buffer_index, "\n");
}

int get(int index) {
    // TODO

}

void append(int key) {
    // TODO

}

void insert(int key, int index) {
    // TODO

}

void clear() {
    Node *temp_node = head, *prev_node;
    while(temp_node) {
        prev_node = temp_node;
        temp_node = temp_node->next;
        free(prev_node);
    }
    head = tail = NULL;
}

void delete(int index) {
    // TODO
    
}
