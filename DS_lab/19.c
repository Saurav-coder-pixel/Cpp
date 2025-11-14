// #include <stdio.h>

// int getMax(int a[], int n) {
//     int max = a[0];
//     for(int i=1;i<n;i++)
//         if(a[i] > max) max = a[i];
//     return max;
// }

// void countSort(int a[], int n, int exp) {
//     int out[50], count[10]={0}, i;
//     for(i=0;i<n;i++) count[(a[i]/exp)%10]++;
//     for(i=1;i<10;i++) count[i]+=count[i-1];
//     for(i=n-1;i>=0;i--) {
//         out[count[(a[i]/exp)%10]-1] = a[i];
//         count[(a[i]/exp)%10]--;
//     }
//     for(i=0;i<n;i++) a[i]=out[i];
// }

// int main() {
//     int a[] = {56,77,23,99,68,11,9,29,33,45,10,87};
//     int n = 12, i, max = getMax(a, n);

//     for(int exp=1; max/exp > 0; exp *= 10)
//         countSort(a, n, exp);

//     printf("Radix Sort: ");
//     for(i=0;i<n;i++) printf("%d ", a[i]);
// }


// #include <stdio.h>

// void merge(int a[], int l, int m, int r) {
//     int i=l, j=m+1, k=l, b[50];
//     while(i<=m && j<=r) {
//         if(a[i] < a[j]) b[k++] = a[i++];
//         else b[k++] = a[j++];
//     }
//     while(i<=m) b[k++] = a[i++];
//     while(j<=r) b[k++] = a[j++];
//     for(i=l;i<=r;i++) a[i] = b[i];
// }

// void mergeSort(int a[], int l, int r) {
//     if(l<r) {
//         int m = (l+r)/2;
//         mergeSort(a, l, m);
//         mergeSort(a, m+1, r);
//         merge(a, l, m, r);
//     }
// }

// int main() {
//     int a[] = {56,77,23,99,68,11,9,29,33,45,10,87};
//     int n = 12, i;
//     mergeSort(a, 0, n-1);

//     printf("Merge Sort: ");
//     for(i=0;i<n;i++) printf("%d ", a[i]);
// }



// #include <stdio.h>

// int partition(int a[], int low, int high) {
//     int pivot = a[high], i = low - 1, t, j;
//     for(j=low; j<high; j++) {
//         if(a[j] < pivot) {
//             i++; t = a[i]; a[i] = a[j]; a[j] = t;
//         }
//     }
//     t = a[i+1]; a[i+1] = a[high]; a[high] = t;
//     return i+1;
// }

// void quickSort(int a[], int low, int high) {
//     if(low < high) {
//         int pi = partition(a, low, high);
//         quickSort(a, low, pi-1);
//         quickSort(a, pi+1, high);
//     }
// }

// int main() {
//     int a[] = {56,77,23,99,68,11,9,29,33,45,10,87};
//     int n = 12, i;
//     quickSort(a, 0, n-1);

//     printf("Quick Sort: ");
//     for(i=0;i<n;i++) printf("%d ", a[i]);
// }


// #include <stdio.h>

// int main() {
//     int a[] = {56,77,23,99,68,11,9,29,33,45,10,87};
//     int n = 12, i, j, key;

//     for(i=1;i<n;i++) {
//         key = a[i];
//         j = i - 1;
//         while(j >= 0 && a[j] > key) {
//             a[j+1] = a[j];
//             j--;
//         }
//         a[j+1] = key;
//     }

//     printf("Insertion Sort: ");
//     for(i=0;i<n;i++) printf("%d ", a[i]);
// }


// #include <stdio.h>

// int main() {
//     int a[] = {56,77,23,99,68,11,9,29,33,45,10,87};
//     int n = 12, i, j, temp;

//     for(i=0;i<n-1;i++) {
//         for(j=0;j<n-i-1;j++) {
//             if(a[j] > a[j+1]) {
//                 temp = a[j]; a[j] = a[j+1]; a[j+1] = temp;
//             }
//         }
//     }

//     printf("Bubble Sort: ");
//     for(i=0;i<n;i++) printf("%d ", a[i]);
// }


#include <stdio.h>

int main() {
    int a[] = {56,77,23,99,68,11,9,29,33,45,10,87};
    int n = 12, i, j, min, temp;

    for(i=0; i<n-1; i++) {
        min = i;
        for(j=i+1; j<n; j++) {
            if(a[j] < a[min])
                min = j;
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }

    printf("Selection Sort: ");
    for(i=0;i<n;i++) printf("%d ", a[i]);
}


