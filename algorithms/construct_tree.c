#include<stdio.h>
#include<stdlib.h>

struct tree_node{
	int val;
	struct tree_node *left;
	struct tree_node *right;
};

struct tree_node *construct_tree_with_pre_in(int *pre_order, int *in_order, int n)
{
	if(n == 0)return NULL;
	struct tree_node *root = (struct tree_node *)malloc(sizeof(struct tree_node));
	if(root == NULL)
	{
		printf("error: malloc.");
		return NULL;
	}
	int root_index = 0;
	for(; root_index < n && in_order[root_index] != pre_order[0]; root_index ++);
	root -> val = pre_order[0];
	root -> left = construct_tree_with_pre_in(pre_order + 1, in_order, root_index);
	root -> right = construct_tree_with_pre_in(pre_order + root_index + 1, in_order + root_index + 1, n - root_index - 1);
	return root;
}

int post_order(struct tree_node *root){
	if(root == NULL)
	{
		printf("#,");
		return 0;
	}
	post_order(root->left);
	post_order(root->right);
	printf("%d,", root->val);
}

int main()
{
	int pre_order[] = {1,2,4,7,3,5,6,8};
	int in_order[] = {4,7,2,1,5,3,8,6};

	struct tree_node *root = construct_tree_with_pre_in(pre_order, in_order, 8);

	post_order(root);

}

