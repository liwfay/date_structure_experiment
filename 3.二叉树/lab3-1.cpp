//lab3-1.cpp
/////////////////////////////////written by lofone at 2018/11/06////////////////////////////////////

#include<stdio.h>
#include<malloc.h>

#define OK 1
#define ERROR 0

typedef int Status;
typedef char TElemType;

//--------------二叉链表存储表述-----------------
typedef struct BiTNode
{
	TElemType  data; //数据域
	struct   BiTNode *lchild, *rchild;
	/*左右孩子结点*/
}BiTNode, *BiTree;

//---------------基本操作函数原型-----------------
Status InitBiTree(BiTree&);
Status CreateBiTree(BiTree&);
Status PreOrderTraverse(BiTree&); //先序
Status InOrderTraverse(BiTree&); //中序
Status PostOrderTraverse(BiTree&); //后序

int main()
{
	BiTree Tree = NULL;
	InitBiTree(Tree);
	printf("Input some elements to create a Binary Tree : ");
	CreateBiTree(Tree);
	printf("-------------------------------------------------\n");
	printf("Input a number to start<0-3> \n");
	/*一直循环，输入 0 跳出*/
	while (1)
	{
		static int n;
		printf("\n-------------------------------------------------\n");
		printf("1: PreOrderTraverse\n2: InOrderTraverse\n3: PostOrderTraverse\n0:EXIT!\n");
		scanf_s("%d", &n);
		switch (n) 
		{
		case 1: printf("The preorder is : "); PreOrderTraverse(Tree); break;
		case 2:printf("The midorder is : "); InOrderTraverse(Tree); break;
		case 3:printf("The backorder is :"); PostOrderTraverse(Tree); break;
		case 0: printf("Done ! Press any keys to Exit\n"); goto sign;
		default: printf("ERROR ! Please input the right number<0-3> : "); break;
		}
	}
sign:	getchar();
	return OK;
}

//---------------基本操作函数定义------------------
Status InitBiTree(BiTree &T)
{
	//构造空树
	T = (BiTree)malloc(sizeof(BiTNode));
	T->lchild = NULL;
	T->rchild = NULL;
	return OK;
}

Status CreateBiTree(BiTree &T)
{
	char e;
	scanf_s("%c", &e);
	if (e == '#') T = NULL;
	else
		InitBiTree(T);
	if (!T) return ERROR; //创建失败
	else //递归创建 //先序
	{
		T->data = e; //根
		CreateBiTree(T->lchild); //左子树
		CreateBiTree(T->rchild); //右子树
	}
	return OK;
}

Status PreOrderTraverse(BiTree &T) //先序
{
	if (T != NULL)
	{
		printf("%c ", T->data);
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
	return OK;
}

Status InOrderTraverse(BiTree &T) /*中序遍历二叉树函数*/
{
	if (T != NULL)
	{
		InOrderTraverse(T->lchild); //左子树
		printf("%c ", T->data); //根
		InOrderTraverse(T->rchild); //右子树
	}
	return OK;
}

Status PostOrderTraverse(BiTree &T) //后序
{
	if (T != NULL)
	{
		PostOrderTraverse(T->lchild); //遍历左子树
		PostOrderTraverse(T->rchild); //遍历右子树
		printf("%c", T->data); //根
	}
	return OK;
}
