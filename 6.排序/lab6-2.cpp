//lab6-2.cpp
////////////////////////////written by lofone at 2018/12/07//////////////////////

#include<stdio.h>

#define MAXSIZE 20  //˳������󳤶�
typedef int Keytype;  //�ѹؼ�������
typedef int Elemtype; //��������

//---��¼����---//
typedef struct {
	Keytype key;
	Elemtype other;
}Recdtype;
//---˳�������---//
typedef struct {
	Recdtype r[MAXSIZE + 1];  //��1��ʼ��ż�¼
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
	for (int i = 1; i <= L.length; i++) //���ݼ�¼����ѭ��
		scanf_s("%d", &L.r[i].key);
	QuickSort(L, 1, L.length);
	Display(L);

	return 0;
}
//---��������---//
void QuickSort(Sqlist &L, int low, int high) 
{  
	int pivotloc; //����
	if (low < high)
	{ 
		pivotloc = Partition(L, low, high);  // ��L.r[low..high]һ��Ϊ��
		QuickSort(L, low, pivotloc - 1); // �Ե��ӱ�ݹ�����
		QuickSort(L, pivotloc + 1, high); // �Ը��ӱ�ݹ�����
	}
} 
//����˳������ӱ�ļ�¼
int Partition(Sqlist &L, int low, int high) 
{ 
	Keytype pivotkey;
	L.r[0] = L.r[low];            // ���ӱ�ĵ�һ����¼�������¼
	pivotkey = L.r[low].key;      // �����¼�ؼ���
	while (low < high) {            // �ӱ�����˽�������м�ɨ��
		while (low < high && L.r[high].key >= pivotkey) --high;
		L.r[low] = L.r[high];      // ���������¼С�ļ�¼�Ƶ��Ͷ�
		while (low < high && L.r[low].key <= pivotkey) ++low;
		L.r[high] = L.r[low];      // ���������¼��ļ�¼�Ƶ��߶�
	}
	L.r[low] = L.r[0];            // �����¼��λ
	return low;                   // ��������λ��
} // Partition

void Display(Sqlist L)
{
	printf("The list now is : ");
	for (int i = 1; i <= L.length; i++)
	{
		printf(" %d", L.r[i].key);
	}
}