#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Automobile {
    char type[30];
    char company[30];
    int year;                       // Key for BST
    struct Automobile *left, *right;
};

// Create a new node
struct Automobile* createNode(char type[], char company[], int year) {
    struct Automobile *newNode = (struct Automobile*)malloc(sizeof(struct Automobile));
    strcpy(newNode->type, type);
    strcpy(newNode->company, company);
    newNode->year = year;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert in BST
struct Automobile* insert(struct Automobile *root, char type[], char company[], int year) {
    if(root == NULL)
        return createNode(type, company, year);

    if(year < root->year)
        root->left = insert(root->left, type, company, year);
    else
        root->right = insert(root->right, type, company, year);

    return root;
}

// Find minimum (used in deletion)
struct Automobile* findMin(struct Automobile *root) {
    while(root->left != NULL)
        root = root->left;
    return root;
}

// Delete node by year
struct Automobile* delete(struct Automobile *root, int year) {
    if(root == NULL)
        return root;

    if(year < root->year)
        root->left = delete(root->left, year);
    else if(year > root->year)
        root->right = delete(root->right, year);
    else {
        if(root->left == NULL) {
            struct Automobile *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL) {
            struct Automobile *temp = root->left;
            free(root);
            return temp;
        }
        struct Automobile *temp = findMin(root->right);
        root->year = temp->year;
        strcpy(root->type, temp->type);
        strcpy(root->company, temp->company);
        root->right = delete(root->right, temp->year);
    }
    return root;
}

// Traversals
void inorder(struct Automobile *root) {
    if(root != NULL) {
        inorder(root->left);
        printf("%s | %s | %d\n", root->type, root->company, root->year);
        inorder(root->right);
    }
}

void preorder(struct Automobile *root) {
    if(root != NULL) {
        printf("%s | %s | %d\n", root->type, root->company, root->year);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Automobile *root) {
    if(root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%s | %s | %d\n", root->type, root->company, root->year);
    }
}

int main() {
    struct Automobile *root = NULL;
    int choice, year;
    char type[30], company[30];

    while(1) {
        printf("\n--- MENU ---\n");
        printf("1. Insert Automobile\n");
        printf("2. Delete by Year of Make\n");
        printf("3. In-Order Display\n");
        printf("4. Pre-Order Display\n");
        printf("5. Post-Order Display\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter Type, Company, Year: ");
                scanf("%s %s %d", type, company, &year);
                root = insert(root, type, company, year);
                break;

            case 2:
                printf("Enter Year to delete: ");
                scanf("%d", &year);
                root = delete(root, year);
                break;

            case 3:
                printf("\nIn-Order (sorted by year):\n");
                inorder(root);
                break;

            case 4:
                printf("\nPre-Order:\n");
                preorder(root);
                break;

            case 5:
                printf("\nPost-Order:\n");
                postorder(root);
                break;

            case 6:
                return 0;

            default:
                printf("Invalid Choice!\n");
        }
    }
}
