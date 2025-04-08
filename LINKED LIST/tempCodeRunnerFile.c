#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *link;
};

struct node *front = NULL;
struct node *rear = NULL;

void insert();
void delete();
void display();

int main() {
    int ch;
    while (1) {
        printf("1. for insert\n");
        printf("2. for delete\n");
        printf("3. for display\n");
        printf("4. exit this program\n");

        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}

void insert() {
    struct node *ptr = (struct node*) malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    printf("Enter the value of item: ");
    scanf("%d", &ptr->info);
    ptr->link = NULL;
    
    if (front == NULL) {
        front = ptr;
    } else {
        rear->link = ptr;
    }
    rear = ptr;
}

void delete() {
    struct node *ptr;
    if (front == NULL) {
        printf("Queue is underflow.\n");
        return;
    }
    ptr = front;
    front = front->link;
    free(ptr);

    if (front == NULL) { // If queue is empty after deletion
        rear = NULL;
    }
}

void display() {
    struct node *ptr = front;
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    
    printf("\nQueue elements are:\n");
    while (ptr != NULL) {
        printf("%d\n", ptr->info);
        ptr = ptr->link;
    }
    printf("\n");
}
