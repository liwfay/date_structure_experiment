//lab2-1.cpp
////////////////////////////////Written by lofone at 2018/10/27/////////////////////////////
/*顺序栈，用连续内存单元构建顺序表*/

#include<stdio.h>
#include<malloc.h>

#define OK 1
#define ERROR 0
#define STACK_INIT_SIZE 100

typedef struct {
	int *base; //栈底
	int *top; //栈顶
	int stacksize; //当前大小
}Sqstack;

int InitStack(Sqstack&); //初始化构造空栈
int CreateStack(Sqstack&); //根据输入的栈中元素个数n和各元素值建立一个顺序栈
int Push(Sqstack&, int); //压栈
int Pop(Sqstack&); //出栈
int DisplayStack(Sqstack); //显示当前栈中元素

int main()
{
	/*测试InitStack函数和CreateStack函数*/
	Sqstack Stack;
	CreateStack(Stack);
	DisplayStack(Stack);

	/*测试入栈*/
	int e;
	printf("\nInput the value of e to push it in stack : ");
	scanf("%d", &e);
	Push(Stack, e); //push e into stack
	DisplayStack(Stack);

	/*测试出栈*/
	Pop(Stack);
	DisplayStack(Stack);

	return 0;
}

int InitStack(Sqstack &S)
{
	S.base = (int*)malloc(STACK_INIT_SIZE * sizeof(int)); //分配连续内存
	if (!S.base)
		return(ERROR);
	S.top = S.base; //空栈
	S.stacksize = STACK_INIT_SIZE;

	return OK;
}

int CreateStack(Sqstack &S)
{
	int n = 0;
	int push_element;

	InitStack(S);
	printf("How many numbers do you wanna create : ");
	scanf("%d", &n);
	printf("Input them : ");
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &push_element); //循环调用push函数以入栈
		Push(S, push_element);
	}

	return OK;
}

int Push(Sqstack &S, int push_element)
{
	if (S.top - S.base > S.stacksize)  /*如果栈满，则函数返回ERROR*/ //top-base+1个
		return ERROR;
	*S.top++ = push_element;/*将新元素e存放在top所指示的存储单元中,并使top值加1*/

	return OK;
}

int Pop(Sqstack &S)
{
	int pop_element;

	if (S.top - S.base <= 0) //判断栈空
		return ERROR;
	pop_element = *--S.top; //弹出元素，栈顶递减
	printf("\nThe popped element is %d\n", pop_element);
	return OK;
}

int DisplayStack(Sqstack S)
{
	printf("The new stack is : ");
	int  *display_stack = S.base;
	for (int i = 0; i < S.top - S.base; i++)   /*依次输出栈中各元素的值，栈顶元素在表的尾部*/
		printf("%d ", *display_stack++); //输出后指针后移
	printf("\n");
	return OK;
}
