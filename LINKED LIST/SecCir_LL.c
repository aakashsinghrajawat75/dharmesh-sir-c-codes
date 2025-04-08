#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the circular linked list
struct Node { 
    int data; 
    struct Node *next; 
};

struct Node *START = NULL;
struct Node *AVAIL = NULL;

// Function to create a new node 
struct Node* getNewNode(int value) { 
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node)); 
    if (newNode == NULL) { 
        printf("Overflow\n"); 
        return NULL; 
    } 
    newNode->data = value; 
    newNode->next = NULL; 
    return newNode; 
}

// Function to insert at the beginning of the circular linked list 
void insertAtBeginning(int value) { 
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
    newNode->next = START;
    ptr->next = newNode;
    START = newNode;
}

}

// Function to insert at the end of the circular linked list 
void insertAtEnd(int value) { 
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
    ptr->next = newNode;
    newNode->next = START;
}

}

// Function to display the circular linked list 
void display() { 
    if (START == NULL) { 
        printf("List is empty\n"); 
        return; 
    } 
    struct Node *ptr = START; 
    do { 
        printf("%d -> ", ptr->data); 
        ptr = ptr->next; 
    } while (ptr != START); printf("(START)\n"); 
}

int main() { 
    insertAtBeginning(3);
    insertAtBeginning(2);
    insertAtBeginning(1);
    insertAtEnd(4);
    insertAtEnd(5);
    display();


    return 0;
}