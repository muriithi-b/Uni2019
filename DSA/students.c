
#include <stdio.h>
#include <stdlib.h>
#include "studentListOps.h"

int main() {
    printf("Let\'s see...\n");
    studentNode *head = NULL;
    int safe_word = 0;

    //the first fgets in newStudentInput to read the name encounters
    //a newline. This simply clears stream for a good read for now.
    char *pit = (char*) malloc(sizeof(char) * 100);
    
    do {
        appendStudent(&head, newStudentInput());
        printf("\n\tNumber of nodes so far: %d", getSize(head));
        printf("\nEnter any number to continue or -1 to stop: ");
        scanf("%d", &safe_word);
        fgets(pit, 100, stdin);
    } while (safe_word != -1);
    
    printList(head);
    free(pit);
    destroyList(head);
    return 0;
}