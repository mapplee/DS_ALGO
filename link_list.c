#include<stdio.h>
#include<stdlib.h>
typedef struct node Node;
struct node{
	int data;
	Node *next;
};
Node *create_node(int item,Node *next)
{
	Node *new_node=(Node *)malloc(sizeof(Node));
	if(new_node==NULL)
		{
			printf("Something Error \n");
			exit(1);
		}

	new_node->data=item;
	new_node->next=next;
	return new_node;
}


Node *prepend_node(Node *head, int item)
{
	Node *new_node=(Node *)malloc(sizeof(Node));
	new_node=create_node(item,head);
	return new_node;
}
Node *append(Node *head, int item)
{
	Node *new_node;
	new_node=(Node *)malloc(sizeof(Node));
	new_node=create_node(item,NULL);
	if(head == NULL)
	return new_node;
	Node *current_node=head;
	while(current_node->next!=NULL)
	{
		current_node=current_node->next;
	}
	current_node->next=new_node;
	return head;
}

void print_linked_list(Node *head)
{
	Node *current_node=head;
	while(current_node!= NULL)
	{
		printf("%d ",current_node->data);
		current_node=current_node->next;

	}
	printf("\n");
}

int count(Node  *head)
{
	Node *current_node;
	current_node=head;
	int count=0;
	while(current_node!=NULL)
	{
		count++;
		current_node=current_node->next;
	}
	return count;
}

Node *search(Node *head , int item)
{
	Node *current_node=head;
	while(current_node != NULL)
	{
		if(current_node->data==item)
			return current_node;
		current_node=current_node->next;
	}
	return current_node;
}
int main()
{
	Node *head;
	head=create_node(10,NULL);
	//Node *n1;
	//n1=create_node(5,NULL);
	print_linked_list(head);
	printf("Element of link list : %d\n",count(head));
	head=prepend_node(head,20);
	print_linked_list(head);
	printf("Element of link list : %d\n",count(head));
	head=append(head,30);
	print_linked_list(head);
	printf("Element of link list : %d\n",count(head));

	int element;
	printf("Search Item : ");
	scanf("%d",&element);
	Node *search_item;
	search_item=search(head,element);
	if(search_item!=NULL)
		printf("Item %d found ",search_item->data);
	else
		printf("Item not found");
//	head=prepend_node(head,20);
//	print_linked_list(head);
//	head=append(head,30);
//	print_linked_list(head);

	return 0;
}
