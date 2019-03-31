//data_struct_lab1-1.cpp
////////////////////////written by lofone at 2018/10/20////////////////////////

#include<stdio.h>
#include<malloc.h>

#define OK 1
#define ERROR -1

struct ListNode
{
	int data;
	struct ListNode *next;
};
typedef struct ListNode Lnode, *LinkList;

int CreateList(LinkList &); //创建
int ReverseList(LinkList);
LinkList OrderList(LinkList, LinkList);
void DisplayNewList(LinkList);

int main()
{
	LinkList list1, list2;
	CreateList(list1);
	CreateList(list2);//创建两个链表
	ReverseList(OrderList(list1, list2));

	getchar();
	getchar();
	return 0;
}

int CreateList(LinkList &L)
{
	printf("Please create a LinkList end with -1 : ");
	int temp = 0;
	L = (LinkList)malloc(sizeof(Lnode));
	L->data = NULL;
	L->next = NULL;

	//通过判断输入值循环插入结点 //头插法
	while (scanf_s("%d", &temp) && temp != -1)
	{
		LinkList temp_pointer = (LinkList)malloc(sizeof(Lnode));
		temp_pointer->data = temp;
		temp_pointer->next = L->next;
		L->next = temp_pointer;
	}
	DisplayNewList(L);
	return OK;
}

int ReverseList(LinkList L)
{
	LinkList list_pointer = (LinkList)malloc(sizeof(Lnode));
	list_pointer->next = NULL;
	list_pointer->data = NULL;
	LinkList temp_pointer = list_pointer;

	while (L->next)
	{
		temp_pointer = L->next->next; //①步
		L->next->next = list_pointer->next; //②步
		list_pointer->next = L->next; //③步
		L->next = temp_pointer; //④步
	}
	L->next = list_pointer->next;
	DisplayNewList(L);
	return OK;
}

	LinkList OrderList(LinkList L1, LinkList L2)
	{
		LinkList L3;
		Lnode *temp_pointer1, *temp_pointer2, *temp_pointer3;
		temp_pointer1 = L1->next;
		temp_pointer2 = L2->next;
		L3 = L1;
		L3->next = NULL;
		temp_pointer3 = L3;
		while (temp_pointer1 != NULL && temp_pointer2 != NULL)
		{
			if (temp_pointer1->data <= temp_pointer2->data) //list1中的值小的话
			{
				temp_pointer3->next = temp_pointer1; //list1的结点接在L3后边
				temp_pointer3 = temp_pointer1; //L3指针后移
				temp_pointer1 = temp_pointer1->next; //L1指针也后移
			}
			else
			{
				temp_pointer3->next = temp_pointer2;
				temp_pointer3 = temp_pointer2;
				temp_pointer2 = temp_pointer2->next;
			}
			if (temp_pointer1)
				temp_pointer3->next = temp_pointer1;
			else
				temp_pointer3->next = temp_pointer2;
		}
		return L3;
	}



/*
LinkList OrderLinkList(LinkList &LinkList1, LinkList &LinkList2)
{
	LinkList LinkList3;
	LinkList temp_pointer1, temp_pointer2, temp_pointer3;
	temp_pointer1 = LinkList1->next;
	temp_pointer2 = LinkList2->next;
	LinkList3 = LinkList1;
	LinkList3->next = NULL;
	temp_pointer3 = LinkList3;
	while (temp_pointer1 != NULL && temp_pointer2 != NULL)
	{
		if (temp_pointer1->data <= temp_pointer2->data)
		{
			temp_pointer3->next = temp_pointer1;
			temp_pointer3 = temp_pointer1;
			temp_pointer1 = temp_pointer1->next;
		}
		else
		{
			temp_pointer3->next = temp_pointer2;
			temp_pointer3 = temp_pointer2;
			temp_pointer2 = temp_pointer2->next;
		}

		if (temp_pointer1)
			temp_pointer3->next = temp_pointer1;
		else
			temp_pointer3->next = temp_pointer2;
	}
	return LinkList3;
}
*/

void DisplayNewList(LinkList L)
{
	LinkList temp_pointer = (LinkList)malloc(sizeof(Lnode));
	printf("The LinkList now is : ");
	temp_pointer = L->next;
	while (temp_pointer)
	{
		printf("%d ", temp_pointer->data);
		temp_pointer = temp_pointer->next; //打印后指针后移
	}
	printf("\n");
}
