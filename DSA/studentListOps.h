
/*Definitions of types and functions that can be used in
   a singly linked list of students
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SN studentNode*
#define NAMESIZE 50
#define REGNOSIZE 30

typedef struct Student {
    char *name;
    int age;
    char *regNo;
    struct Student* next;
} studentNode;

studentNode *newStudentInput() {
    studentNode* node = (SN) malloc(sizeof(studentNode));
    node->name = (char *) malloc(sizeof(char) * NAMESIZE);
    node->regNo = (char *) malloc(sizeof(char) * REGNOSIZE);
    node->next = NULL;

    printf("Enter new student name: ");
    fgets(node->name, NAMESIZE, stdin);
    printf("\nEnter student reg No: ");
    fgets(node->regNo, REGNOSIZE, stdin);
    printf("\nEnter student age: ");
    scanf("%d", &node->age);

    return node;
}

bool appendStudent(studentNode** head, studentNode* node) {
    if(*head == NULL) {
        *head = node;
        return true;
    }
    studentNode* current = *head;
    while(current->next != NULL) {
        current = current->next;
    }
    current->next = node;
    current->next->next = NULL;
    return true;
}

bool insertFront(studentNode** head, studentNode* node) {
    studentNode* temp = *head;
    *head = node;
    (*head)->next = temp;
    return true;
}

void popFirst(studentNode** head) {
    if(*head == NULL) return;

    studentNode* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void removeLast(studentNode** head) {
    if((*head)->next == NULL) {
        free(*head);
        *head = NULL;
    }
    studentNode* current = *head;
    while(current->next->next != NULL) {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
}

int getSize(studentNode* head) {
    int i = 0;
    for(; head != NULL; i++) {
        head = head->next;
    }
    return i;
}

void printList(studentNode* head) {
    printf("=====================================================\n");
    for(;head != NULL; head = head->next) {
        printf("***************************************\n");
        printf("Name: %s\n", head->name);
        printf("Reg. No: %s \nAge: %d\n", head->regNo, head->age);
    }
    printf("=====================================================\n");
}

void destroyList(studentNode* head) {
    if(head == NULL) return;
    studentNode* current = head;
    studentNode* fwd = current->next;
    while(fwd != NULL) {
        free(current);
        current = fwd;
        fwd = fwd->next;
    }
    free(current);
}