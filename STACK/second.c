#include <stdio.h>
#include <stdlib.h>

// Define structure for node
struct node {
    int info;
    struct node* link;
};

// Global pointer to the first node
struct node* first = NULL;

// Function to create a linked list
void create() {
    struct node *ptr, *cpt;
    char ch;

    // Allocating memory for the first node
    ptr = (struct node*)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Input first node information: ");
    scanf("%d", &ptr->info);
    ptr->link = NULL;
    first = ptr;

    do {
        cpt = (struct node*)malloc(sizeof(struct node));
        if (cpt == NULL) {
            printf("Memory allocation failed\n");
            return;
        }

        printf("Input next node information: ");
        scanf("%d", &cpt->info);
        cpt->link = NULL;
        ptr->link = cpt;
        ptr = cpt;  // Move pointer to the new last node

        printf("Press <Y/N> for more nodes: ");
        scanf(" %c", &ch);
    } while (ch == 'Y' || ch == 'y');

    ptr->link = NULL; // Last node points to NULL
}

// Function to display the linked list
void display() {
    struct node* temp = first;

    if (temp == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->info);
        temp = temp->link;
    }
    printf("NULL\n");
}

// Main function
int main() {
    create();
    display();

    return 0;
}