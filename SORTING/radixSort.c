#include <stdio.h>
#include <stdlib.h>

void printarray(int a[], int n)
{
    printf("array is :");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void bucketSort(float a[], int n) {
    // Create n empty buckets
    float buckets[n][n];
    int count[n];
    for (int i = 0; i < n; i++)
    {
        count[i] = 0;
    }

    // Put array elements into different buckets
    for (int i = 0; i < n; i++)
    {
        int bucketIndex = n * a[i]; // Index in bucket
        buckets[bucketIndex][count[bucketIndex]++] = a[i];
    }

    // Sort individual buckets using insertion sort
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < count[i]; j++)
        {
            float key = buckets[i][j];
            int k = j - 1;
            while (k >= 0 && buckets[i][k] > key)
            {
                buckets[i][k + 1] = buckets[i][k];
                k--;
            }
            buckets[i][k + 1] = key;
        }
    }

    // Concatenate all buckets into arr[]
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < count[i]; j++)
        {
            a[index++] = buckets[i][j];
        }
    }
}

int main() {
    int n = 6, a[6];

    printf("enter array element :");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    // printarray(a,n);
    // bubbleshort(a,n);
    bucketSort(a, n);
    printarray(a, n);

    return 0;
}