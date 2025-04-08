#include<stdio.h>
#include<stdlib.h>

void printarray(int a[], int n) { //for print
    printf("array is :");
    for(int i=0; i<n; i++) {  
        printf("%d ",a[i]);
    }
    printf("\n");
}

//bubble sort   TC- O(n^2)
void bubbleshort(int a[], int n) {
    int temp;
    int isSorted=0;
    for(int i=0; i<n-1; i++) { // for number

        printf("working on time %d\n",i+1);  // for current working
        isSorted =1;

        for(int j=0;j<n-1-i; j++) { // for very number compare
            //last number first shorted
            if(a[j]>a[j+1]) {
                //swap
              temp=a[j];
              a[j]=a[j+1];
              a[j+1]=temp;  
              isSorted = 0;
            }
        }
        if(isSorted) { // go when sort all
            return;
        }
    }
}

int main() {
    int n=6,a[6];

    printf("enter array element :");
    for(int i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    //printarray(a,n);
    bubbleshort(a,n);
    printarray(a,n);

    return 0;
}