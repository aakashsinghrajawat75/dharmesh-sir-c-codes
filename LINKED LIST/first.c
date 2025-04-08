#include <stdio.h>
#include <stdlib.h>

// Define a structure for a queue node
struct Node
{
    int data;
    struct Node *next;
};

// Define front and rear pointers
struct Node *front = NULL;
struct Node *rear = NULL;

// Function to enqueue an element
void enqueue()
{
    int value;
    printf("Enter value to enqueue: ");
    scanf("%d", &value);
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed. Queue overflow!\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL)
    { // If queue is empty
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
    printf("%d enqueued successfully.\n", value);
}

// Function to dequeue an element
void dequeue()
{
    if (front == NULL)
    {
        printf("Queue underflow! No elements to dequeue.\n");
        return;
    }

    struct Node *temp = front;
    front = front->next;

    if (front == NULL)
    { // If queue becomes empty
        rear = NULL;
    }

    printf("%d dequeued successfully.\n", temp->data);
    free(temp);
}

// Function to display the queue
void display()
{
    if (front == NULL)
    {
        printf("Queue is empty.\n");
        return;
    }

    struct Node *temp = front;
    printf("Queue elements: ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function with switch-case menu
int main()
{
    int choice ;

    while (1)
    {
        printf("\nQueue using Linked List (Menu):\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting program...\n");
            return 0;
        default:
            printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}