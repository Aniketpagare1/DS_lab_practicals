
#include <stdio.h>
#include <stdlib.h>

struct node {
	int key;
	struct node *left, *right;
};

struct node* newNode(int item)
{
	struct node* temp
		= (struct node*)malloc(sizeof(struct node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

void inorder(struct node* root)
{
	if (root != NULL) {
		inorder(root->left);
		printf("%d ", root->key);
		inorder(root->right);
	}
}

void preorder(struct node* root)
{
	if (root != NULL) {
	    printf("%d ", root->key);
		preorder(root->left);
		preorder(root->right);
	}
}
void postorder(struct node* root)
{
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->key);
        
    }
    
}

struct node* insert(struct node* node, int key)
{
	if (node == NULL)
		return newNode(key);

	
	if (key < node->key)
		node->left = insert(node->left, key);
	else
		node->right = insert(node->right, key);

	return node;
}

/* Given a non-empty binary search
tree, return the node
with minimum key value found in
that tree. Note that the
entire tree does not need to be searched. */
struct node* minValueNode(struct node* node)
{
	struct node* current = node;

	/* loop down to find the leftmost leaf */
	while (current && current->left != NULL)
		current = current->left;

	return current;
}

/* Given a binary search tree
and a key, this function
deletes the key and
returns the new root */
struct node* deleteNode(struct node* root, int key)
{
	// base case
	if (root == NULL)
		return root;

	// If the key to be deleted
	// is smaller than the root's
	// key, then it lies in left subtree
	if (key < root->key)
		root->left = deleteNode(root->left, key);

	// If the key to be deleted
	// is greater than the root's
	// key, then it lies in right subtree
	else if (key > root->key)
		root->right = deleteNode(root->right, key);

	// if key is same as root's key,
	// then This is the node
	// to be deleted
	else {
		// node with only one child or no child
		if (root->left == NULL) {
			struct node* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			struct node* temp = root->left;
			free(root);
			return temp;
		}

		// node with two children:
		// Get the inorder successor
		// (smallest in the right subtree)
		struct node* temp = minValueNode(root->right);

		// Copy the inorder
		// successor's content to this node
		root->key = temp->key;

		// Delete the inorder successor
		root->right = deleteNode(root->right, temp->key);
	}
	return root;
}
int hi(struct node* root)
{
   if(root==NULL){
    return 0;
   }
   else
   {
       int lhi=hi(root->left);
       int rhi=hi(root->right);
       if(lhi>=rhi){
           return lhi + 1;
           
       }
       else
       {
           return rhi + 1;
       }
   }
}

int main()
{
	struct node* root = NULL;
	
	root = insert(root, 50);
	root = insert(root, 30);
	root = insert(root, 20);
	root = insert(root, 40);
	root = insert(root, 70);
	root = insert(root, 60);
	root = insert(root, 80);

	printf("Display of the given tree \n");
	inorder(root);

root=deleteNode(root,30);
printf("\nDisplay of the given tree after deleting node\n");
inorder(root);
printf("\nPreorder traversal of the given tree \n");
preorder(root);
printf("\nPostorder traversal of the given tree \n");
postorder(root);
printf("\nHight of the given tree : %d ",hi(root));


	return 0;
}
