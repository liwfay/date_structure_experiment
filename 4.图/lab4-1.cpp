//lab4-1.cpp
//////////////////////////////////////////written by lofone at 2018/11/18///////////////////////////////////

#include <stdio.h>  
#include <malloc.h>

#define  MAX_VERTEX_NUM 20
#define OK 1;
#define ERROR 0;
typedef int Status;

//-------------图的邻接表存储表示-----------------  
typedef struct ArcNode {  		 	
	int adjvex; //该弧所指向的顶点的位置    	
    struct ArcNode *nextarc; //链域, 指向下一个邻接点 	
} ArcNode, *LinkArc;   

typedef struct {   
	ArcNode *firstarc; //边表头指针   
	int tag; //访问标记
} VexNode;   

typedef struct{   	 
    VexNode adjlist[MAX_VERTEX_NUM];    
	int vexnum,arcnum; //图中当前顶点数和边数
} Algraph;  

typedef struct{
	int *base;	
	int front;	
	int rear;
}Sqqueue;

Status Initqueue(Sqqueue&);
Status Enqueue(Sqqueue&, int);
Status Dequeue(Sqqueue &);
Status CreateUDG(Algraph*);
Status Dfs(Algraph*, int);
Status Bfs(Sqqueue&, Algraph*, int);




Status main()  
{	
	Sqqueue Q;

	int v = 1;//从1结点开始遍历     
    Algraph*G = (Algraph*)malloc(sizeof(Algraph));   
	CreateUDG(G);     
	printf("\nDepth_First Search : ");   
	Dfs(G,v);   
	for (int i = 1; i <= G->vexnum; i++)	
	G->adjlist[i].tag = 0; //将全部tag重新赋0     
	printf("\nBroadth_First Search : ");    
	Bfs(Q, G, v);    
	return OK;
} 

Status Initqueue(Sqqueue &Q) //初始化队列 
{
	Q.base = (int*)malloc(sizeof(int));
	if (!Q.base) return ERROR;
	Q.front = Q.rear = 0;
	return OK;
}

Status Enqueue(Sqqueue &Q, int e)//入队列 
{
	Q.base[Q.rear] = e;	
	Q.rear = Q.rear + 1;
	return OK;
}  

Status Dequeue(Sqqueue &Q)//出队列
 {	
	int e;	    
    e = Q.base[Q.front];   
	Q.front = Q.front + 1;
	return e;
} 

Status CreateUDG(Algraph *G)//创建无向图的邻接表
 {      
	int i, j, s, d;	
    LinkArc p, q;     
	printf("Input the number of nodes : ");
	scanf("%d", &G->vexnum);  
	printf("Input the number of edges : ");
	scanf("%d", &G->arcnum);

	for (i = 1; i <= G->vexnum; i++)//顶点表    
	{ 	   
		G->adjlist[i].tag = 0;//初始化为0        
		G->adjlist[i].firstarc = NULL;    
	}     
	for (j = 1; j <= G->arcnum; j++)//顶点所包含的链表   
	{          
		printf("Input the node which connecded by edge %d : ",j);  		
		scanf("%d%d",&s,&d);        
		p=(ArcNode*)malloc(sizeof(ArcNode));         
		q=(ArcNode*)malloc(sizeof(ArcNode));        
		p->adjvex = d;   
		q->adjvex = s;		        
		p->nextarc = G->adjlist[s].firstarc;
		G->adjlist[s].firstarc = p;        
		q->nextarc = G->adjlist[d].firstarc;
		G->adjlist[d].firstarc = q;    
	}
	return OK;
} 

Status Dfs(Algraph*G, int v)  //深度优先遍历
{	
	int w;	
    ArcNode *p;	
	printf("%5d",v);	
	G->adjlist[v].tag = 1;
	p = G->adjlist[v].firstarc;	
	while(p!=NULL)	
	{		
		w=p->adjvex;      	
	    if(G->adjlist[w].tag == 0)        
			Dfs(G,w);      	
		p = p->nextarc;  
	}
	return OK;
} 

Status Bfs(Sqqueue &Q, Algraph*G, int v) //广度优先遍历
{	
	int v1, w;    
    ArcNode *p;    
	Q.base = NULL;    
	Initqueue(Q);
	printf("%5d",v);   
    G->adjlist[v].tag = 1;    
	Enqueue(Q, v);   
    while(Q.front != Q.rear)	
	{		
		v1 = Dequeue(Q);      
	    p = G->adjlist[v1].firstarc;        
		while(p != NULL)       
		 {			
			w = p->adjvex;	    	
			if(G->adjlist[w].tag == 0)	       
			{				
				printf("%5d",w);		        
				G->adjlist[w].tag = 1;	           
				 Enqueue(Q,w);	        
			}            
			p = p->nextarc;                 
		}     				
	}
	return OK;
} 

