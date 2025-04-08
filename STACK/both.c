#include <stdio.h>
#include <stdlib.h>
#define MAX 7     // size

int stack[MAX], top = -1; // -1 means stack is empty

// Define structure for linked list node
struct node {
    int info;
    struct node* link;
};

// Global pointer to the first node of the linked list
struct node* first = NULL;

// Function to create a linked list
void create() {
    struct node *ptr, *cpt;
    char ch;

    // Allocate memory for the first node
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
}

// Function to push an element into the stack
void push() {
    int value;
    if (top == MAX - 1) {   
        printf("Stack overflow\n");
    } else {
        printf("Enter value to push: ");
        scanf("%d", &value);
        top++;
        stack[top] = value;
        printf("%d pushed into the stack.\n", value);
    }
}

// Function to pop an element from the stack
void pop() {
    if (top == -1) {
        printf("Stack underflow! No element to pop.\n");
    } else {
        printf("%d popped from the stack.\n", stack[top]);
        top--;
    }
}

// Function to peep (look at) the top element of the stack
void peep() {
    if (top == -1) {
        printf("Stack is empty, nothing to peep.\n");
    } else {
        printf("Top element is %d\n", stack[top]);
    }
}

// Single display function for both stack and linked list
void displayAll() {
    // Display stack contents
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements (top to bottom): ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
    
    // Display linked list contents
    if (first == NULL) {
        printf("Linked list is empty.\n");
    } else {
        printf("Linked list: ");
        struct node* temp = first;
        while (temp != NULL) {
            printf("%d -> ", temp->info);
            temp = temp->link;
        }
        printf("NULL\n");
    }
}

// Main function
int main() {
    int choice;
    while (1) {
        printf("\nMenu:\n");
        printf(" 1. Push into stack\n");
        printf(" 2. Pop from stack\n");
        printf(" 3. Create linked list\n");
        printf(" 4. Peep top of stack\n");
        printf(" 5. Display (stack & linked list)\n");
        printf(" 6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                create();
                break;
            case 4:
                peep();
                break;
            case 5:
                displayAll();
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("\nOops! Wrong choice; enter a valid choice.\n");
        }
    }
    return 0;
}
