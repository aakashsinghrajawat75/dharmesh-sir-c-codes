#include<stdio.h>
#include<stdlib.h>
#define MAX 100

// global declare
int q[MAX+ 1], front=0, rear=0;

// global function
void create(); // create ques
void traverse();
void insert();
void delete();

// main function
int main() {
    create();
    traverse();
    insert();
    printf("\n after insert an element");
    delete();
    printf("\n after deletion");
    traverse();
    return 0;
}


void create() {
    front=1;
    char ch;
    do {
        rear++;
        printf("\n input element in queue :");
        scanf("%d",&q[rear]);
        printf("press <Y/N> FOR more element : ");
        scanf(" %c",&ch);

    }while(ch=='Y' || ch=='y');
}
void traverse() {
    int i;
    printf("\n element in the queue are : ");
    for(i=front; i<=rear; ++i) {
        printf("%d\n",q[i]);
    }

}
void insert() {
    int m;
    if(rear==MAX) {
        printf("\n queue is overflow\n");
        return;
    }
    printf("\n input new element to insert :");
    scanf("%d",&m);
    rear++;
    q[rear]=m;
}
void delete() {
    if(front==0) {
        printf("\nqueue is underflow\n ");
        return;
    }
    if(front==rear) {
        q[front]='\n';
        front=rear=0;
    }else{
        q[front]='\0';
        front++;
    }
}