#include<stdio.h>
#include<stdlib.h>
typedef struct node Node;
struct node
{
	int data;
	Node *next;
	Node *prev;

};
Node *create_node(int item,Node *next,Node *prev)
{
	Node *new_node=(Node *)malloc(sizeof(Node));
	if(new_node==NULL)
	{
		printf("Something went wrong\n");
		exit(1);
	}
	new_node->data=item;
	new_node->next=next;
	new_node->prev=prev;
	return new_node;
}
Node *prepend_node(Node *head,int item)
{
	Node *new_node=create_node(item,head,NULL);
	new_node->next->prev=new_node;
	return new_node;
}

Node *append(Node *head,int item)
{
	Node *new_node=create_node(item,NULL,NULL);
	if(head==NULL)
	{

		return new_node;
	}


	Node *current_node;

	current_node=head;

	while(current_node->next!=NULL)
	{
		current_node=current_node->next;
	}

	current_node->next=new_node;
	new_node->prev=current_node;
	return head;
}
void insert_node(Node *node,int item)
{

		//Node *new_node=(Node *)malloc(sizeof(Node));
		Node *new_node=create_node(item,node->next,node);

		node->next=new_node;
		node->next->prev=new_node;

}

Node *search_node(Node *head,int item)
{

	Node *current_item=head;
	while(current_item!=NULL)
	{
		if(current_item->data==item)
			return current_item;
		current_item=current_item->next;
	}
	return  current_item;
}

Node *remove_node(Node *head,int item)
{

	Node *node;
	node=search_node(head,item);
	if(node!=NULL)
		{
			if(node == head)
			{
				head=head->next;
				head->prev=NULL;
				free(node);
				return head;
			}

			Node *previous_node=node->prev;
			Node *next_node=node->next;

			previous_node->next=next_node;
			if(next_node!=NULL)
			next_node->prev=previous_node;
			free(node);

		}
	//free(node);
	return head;
}


void print_doubly_link_list(Node *head)
{
	Node *current_node=head;
	while(current_node!=NULL)
	{
		printf("%d ",current_node->data);
		current_node=current_node->next;
	}
	printf("\n");
}

int main()
{
	Node *n1,*n2,*n3,*head;
	head=create_node(5,NULL,NULL);
	head=append(head,8);
	head=append(head,15);
	head=prepend_node(head,1008);
	head=append(head,18);

	n1=search_node(head,8);
	head=remove_node(head,1);
	insert_node(n1,10006);
	print_doubly_link_list(head);

	return 0;
}


