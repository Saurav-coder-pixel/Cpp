#include <stdio.h>

// Function to perform linear search
int linearSearch(int arr[], int n, int key) {
    int i;
    for(i = 0; i < n; i++) {
        if(arr[i] == key) {
            return i;  // return index if found
        }
    }
    return -1; // element not found
}

int main() {
    int arr[100], n, key, i, pos;

    // a. Read an array
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d integer values:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // b. Input element to search
    printf("Enter element to search: ");
    scanf("%d", &key);

    // c. Call function for linear search
    pos = linearSearch(arr, n, key);

    // d. Display result
    if(pos == -1)
        printf("Element not found in the array.\n");
    else
        printf("Element found at position %d\n", pos + 1); // +1 for user-friendly position

    return 0;
}
