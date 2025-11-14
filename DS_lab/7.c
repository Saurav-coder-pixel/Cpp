#include <stdio.h>

struct sparse {
    int row;
    int col;
    int value;
};

int main() {
    int a[10][10], r, c, i, j;
    struct sparse s[100];
    int k = 1; // index for sparse array (0 will store header)

    // a. Read matrix from user
    printf("Enter number of rows and columns: ");
    scanf("%d%d", &r, &c);

    printf("Enter matrix elements:\n");
    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // b. Convert to sparse matrix form
    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            if(a[i][j] != 0) {
                s[k].row = i;
                s[k].col = j;
                s[k].value = a[i][j];
                k++;
            }
        }
    }

    // Store header information at s[0]
    s[0].row = r;
    s[0].col = c;
    s[0].value = k - 1; // number of non-zero elements

    // c. Print sparse matrix (Triplet form)
    printf("\nSparse Matrix Representation (row col value):\n");
    for(i = 0; i < k; i++) {
        printf("%d\t%d\t%d\n", s[i].row, s[i].col, s[i].value);
    }

    return 0;
}
