#include<stdio.h>
#include<stdlib.h>
#define MAX 7     //size

int stack[MAX], top=-1; // -1 mean NULL

void push() {  // insert value in tatck
    int value;
    if (top == MAX-1) {   
        printf("overflow");
    }else{
        printf("enter value to push :");
        scanf("%d",&value);
        top++;
        stack[top]= value;
        printf("%d pushed into the stack\n",value);
    }
}

void pop() {     // delete element in the stack
    if(top== -1) {
        printf("stack underflow! No element pop\n");
    }else{
        printf("%d popped from the stack.\n",stack[top]);
        top--;
    }
}

void display() {     // display stack element
    if(top == -1) {
        printf("stack is empty \n");
    }else{
        printf("stack element\n");
        for(int i= top; i >=0;i--) {
            printf("%d ",stack[i]);
        }
    }
}

int main() {
    int choice;
    while(1) {
        printf("\n stack operator\n");
        printf(" 1. for push\n");
        printf(" 2. for pop\n");
        printf(" 3. for display\n");
        printf(" 4. for exit\n");

        printf("enter your choice : ");
        scanf("%d",&choice);

        switch(choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("\n OOPs! wrong choice; enter a vilad choice....\n");
        }
    }
}