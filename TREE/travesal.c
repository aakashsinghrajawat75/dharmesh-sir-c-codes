#include <stdio.h>
#include <stdlib.h>

typedef struct bin {
    int data;
    struct bin *left;
    struct bin *right;
} node;

node *get_node() {
    node *temp = (node *)malloc(sizeof(node));
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void insert(node *root, node *newn) {
    char ch;
    printf("\nWhere to insert left/right of %d (l/r) : ", root->data);
    scanf(" %c", &ch);  // Space before %c to consume newline character

    if (ch == 'l' || ch == 'L') {
        if (root->left == NULL)
            root->left = newn;
        else
            insert(root->left, newn);
    } else if (ch == 'r' || ch == 'R') {
        if (root->right == NULL)
            root->right = newn;
        else
            insert(root->right, newn);
    } else {
        printf("Invalid choice \n");
    }
}

void inorder(node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d->", root->data);
        inorder(root->right);
    }
}

void preorder(node *root) {
    if (root != NULL) {
        printf("%d->", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d->", root->data);
    }
}

int main() {
    int choice;
    char ans;
    node *newn, *root = NULL;

    do {
        printf("\nAakash's Binary Tree Program\n");
        printf("1. Create\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                do {
                    newn = get_node();
                    printf("\nEnter your element: ");
                    scanf("%d", &newn->data);
                    
                    if (root == NULL)
                        root = newn;
                    else
                        insert(root, newn);

                    printf("\nDo you want to enter more elements (y/n) : ");
                    scanf(" %c", &ans);
                } while (ans == 'y' || ans == 'Y');
                break;

            case 2:
                if (root == NULL)
                    printf("Tree is not created.\n");
                else {
                    printf("Inorder Traversal: ");
                    inorder(root);
                    printf("\n");
                }
                break;

            case 3:
                if (root == NULL)
                    printf("Tree is not created.\n");
                else {
                    printf("Preorder Traversal: ");
                    preorder(root);
                    printf("\n");
                }
                break;

            case 4:
                if (root == NULL)
                    printf("Tree is not created.\n");
                else {
                    printf("Postorder Traversal: ");
                    postorder(root);
                    printf("\n");
                }
                break;

            case 5:
                printf("Exiting the program.\n");
                exit(0);

            default:
                printf("Invalid choice, try again.\n");
        }
    } while (choice != 5);

    return 0;
}
