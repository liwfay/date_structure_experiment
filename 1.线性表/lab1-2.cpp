//data_struct_lab1-2.cpp
/////////////////////written by lofone at 2018/10/20///////////////////////////////

#include<stdio.h>
#include<malloc.h>

#define OK 1;
#define ERROR -1;

/* ���Ա�ĵ�����洢�ṹ */
struct ListNode
{
	int data;
	struct ListNode *next;
};
typedef struct ListNode Lnode, *LinkList;

int CreateList(LinkList &); //����
int SearchList(LinkList, int); //����
int InsertList(LinkList &, int, int); //����
int DeleteList(LinkList&, int); //ɾ��
void DisplayNewList(LinkList); //���������롢ɾ�����ӡ������

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


/* ��������*/
//ͷ�巨��������
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
	int search_count = 1; //ָ���±���Ϊ1

	while (temp_pointer && search_count <= search_where)
	{
		if (search_count == search_where) 
		{
			printf("The number you searched is %d\n", temp_pointer->data);//�ҵ������
			return OK;
		}
		temp_pointer = temp_pointer->next; //ָ�����
		search_count++;  //��ǰ�±�
	}
	printf("The number you searched isn't here\n");
	return ERROR;
}

//
int InsertList(LinkList &L, int insert_where, int insert_number)
{
	LinkList temp_pointer = (LinkList)malloc(sizeof(Lnode)); //��ʱָ��
	temp_pointer = L->next;
	int insert_count = 1;

	while (temp_pointer && insert_count <= insert_where)
	{
		
		if (insert_where == 1) //��������һ��Ԫ��֮ǰ Ҫ�õ�ͷָ��
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
			LinkList number_pointer = (LinkList)malloc(sizeof(Lnode)); //���ָ��
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
		 if (delete_count == delete_where - 1) //�±�Ҫͣ��ɾ��������һ����㴦
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
		temp_pointer = temp_pointer->next; //��ӡ��ָ�����
	}
	printf("\n");
}