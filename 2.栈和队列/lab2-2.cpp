//lab2-2.cpp
////////////////////////////////Written by lofone at 2018/10/31////////////////////////////////
/*ѭ�����У���˳���ʵ��*/

#include<stdio.h>
#include<malloc.h>

#define OK 1
#define ERROR 0
#define MAXSIZE 100

typedef struct {
	int *base; //ָ��һ�������Ĵ洢��Ԫ
	int front;
	int rear;
}Sqqueue; //ѭ������

int InitQueue(Sqqueue&); //��ʼ��
int CreateQueue(Sqqueue&); //��������Ķ��г���n�͸�Ԫ��ֵ����һ��ѭ��˳����ʾ�Ķ���
int InQueue(Sqqueue&, int); //������Ĳ������
int DeQueue(Sqqueue&); //Ԫ�س��� 
int DisplayQueue(Sqqueue); //��ʾ�¶���Ԫ��

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
	Q.front = Q.rear = 0; //��ʼ��
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
		InQueue(Q, e); //ѭ������InQueue����������
	}
	return OK;

}

int InQueue(Sqqueue &Q, int insert_element)
{
	if ((Q.rear + 1) % MAXSIZE == Q.front)//�ж϶���
		return ERROR;
	Q.base[Q.rear] = insert_element; //���뵽��ǰ��βλ��
	Q.rear = (Q.rear + 1) % MAXSIZE; //��β����
	return OK;
}

int DeQueue(Sqqueue &Q)
{
	if (Q.rear == Q.front) //rear = front �ӿ�
		return ERROR;
     int delete_element;
	 delete_element = Q.base[Q.front];
	 Q.front = (Q.front + 1) % MAXSIZE; //���׺���
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