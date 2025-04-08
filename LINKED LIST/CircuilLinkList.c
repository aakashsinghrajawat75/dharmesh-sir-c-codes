#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the circular linked list
struct Node { 
    int data; 
    struct Node *next; 
};

struct Node *START = NULL;

// Function to create a new node 
struct Node* getNewNode(int value) { 
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node)); 
    if (newNode == NULL) { 
        printf("Memory Overflow\n"); 
        return NULL; 
    } 
    newNode->data = value; 
    newNode->next = NULL; 
    return newNode; 
}

// Function to insert at the beginning 
void insertAtBeginning(int value) { 
    struct Node *newNode = getNewNode(value); 
    if (newNode == NULL) 
    return;

    if (START == NULL) {
        START = newNode;
        newNode->next = START;
    } else {
        struct Node *ptr = START;
        while (ptr->next != START) {
            ptr = ptr->next;
        }
        newNode->next = START;
        ptr->next = newNode;
        START = newNode;
    }
}

// Function to insert at the end 
void insertAtEnd(int value) { 
    struct Node *newNode = getNewNode(value); 
    if (newNode == NULL) return;

    if (START == NULL) {
        START = newNode;
        newNode->next = START;
    } else {
        struct Node *ptr = START;
        while (ptr->next != START) {
            ptr = ptr->next;
        }
        ptr->next = newNode;
        newNode->next = START;
    }
}

// Function to insert at a specific position (middle)
void insertAtMid(int value, int position) { 
    struct Node *newNode = getNewNode(value); 
    if (newNode == NULL) 
    return;

    if (START == NULL || position == 1) { // If list is empty or position = 1, insert at beginning
        insertAtBeginning(value);
        return;
    }

    struct Node *ptr = START;
    int count = 1;

    while (count < position - 1 && ptr->next != START) {
        ptr = ptr->next;
        count++;
    }

    newNode->next = ptr->next;
    ptr->next = newNode;
}

// Function to delete from the beginning
void deleteFromBeginning() {
    if (START == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return;
    }

    struct Node *ptr = START, *temp = START;

    if (START->next == START) { // If only one node
        START = NULL;
    } else {
        while (ptr->next != START) {
            ptr = ptr->next;
        }
        START = START->next;
        ptr->next = START;
    }
    
    free(temp);
    printf("Deleted from beginning.\n");
}

// Function to delete from the end
void deleteFromEnd() {
    if (START == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return;
    }

    struct Node *ptr = START, *prev = NULL;

    if (START->next == START) { // If only one node
        free(START);
        START = NULL;
    } else {
        while (ptr->next != START) {
            prev = ptr;
            ptr = ptr->next;
        }
        prev->next = START;
        free(ptr);
    }
    
    printf("Deleted from end.\n");
}

// Function to delete from a specific position (middle)
void deleteFromMid(int position) {
    if (START == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return;
    }

    struct Node *ptr = START, *prev = NULL;
    int count = 1;

    if (position == 1) { // If first position, call deleteFromBeginning
        deleteFromBeginning();
        return;
    }

    while (count < position && ptr->next != START) {
        prev = ptr;
        ptr = ptr->next;
        count++;
    }

    if (ptr == START) {
        printf("Invalid position!\n");
        return;
    }

    prev->next = ptr->next;
    free(ptr);
    printf("Deleted from position %d.\n", position);
}

// Function to display the circular linked list 
void display() { 
    if (START == NULL) { 
        printf("List is empty\n"); 
        return; 
    } 
    struct Node *ptr = START; 
    printf("Circular Linked List: ");
    do { 
        printf("%d -> ", ptr->data); 
        ptr = ptr->next; 
    } while (ptr != START); 
    printf("(START)\n"); 
}

int main() { 
    int choice, value, position;
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Middle\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Middle\n");
        printf("7. Display List\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 3:
                printf("Enter value to insert at middle: ");
                scanf("%d", &value);
                printf("Enter position: ");
                scanf("%d", &position);
                insertAtMid(value, position);
                break;
            case 4:
                deleteFromBeginning();
                break;
            case 5:
                deleteFromEnd();
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteFromMid(position);
                break;
            case 7:
                display();
                break;
            case 8:
                printf("Exiting bro! \n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
