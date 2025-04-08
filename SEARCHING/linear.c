#include <stdio.h>

int main() {
    int n, key, found = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the value to search: ");
    scanf("%d", &key);

    // Leaner linear search
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("Element found at index %d\n", i);
            found = 1;
            break; // Stop searching once found
        }
    }

    if (!found) {
        printf("Element not found in the array.\n");
    }

    return 0;
}
