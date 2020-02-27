
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int key;
    int data;
    struct node *next;
};

struct node *head = NULL;

void printList() {
    printf("\n[ ");
    for (struct node *ptr = head; ptr != NULL; ptr = ptr->next) {
        printf("(%d, %d)", ptr->key, ptr->data);
    }
}

void insertFirst(int key, int data) {
    struct node *link = (struct node *)malloc(sizeof(struct node));
    link->key = key;
    link->data = data;
    link->next = head;
    head = link;
}

struct node* deleteFirst() {
    struct node* copy = head;
    head = head->next;
    return copy;
}

bool isEmpty() {
    return head == NULL;
}

int length() {
    int counter = 0;
    for(struct node *ptr = head; ptr != NULL; ptr = ptr->next) {
        counter++;
    }
    return counter;
}

struct node* find(int key) {
    for (struct node *ptr = head; ptr != NULL; ptr = ptr->next) {
        if (ptr->key == key) {
            return ptr;
        }
    }
    return NULL;
}

struct node *deleteNode(int key) {
    if (head->key == key) {
        return deleteFirst();
    }
    struct node* current = head->next;
    struct node* previous = head;
    for (;current != NULL;) {
        if (current->key == key) {
            previous->next = current->next;
        }
        previous = current;
        current = current->next;
    }
}