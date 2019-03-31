//lab6-1.cpp
/////////////////////////written by lofone at 2018/12/04///////////////////////

#include<stdio.h>

#define MAXSIZE 50  //顺序表的最大长度
typedef int Keytype;  //把关键字类型定义为整型
typedef int Elemtype;
//---记录类型---//
typedef struct{
	Keytype key;
	Elemtype other;
}Recdtype;
//---顺序表类型---//
typedef struct{
	Recdtype r[MAXSIZE + 1];  //从1开始存放记录，0号未用
	int length;
} Sqlist;
//---记录比较次数和移动次数---//
struct{
	int compare_times;  
	int move_times; 
} cm[3]; //三种排序方式

Sqlist DirectlyInsertSort(Sqlist); //直接插入排序
Sqlist BubbleSort(Sqlist); //冒泡排序
Sqlist SelectSort(Sqlist); //选择排序
void Display(Sqlist); //打印新表

int main()
{
	Sqlist L;
	for (int i = 0; i < 3; i++)
	{
		cm[i].compare_times = 0;
		cm[i].move_times = 0;
	} 
	printf("Please input the number of records : "); 
	scanf("%d", &L.length);
	printf("Please input these keys : ");
	for (int i = 1; i <= L.length; i++) //根据记录个数循环
		scanf("%d", &L.r[i].key);

	printf("Directly Insertion Sort:\n");//调用接插入排序
	DirectlyInsertSort(L);
	Display(L);
	printf("\nhe comparing numbers is %d\n", cm[0].compare_times);
	printf("the moving numbers is %d\n\n", cm[0].move_times);

	printf("Bubble Sort:\n"); //调用冒泡排序
	BubbleSort(L);
	Display(L);
	printf("\nthe comparing numbers is %d\n", cm[1].compare_times);
	printf("the moving numbers is %d\n\n", cm[1].move_times);

	printf("Select Sort:\n"); //调用选择排序
	SelectSort(L);
	Display(L);
	printf("\nthe comparing numbers is %d\n", cm[2].compare_times);
	printf("the moving numbers is %d\n", cm[2].move_times);
	return 0;
}

//---直接插入排序---//
Sqlist DirectlyInsertSort(Sqlist  L) 
{
	int i, j;
	for (i = 2; i <= L.length; ++i)
		if (cm[0].compare_times++, L.r[i].key < L.r[i - 1].key)  /*比较时，比较次数加1*/
		{
			L.r[0] = L.r[i];  /*将待插入的记录移到零号存储单元,充当监视哨*/
			cm[0].move_times++;  /*移动次数加1*/
			for ( j = i - 1; cm[0].compare_times++, L.r[0].key < L.r[j].key; --j)/*在比较关键字值时,比较次数要加1*/
			{
				L.r[j + 1] = L.r[j];  /*记录后移*/
				cm[0].move_times++;     /*移动次数加1*/
			}
			L.r[j + 1] = L.r[0];
			cm[0].move_times++;    /*移动次数加1*/
		}
	return L;
}
//---冒泡排序---//
Sqlist BubbleSort(Sqlist L) 
{
	int change = 1; /*数据是否发生交换的标志变量*/
	Recdtype temp;

	for (int i = 1; i <= L.length - 1 && change; ++i)
	{
		change = 0;
		for (int j = 1; j <= L.length - i; ++j)
			if (cm[1].compare_times++, L.r[j + 1].key < L.r[j].key) /*比较关键字值时,比较次数加1*/
			{
				temp = L.r[j];
				L.r[j] = L.r[j + 1];
				L.r[j + 1] = temp;
				cm[1].move_times += 3;  /*数据交换需进行3次移动*/
				change = 1;
			}
	}
	return L;
}
//---直接选择排序---//
Sqlist SelectSort(Sqlist L)
{
	int k;
	Recdtype temp;
	for (int i = 1; i <= L.length - 1; ++i)
	{
		k = i;
		for (int j = i + 1; j <= L.length; ++j)
			if (cm[2].compare_times++, L.r[j].key < L.r[k].key) /*比较关键字值时,比较次数加1*/
				k = j;    /* k始终“指向”关键字最小的记录*/
		if (k != i)
		{
			temp = L.r[i];
			L.r[i] = L.r[k];
			L.r[k] = temp;
			cm[2].move_times += 3;  /*数据交换需进行3次移动*/
		}
	}
	return L;
}

void Display(Sqlist L)
{
	printf("The list now is : ");
	for (int i = 1; i <= L.length; i++)
	{
		printf(" %d", L.r[i].key);
	}
}
