#include<stdio.h>
#define STACK_MAX 2
typedef struct{
	int top;
	int data[STACK_MAX];

}Stack;
 void push(Stack *s,int item){
	if(s->top<STACK_MAX){
		s->data[s->top]=item;
		s->top=s->top+1;

	}else {
		printf("Stack is full\n");
		}
 }
 int pop(Stack *s){
	int item;
	if(s->top==0)
	{
		printf("Stack is empty");
		return -1;

	} else {
		s->top=s->top-1;
		item=s->data[s->top];
		}
	return item;
}
int main()
{
	Stack s1;
	s1.top=0;
	push(&s1,4);
	push(&s1,5);
	push(&s1,6);
	printf("%d\n",pop(&s1));
	printf("%d\n",pop(&s1));
	//printf("%d\n",pop(&s1));
	//printf("%d\n",pop(&s1));
	return 0;
}
