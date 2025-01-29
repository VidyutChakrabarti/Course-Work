#include <stdio.h>
#include <stdlib.h>
struct tnode
{
    int data;
    struct tnode *left;
    struct tnode *right;
};
struct tnode *create_tNode(int elem)
{
    struct tnode *temp;
    temp = (struct tnode *)malloc(sizeof(struct tnode));
    if (temp != NULL)
    {
        temp->data = elem;
        temp->left = NULL;
        temp->right = NULL;
    }
    else
    {
        printf("Allocation of memory failed.");
        exit(0);
    }
    return temp;
}
struct tnode *insertnodebst(struct tnode *root, int elem)
{
    struct tnode *temp;
    temp = root;
    if (temp == NULL)
    {
        struct tnode *newnode = create_tNode(elem);
        temp = newnode;
    }
    else
    {
        if (temp->data >= elem)
        {
            temp->left = insertnodebst(temp->left, elem);
        }
        else if (temp->data < elem)
        {
            temp->right = insertnodebst(temp->right, elem);
        }
    }
    return temp;
}
void inorder(struct tnode *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
void preorder(struct tnode *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct tnode *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}
int countnodes(struct tnode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        return countnodes(root->left) + countnodes(root->right) + 1;
    }
}

int leafnodes(struct tnode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    else
    {
        return leafnodes(root->left) + leafnodes(root->right);
    }
}

int intern_nodes(struct tnode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else if (root->left == NULL && root->right == NULL)
    {
        return 0;
    }
    else
    {
        return intern_nodes(root->left) + intern_nodes(root->right) + 1;
    }
}
int max(int c, int b)
{
    if (c > b)
    {
        return c;
    }
    else if (b > c)
    {
        return b;
    }
    else
    {
        return b;
    }
}
int height(struct tnode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        return max(height(root->left), height(root->right)) + 1;
    }
}
struct tnode *deleteNode(struct tnode *root, int k)
{
    if (root == NULL)
        return root;
    if (root->data > k)
    {
        root->left = deleteNode(root->left, k);
        return root;
    }
    else if (root->data < k)
    {
        root->right = deleteNode(root->right, k);
        return root;
    }
    if (root->left == NULL)
    {
        struct tnode *temp = root->right;
        free(root);
        return temp;
    }
    else if (root->right == NULL)
    {
        struct tnode *temp = root->left;
        free(root);
        return temp;
    }
    else
    {

        struct tnode *succParent = root;
        struct tnode *succ = root->right;
        while (succ->left != NULL)
        {
            succParent = succ;
            succ = succ->left;
        }
        if (succParent != root)
            succParent->left = succ->right;
        else
            succParent->right = succ->right;
        root->data = succ->data;
        free(succ);
        return root;
    }
}
struct tnode *search(struct tnode *root, int key)
{
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->data == key)
        return root;
    // Key is greater than root's key
    if (root->data < key)
        return search(root->right, key);
    // Key is smaller than root's key
    return search(root->left, key);
}
void levelOrderTraversal(struct tnode *root)
{
    if (root == NULL)
        return;
    struct tnode **queue =
        (struct tnode **)malloc(sizeof(struct tnode *) * 50);
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front < rear)
    {
        struct tnode *current = queue[front++];
        printf("%d ", current->data);
        if (current->left != NULL)
        {
            queue[rear++] = current->left;
        }
        if (current->right != NULL)
        {
            queue[rear++] = current->right;
        }
    }
}
int diameter(struct tnode *root)
{
    if (root == NULL)
        return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    int ldir = diameter(root->left);
    int rdir = diameter(root->right);
    return max(lh + rh + 1,
               max(ldir, rdir));
}
void inorder_iter(struct tnode *root)
{
    if (root == NULL)
    {
        return;
    }
    struct tnode *stack[50];
    int top = -1;
    struct tnode *current = root;
    while (current != NULL || top != -1)
    {
        // Traverse to the leftmost node
        while (current != NULL)
        {
            stack[++top] = current;
            current = current->left;
        }
        // Visit the top of the stack
        current = stack[top--];
        printf("%d ", current->data);
        // Move to the right subtree
        current = current->right;
    }
}

int cpefparent(struct tnode* root){
    if(root==NULL){
        return 0;
    }
    if(root->left!=NULL && root->right!=NULL){
        printf("%d",root->data);
        return cpefparent(root->left)+cpefparent(root->right)+1;
    }
    else{
       return cpefparent(root->left)+cpefparent(root->right); 
    }
}