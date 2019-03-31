//lab6-2.cpp
////////////////////////////written by lofone at 2018/12/07//////////////////////

#include<stdio.h>

#define MAXSIZE 20  //顺序表的最大长度
typedef int Keytype;  //把关键字类型
typedef int Elemtype; //数据类型

//---记录类型---//
typedef struct {
	Keytype key;
	Elemtype other;
}Recdtype;
//---顺序表类型---//
typedef struct {
	Recdtype r[MAXSIZE + 1];  //从1开始存放记录
	int length;
} Sqlist;

void QuickSort(Sqlist&, int, int);
int Partition(Sqlist&, int, int);
void Display(Sqlist);

int main()
{
	Sqlist L;
	printf("Please input the number of records : ");
	scanf_s("%d", &L.length);
	printf("Please input these keys : ");
	for (int i = 1; i <= L.length; i++) //根据记录个数循环
		scanf_s("%d", &L.r[i].key);
	QuickSort(L, 1, L.length);
	Display(L);

	return 0;
}
//---快速排序---//
void QuickSort(Sqlist &L, int low, int high) 
{  
	int pivotloc; //枢轴
	if (low < high)
	{ 
		pivotloc = Partition(L, low, high);  // 将L.r[low..high]一分为二
		QuickSort(L, low, pivotloc - 1); // 对低子表递归排序
		QuickSort(L, pivotloc + 1, high); // 对高子表递归排序
	}
} 
//交换顺序表中子表的记录
int Partition(Sqlist &L, int low, int high) 
{ 
	Keytype pivotkey;
	L.r[0] = L.r[low];            // 用子表的第一个记录作枢轴记录
	pivotkey = L.r[low].key;      // 枢轴记录关键字
	while (low < high) {            // 从表的两端交替地向中间扫描
		while (low < high && L.r[high].key >= pivotkey) --high;
		L.r[low] = L.r[high];      // 将比枢轴记录小的记录移到低端
		while (low < high && L.r[low].key <= pivotkey) ++low;
		L.r[high] = L.r[low];      // 将比枢轴记录大的记录移到高端
	}
	L.r[low] = L.r[0];            // 枢轴记录到位
	return low;                   // 返回枢轴位置
} // Partition

void Display(Sqlist L)
{
	printf("The list now is : ");
	for (int i = 1; i <= L.length; i++)
	{
		printf(" %d", L.r[i].key);
	}
}