#include<stdio.h>
int left(int i)
{
	return 2*i;
}
int right(int i)
{
	return (2*i)+1;
}
int parent(int i)
{
	return i/2;
}
int is_max_heap(int h[],int heap_size)
{

	for(int i=heap_size;i>1;i--)
	{
		int p=parent(i);
		printf("i = %d, p = %d\th[i] = %d, h[p] = %d\n",i,parent(i),h[i],h[p]);
		if(h[i]>h[p])
		return 0;
	}
	return 1;
}
void max_heapyfy(int heap[],int heap_size,int i)
{


	int l=left(i);
	int r=right(i);
	int largest;
	if(l<=heap_size&&heap[l]>heap[r])
	{
		largest=l;
	}
	else{
		largest=i;
	}
	if(r<=heap_size&&heap[r]>heap[largest])
	{

		largest=r;

	}
	if(largest!=i)
	{
		int temp;
		temp=heap[i];
		heap[i]=heap[largest];
		heap[largest]=temp;
		max_heapyfy(heap,heap_size,largest);
	}



}
void print_heap(int heap[],int heap_size)
{
	int i;
	for(i=1;i<=heap_size;i++)
	{
		printf("%d ",heap[i]);

	}
	printf("\n\n");
}
void build_max_heap(int heap[],int heap_size)
{

	for(int i=heap_size/2;i>=1;i--)
	{
		max_heapyfy(heap,heap_size,i);
	}
}
void heap_sort(int heap[],int heap_size)
{
	int i,t;
	for(i=heap_size;i>1;i--)
	{
		t=heap[1];
		heap[1]=heap[i];
		heap[i]=t;
		heap_size-=1;
		max_heapyfy(heap,heap_size,1);
	}

}

int main()
{
	int heap_size=5;
	//int heap[]={0,19,7,17,3,5,12,10,1,4};
	//int heap[]={0,12,7,1,3,10,17,19,2,5};
	//int heap[]={0,19,7,12,3,5,17,10,1,2};
	int heap[]={0,6,5,3,1,7};
	printf("%d \n",is_max_heap(heap,heap_size));
	//print_heap(heap,heap_size);
	build_max_heap(heap,heap_size);
	//max_heapyfy(heap,heap_size,3);
	print_heap(heap,heap_size);
	printf("%d \n",is_max_heap(heap,heap_size));
	heap_sort(heap,heap_size);
	print_heap(heap,heap_size);
	//max_heapyfy(h,heap_size,1);
	//is_max_heap(h,heap_size);
	return 0;


}
