#include <stdio.h>

int main() {
    int arr[100], n, key;
    int low, high, mid, pos = -1;
    int i;

    // a. Read an array
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d sorted integers:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // b. Input element to search
    printf("Enter element to search: ");
    scanf("%d", &key);

    // Binary Search (Iteration)
    low = 0;
    high = n - 1;

    while(low <= high) {
        mid = (low + high) / 2;

        if(arr[mid] == key) {
            pos = mid; // element found
            break;
        }
        else if(key < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    // c. Display result
    if(pos == -1)
        printf("Element not found in the array.\n");
    else
        printf("Element found at position %d\n", pos + 1); // +1 for user position

    return 0;
}
