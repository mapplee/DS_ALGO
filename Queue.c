#include<stdio.h>
#define Q_SIZE 3
typedef struct{
	int data[Q_SIZE+1];
	int head ,tail;
}Queue;
void enqueue(Queue *q, int item)
{
	if((q->tail+1)%(Q_SIZE+1)==q->head){
		printf("Queue is Full");
		return;
	}
	q->data[q->tail]=item;
	q->tail=(q->tail+1)%(Q_SIZE+1);
}
int dequeue(Queue *q){
	int item;
	if(q->tail==q->head){
	printf("Queue is Empty\n");
	return -1;
	}
	item=q->data[q->head];
	q->head=(q->head+1)%(Q_SIZE+1);
	return item;
}
int main()
{
	Queue m_q;
	int item;
	m_q.head=0;
	m_q.tail=0;
	enqueue(&m_q,12);
	printf("Tail = %d\n",m_q.tail);
	enqueue(&m_q,16);
	printf("Tail = %d\n",m_q.tail);
	enqueue(&m_q,20);
	printf("Tail = %d\n\n",m_q.tail);

	printf("Starting head = %d\n\n",m_q.head);
	item=dequeue(&m_q);
	printf("Item= %d head = %d\n\n",item,m_q.head);
	item=dequeue(&m_q);
	printf("Item= %d head = %d\n\n",item,m_q.head);
	item=dequeue(&m_q);
	printf("Item= %d head = %d\n\n",item,m_q.head);
	item=dequeue(&m_q);
	printf("Item= %d head = %d\n\n",item,m_q.head);


}
