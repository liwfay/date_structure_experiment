//data_struct_lab1-2.cpp
/////////////////////written by lofone at 2018/10/20///////////////////////////////

#include<stdio.h>
#include<malloc.h>

#define OK 1;
#define ERROR -1;

/* 线性表的单链表存储结构 */
struct ListNode
{
	int data;
	struct ListNode *next;
};
typedef struct ListNode Lnode, *LinkList;

int CreateList(LinkList &); //创建
int SearchList(LinkList, int); //查找
int InsertList(LinkList &, int, int); //插入
int DeleteList(LinkList&, int); //删除
void DisplayNewList(LinkList); //创建、插入、删除后打印新链表

int main()
{
	int search_index, insert_index, insert_number, delete_index;

	LinkList L = NULL;
	CreateList(L);

	printf("Which number would you wanna search : ");
	scanf_s("%d", &search_index);
	SearchList(L, search_index);

	printf("Where would you want to insert : ");
	scanf_s("%d", &insert_index);
	printf("Which number would you wanna insert : ");
	scanf_s("%d", &insert_number);
	InsertList(L, insert_index, insert_number);

	printf("Where would you want to delete : ");
	scanf_s("%d", &delete_index);
	DeleteList(L, delete_index);
	getchar();
	getchar();
	return 0;
}


/* 函数定义*/
//头插法建立链表
int CreateList(LinkList &L)
{
	printf("Please create a list end with 0 : ");
	int temp = 0; //temporary
	L = (LinkList)malloc(sizeof(Lnode));
	L->data = NULL;
	L->next = NULL;

	while (scanf_s("%d", &temp) && temp != 0)
	{
		LinkList temp_pointer = (LinkList)malloc(sizeof(Lnode));
		temp_pointer->data = temp;
		temp_pointer->next = L->next;
		L->next = temp_pointer;
	}
	DisplayNewList(L);
	return OK;
}

int SearchList(LinkList L, int search_where)
{
	LinkList temp_pointer = (LinkList)malloc(sizeof(Lnode));
     temp_pointer = L->next;
	int search_count = 1; //指针下标置为1

	while (temp_pointer && search_count <= search_where)
	{
		if (search_count == search_where) 
		{
			printf("The number you searched is %d\n", temp_pointer->data);//找到后输出
			return OK;
		}
		temp_pointer = temp_pointer->next; //指针后移
		search_count++;  //当前下标
	}
	printf("The number you searched isn't here\n");
	return ERROR;
}

//
int InsertList(LinkList &L, int insert_where, int insert_number)
{
	LinkList temp_pointer = (LinkList)malloc(sizeof(Lnode)); //临时指针
	temp_pointer = L->next;
	int insert_count = 1;

	while (temp_pointer && insert_count <= insert_where)
	{
		
		if (insert_where == 1) //如果插入第一个元素之前 要用到头指针
		{
			LinkList number_pointer = (LinkList)malloc(sizeof(Lnode)); 
			number_pointer->data = insert_number;
			number_pointer->next = L->next;
			L->next = number_pointer;
			DisplayNewList(L);
			return OK;
		}
		if (insert_count == insert_where - 1)
		{
			LinkList number_pointer = (LinkList)malloc(sizeof(Lnode)); //结点指针
			number_pointer->data = insert_number;
			number_pointer->next = temp_pointer->next;
			temp_pointer->next = number_pointer;
			DisplayNewList(L);
			return OK;
		}
		temp_pointer = temp_pointer->next;
		insert_count++;

	}
	return ERROR;
}

int DeleteList(LinkList &L, int delete_where)
{
	LinkList temp_pointer = (LinkList)malloc(sizeof(Lnode));
	temp_pointer = L->next;
	int delete_count = 1;

	while (temp_pointer && delete_count <= delete_where ) 
	{
		if (delete_where == 1)
		{
			L = L->next;
			DisplayNewList(L);
			return OK;
		}
		 if (delete_count == delete_where - 1) //下标要停在删除结点的上一个结点处
		{
			temp_pointer->next = temp_pointer->next->next;
			DisplayNewList(L);
			return OK;
		}
		 temp_pointer = temp_pointer->next;
		 delete_count++;
	}
	printf("Your input is bigger than the length\n");
    return ERROR;
}

void DisplayNewList(LinkList L)
{
	LinkList temp_pointer = (LinkList)malloc(sizeof(Lnode));
	printf("The list now is : ");
	temp_pointer = L->next;
	while (temp_pointer)
	{
		printf("%d ", temp_pointer->data);
		temp_pointer = temp_pointer->next; //打印后指针后移
	}
	printf("\n");
}