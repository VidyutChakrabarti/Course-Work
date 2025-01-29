#include <stdio.h>
#include "bstb_68.h"
int main()
{
    struct tnode *root = create_tNode(1);
    insertnodebst(root, 2);
    insertnodebst(root, 3);
    insertnodebst(root, 4);
    insertnodebst(root, 5);
    insertnodebst(root, 6);
    insertnodebst(root, 7);
    insertnodebst(root, 8);
    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);
    int c = countnodes(root);
    printf("\ntotal nodes: %d", c);
    int d = leafnodes(root);
    printf("\ntotal leaf nodes: %d", d);
    int e = intern_nodes(root);
    printf("\ntotal internal nodes: %d", e - 1);
    int h = height(root);
    printf("\nheight of tree: %d", h);
    struct tnode *temp = deleteNode(root, 4);
    printf("\nAfter deletion of key 45 inorder traversal looks like: ");
    inorder(root);
    struct tnode *searched = search(root, 3);
    if (searched != NULL)
        printf("\nkey found: %d\n", searched->data);
    else
        printf("\nkey not found.\n");
    printf("level order traversal: ");
    levelOrderTraversal(root);
    int dir = diameter(root);
    printf("\nThe diameter of the tree is: %d\n", dir);
    printf("inorder traversal through iteration: ");
    inorder_iter(root);
    int p=cpefparent(root);
    printf("\n %d",p);
}
