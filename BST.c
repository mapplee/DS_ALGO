#include<stdio.h>
#include<stdlib.h>
typedef struct node Node;
struct node{
	int data;
	Node *parent;
	Node *left;
	Node *right;
};
// at-first create node with null left ,right and parent;
Node *create_node(int item)
{
	Node *new_node=(Node *)malloc(sizeof(Node));
	if(new_node==NULL)
	{
	printf("Error Occurd\n");
		exit(1);
	}
	new_node->data=item;
	new_node->parent=NULL;
	new_node->left=NULL;
	new_node->right=NULL;

	return new_node;
}
//from insert_bst function take last node then add value left or right with parent node
void add_left_child(Node *node, Node *child)
{
	node->left=child; //last node
	if(child!=NULL)
	{
		child->parent=node;
	}
}
void add_right_child(Node *node,Node *child)
{
	node->right=child;
	if(child!=NULL)
	{
		child->parent=node;
	}
}

//Each and every time  travarse node from root to last node for adding  new node
//We will work with *node
Node *insert_bst(Node *root,Node *node)
{
	Node *parent_node,*current_node; /*for (new node) parent_node is null so the last current node will parent_node for new node */
	if(root==NULL)
	{
		root=node;
		return node;
	}
	parent_node=NULL;
	current_node=root;
	//finding the last node where we can add our new node
	while(current_node!=NULL)
	{
		parent_node=current_node; //That was the node Which have NULL left or NULL right
		if(node->data < current_node->data)
			{
				current_node=current_node->left;
			}else
			{
				current_node=current_node->right;
			}
	}

	if(node->data < parent_node->data)//check the parent node data before adding with parent.
	{
		add_left_child(parent_node,node);
	}else
	{
		add_right_child(parent_node,node);
	}
	return root;
}

Node *create_bst()
{
	Node *root,*node;
	root=create_node(10);
	int arr[]={5,17,3,7,12,19,1,4};
	for(int i=0;i<8;i++)
	{
		node=create_node(arr[i]);
		root=insert_bst(root,node);
	}
	return root;
}
void pre_order(Node *root)
{
	printf("%d ",root->data);
	if(root->left!=NULL)
	pre_order(root->left);
	if(root->right!=NULL)
	pre_order(root->right);
}
void in_oreder(Node *root)
{
	if(root->left!=NULL)
	in_oreder(root->left);
	printf("%d ",root->data);
	if(root->right)
	in_oreder(root->right);

}
void post_order(Node *root)
{

	if(root->left!=NULL)
	{

		post_order(root->left);
	}

	if(root->right!=NULL)
	{
		post_order(root->right);
	}
	printf("%d ",root->data);

}
int main()
{
	Node *root=create_bst();

	printf("%d \n",root->data);
	printf("Traverse with post order(L-R-ROOT): ");
	post_order(root);
	printf("\n");
	printf("Traverse with pre order(ROOT-L-R): ");
	pre_order(root);
	printf("\n");
	printf("Traverse with in order(L-ROOT-R): ");
	in_oreder(root);
	printf("\n");

	return 0;
}
