#include<stdio.h>
#include<stdlib.h>

void printarray(int *a, int n) {// print at last
    printf("array is :");
    for(int i=0; i<n; i++) {
        printf("%d ",a[i]);
    }
    printf("\n");
}

// selection sort
void selectioSort(int a[], int n) {
    
    for(int i = 0; i < n-1; i++) { //outer loop

        int smallestElement = i; //define smallest element

        for(int j=i+1; j<n; j++) {    // inner i+1 

            if(a[j]<a[smallestElement]) {           // > can decending order
                smallestElement = j;
            }
        }

        //swap(a[i],a[smallestElement]);
        int temp = a[i];
        a[i] = a[smallestElement];
        a[smallestElement] = temp;

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
    selectioSort(a,n);
    printarray(a,n);

    return 0;
}