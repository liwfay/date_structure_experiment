//lab4-2.cpp
/////////// ////////////written by lofone at 2018/11/21//////////////////// 

#include<stdio.h>
#include<malloc.h>
#include<string.h>

#define MAXNODE 20
typedef struct{
	char vertex;
}VerNode;

typedef struct{
	int adj;
}Arc;

typedef struct{
	VerNode vexs[MAXNODE];
	Arc arcs[MAXNODE][MAXNODE];
	int m_numOfVexs;
}Graph;
int mFind(char aim, VerNode* arry)
{
	int pos = -1;
	int i = 0;
	for (i = 0; i < MAXNODE; i++)
	{
		if (aim == arry[i].vertex)
		{
			pos = i;
			return pos;
		}
	}
	return pos;
}
void showGraph(Graph aGraph, int num)
{
	int i = 0;
	int j = 0;
	printf("\n NODES:\n");
	for (i = 0; i < num; i++)
	{
		printf(" %c", aGraph.vexs[i].vertex);
	}
	printf("\n ARCS:\n");
	for (i = 0; i < num; i++)
	{
		for (j = 0; j < num; j++)
		{
			printf(" %d", aGraph.arcs[i][j].adj);
		}
		printf(" \n");
	}
}
//添加顶点
void addVexs(Graph* aGraph, char vex)
{
	aGraph->m_numOfVexs++;
	aGraph->vexs[aGraph->m_numOfVexs].vertex = vex;
}
//添加边
void addArcs(Graph* aGraph, char aStart, char aEnd)
{
	int p_x = mFind(aStart, aGraph->vexs);
	int p_y = mFind(aEnd, aGraph->vexs);
	aGraph->arcs[p_x][p_y].adj = 1;
}
//图的初始化
void initGraph(Graph* aGraph)
{
	int i = 0;
	int j = 0;
	aGraph->m_numOfVexs = -1;
	for (i = 0; i < MAXNODE; i++)
	{
		for (j = 0; j < MAXNODE; j++)
			aGraph->arcs[i][j].adj = 0;
	}
}
int getInDegree(int i, Graph* aGraph)
{
	int InDegree = 0;
	int j = 0;
	for (j = 0; j < aGraph->m_numOfVexs; j++)
		InDegree += aGraph->arcs[j][i].adj;
	return InDegree;
}
int topSort(Graph* aGraph)
{
	int i;
	int isOK = 1;
	int vexsIsOut[MAXNODE];
	for (i = 0; i < aGraph->m_numOfVexs; i++)
	{
		vexsIsOut[i] = 0;
	}
	while (isOK == 1)
	{
		isOK = 0;
		for (i = 0; i < aGraph->m_numOfVexs; i++)
		{
			if (vexsIsOut[i] == 0 && getInDegree(i, aGraph) == 0)
			{
				int j;
				printf("%c ", aGraph->vexs[i].vertex);
				vexsIsOut[i] = 1;
				for (j = 0; j < aGraph->m_numOfVexs; j++)
				{
					aGraph->arcs[i][j].adj = 0;
				}
				isOK = 1;
			}
		}
	}
	for (i = 0; i < aGraph->m_numOfVexs; i++)
	{
		if (vexsIsOut[i] == 0)
			return 0;
	}
	return 1;
}
int main()
{
	char node = 'a';
	char input1 = 'a';
	char input2 = 'a';
	//将图初始化
	Graph g_graph;
	initGraph(&g_graph);
	//根据用户的输入添加顶点
	printf("201716010506张桂诚\n");
	printf("Please input the vexs( end with #):\n");
	while (1)
	{
		if (node == '#')
			break;
		if (scanf_s("%c,", &node) == 1)
		{
			if (node == '\n')
				continue;
			addVexs(&g_graph, node);
		}
	}
	//根据用户的输入添加边
	printf("Please input arcs, just like this \"startNod,endNode\" \n");
	while (1)
	{
		if (input1 == '#')
			break;
		if (scanf_s("%c,%c", &input1, &input2) == 2)
		{
			if (input1 == '\n' || input2 == '\n')
				continue;
			addArcs(&g_graph, input1, input2);
		}
	}
	//输出图
	showGraph(g_graph, g_graph.m_numOfVexs);
	printf("The topsort is: \n");
	if (topSort(&g_graph) == 0)
		printf("There is a circle in the graph!! \n");
	return 0;
}
