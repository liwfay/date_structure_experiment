//lab2-3.cpp
////////////////////////////////Written by lofone at 2018/10/31////////////////////////////////
/*链式栈，用链表实现*/

#include<stdio.h>
#include<malloc.h>

#define OK 1
#define ERROR 0

typedef struct node{
	int data;
	struct  node *next;
}StackNode, *Linkstack; //*Linkstack 是结构体指针类型

int InitStack(Linkstack&); //初始化构建空栈
int CreateStack(Linkstack&); //根据输入元素个数n和输入个元素建立链式表
int Push(Linkstack&, int); //将输入元素入栈
int Pop(Linkstack&); //弹出栈顶元素
int DisplayStack(Linkstack); //显示新的栈中元素

int main()
{
	Linkstack Stack;
	/*测试创建函数*/
	CreateStack(Stack);
	DisplayStack(Stack);

	/*测试入栈函数*/
	printf("What do you wanna push : ");
	int e;
	scanf_s("%d", &e);
	Push(Stack, e);
	DisplayStack(Stack);

	/*测试出栈函数*/
	Pop(Stack);
	DisplayStack(Stack);

	return 0;
}

int InitStack(Linkstack &S)
{
/*将栈底元素设为空，用S指向入栈元素*/
	S = NULL;  //栈底 //空栈
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
		Push(S, push_element); //循环调用push函数压栈
	}
	return OK;
}

int Push(Linkstack &S, int push_element)
{
	Linkstack node = (Linkstack)malloc(sizeof(StackNode)); //创建临时结点
	node->data = push_element; //赋值
	node->next = S;
	S = node; //头插法压栈 //S指向栈顶
	return OK;
}

int Pop(Linkstack &S)
{
	printf("The popped element is %d", S->data);
	S = S->next; //头指针直接后移，原元素出栈 //一步出栈，省得麻烦
	return OK;
}

int DisplayStack(Linkstack S)
{
	Linkstack stack_pointer;
	stack_pointer = S;

    printf("The stack now is : ");
	while (stack_pointer) //指针非空 //栈底是空
	{
		printf("%d ", stack_pointer->data);
		stack_pointer = stack_pointer->next; //输出后指针后移
	}
	printf("\n");
	return OK;
}