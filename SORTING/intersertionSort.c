#include<stdio.h>
#include<stdlib.h>

void printarray(int *a, int n) {
    printf("array is :");
    for(int i=0; i<n; i++) {
        printf("%d ",a[i]);
    }
    printf("\n");
}

void  insertion(int a[], int n) {
    for(int i=1;i<n;i++) {
        int current=a[i];
        int prev=i-1;
        while(prev>=0 && a[prev]>current) {
            a[prev + 1] = a[prev];
            prev--;
        }
        a[prev + 1] = current;
    }
}

int main() {
    int n=6,a[6];

    printf("enter array element :");
    for(int i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    //printarray(a,n);
    //bubbleshort(a,n);
    insertion(a,n);
    printarray(a,n);

    return 0;
}