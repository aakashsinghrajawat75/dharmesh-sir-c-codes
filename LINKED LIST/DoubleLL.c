#include <stdio.h>
#include <stdlib.h>

// Structure for a Node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Head pointer for DLL
struct Node* head = NULL;

// Function to insert at the beginning
void insertAtBeginning(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
        head->prev = newNode;

    head = newNode;
}

// Function to delete from the beginning
void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    free(temp);
    printf("Node deleted from beginning.\n");
}

// Function to display the linked list
void display() {
    struct Node* temp = head;

    if (temp == NULL) {
        printf("List is empty!\n");
        return;
    }

    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    insertAtBeginning(10);
    insertAtBeginning(20);
    insertAtBeginning(30);
    
    display();  // Output: 30 <-> 20 <-> 10 <-> NULL

    deleteFromBeginning();
    
    display();  // Output: 20 <-> 10 <-> NULL

    return 0;
}
