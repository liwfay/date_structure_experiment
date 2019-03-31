//lab2-2.cpp
////////////////////////////////Written by lofone at 2018/10/31////////////////////////////////
/*循环队列，用顺序表实现*/

#include<stdio.h>
#include<malloc.h>

#define OK 1
#define ERROR 0
#define MAXSIZE 100

typedef struct {
	int *base; //指向一组连续的存储单元
	int front;
	int rear;
}Sqqueue; //循环队列

int InitQueue(Sqqueue&); //初始化
int CreateQueue(Sqqueue&); //根据输入的队列长度n和各元素值建立一个循环顺序表表示的队列
int InQueue(Sqqueue&, int); //将传入的参数入队
int DeQueue(Sqqueue&); //元素出队 
int DisplayQueue(Sqqueue); //显示新队列元素

int main()
{
	int e;
	Sqqueue Queue;

	CreateQueue(Queue);
	DisplayQueue(Queue);

	printf("What do you wanna insert into squeue : ");
	scanf("%d", &e);
	InQueue(Queue, e);
	DisplayQueue(Queue);

	DeQueue(Queue);
	DisplayQueue(Queue);

	return 0;
}

int InitQueue(Sqqueue &Q)
{
	Q.base = (int*)malloc(MAXSIZE * sizeof(int));
	if (!Q.base)
		return ERROR;
	Q.front = Q.rear = 0; //初始化
		return OK;
}

int CreateQueue(Sqqueue &Q)
{
	int n, e;
	InitQueue(Q);
	printf("How many element would you wanna create : ");
	scanf("%d", &n);
	printf("Input these element : ");
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &e);
		InQueue(Q, e); //循环调用InQueue函数逐个入队
	}
	return OK;

}

int InQueue(Sqqueue &Q, int insert_element)
{
	if ((Q.rear + 1) % MAXSIZE == Q.front)//判断队满
		return ERROR;
	Q.base[Q.rear] = insert_element; //插入到当前队尾位置
	Q.rear = (Q.rear + 1) % MAXSIZE; //队尾后置
	return OK;
}

int DeQueue(Sqqueue &Q)
{
	if (Q.rear == Q.front) //rear = front 队空
		return ERROR;
     int delete_element;
	 delete_element = Q.base[Q.front];
	 Q.front = (Q.front + 1) % MAXSIZE; //队首后置
	 printf("The deleted element is : %d\n", delete_element);
	 return OK;
}

int DisplayQueue(Sqqueue Q)
{
	printf("The new queue is : ");

	while (Q.front < Q.rear)
		printf("%d ", Q.base[Q.front++]);

	printf("\n");
	return OK;
}