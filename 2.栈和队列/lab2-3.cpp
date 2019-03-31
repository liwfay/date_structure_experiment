//lab2-3.cpp
////////////////////////////////Written by lofone at 2018/10/31////////////////////////////////
/*��ʽջ��������ʵ��*/

#include<stdio.h>
#include<malloc.h>

#define OK 1
#define ERROR 0

typedef struct node{
	int data;
	struct  node *next;
}StackNode, *Linkstack; //*Linkstack �ǽṹ��ָ������

int InitStack(Linkstack&); //��ʼ��������ջ
int CreateStack(Linkstack&); //��������Ԫ�ظ���n�������Ԫ�ؽ�����ʽ��
int Push(Linkstack&, int); //������Ԫ����ջ
int Pop(Linkstack&); //����ջ��Ԫ��
int DisplayStack(Linkstack); //��ʾ�µ�ջ��Ԫ��

int main()
{
	Linkstack Stack;
	/*���Դ�������*/
	CreateStack(Stack);
	DisplayStack(Stack);

	/*������ջ����*/
	printf("What do you wanna push : ");
	int e;
	scanf_s("%d", &e);
	Push(Stack, e);
	DisplayStack(Stack);

	/*���Գ�ջ����*/
	Pop(Stack);
	DisplayStack(Stack);

	return 0;
}

int InitStack(Linkstack &S)
{
/*��ջ��Ԫ����Ϊ�գ���Sָ����ջԪ��*/
	S = NULL;  //ջ�� //��ջ
	return OK;
}

int CreateStack(Linkstack &S)
{
	int n, push_element;
	InitStack(S);

	printf("How many element do you wanna create : ");
	scanf_s("%d", &n);
	printf("Input these elements : ");
	for (int i = 1; i <= n; i++)
	{
		scanf_s("%d", &push_element);
		Push(S, push_element); //ѭ������push����ѹջ
	}
	return OK;
}

int Push(Linkstack &S, int push_element)
{
	Linkstack node = (Linkstack)malloc(sizeof(StackNode)); //������ʱ���
	node->data = push_element; //��ֵ
	node->next = S;
	S = node; //ͷ�巨ѹջ //Sָ��ջ��
	return OK;
}

int Pop(Linkstack &S)
{
	printf("The popped element is %d", S->data);
	S = S->next; //ͷָ��ֱ�Ӻ��ƣ�ԭԪ�س�ջ //һ����ջ��ʡ���鷳
	return OK;
}

int DisplayStack(Linkstack S)
{
	Linkstack stack_pointer;
	stack_pointer = S;

    printf("The stack now is : ");
	while (stack_pointer) //ָ��ǿ� //ջ���ǿ�
	{
		printf("%d ", stack_pointer->data);
		stack_pointer = stack_pointer->next; //�����ָ�����
	}
	printf("\n");
	return OK;
}