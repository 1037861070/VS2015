#ifndef GRAPH_H
#define GRAPH_H

#include<stdio.h>
#include<string.h>

typedef struct Vex {
	int num;
	char name[20];
	char desc[1024];
}Vex;

typedef struct Edge {
	int vex1;
	int vex2;
	int weight;
}Edge;

typedef struct Closedge {
	int lowcost;
	int vex;
}Closedge;

char *trim(char *str);
void Init();
void CreatGraph();
Vex getVex(int i);
void Initcount();
int DFS(int v, int mark[], int aPath[], int index);
void FindShortPath(int start, int aPath[]);
void prim();

int Matrix[20][20];
int VexNum;
int Path[50][20];
Closedge closedge[20];
int result[20];

#endif // !GRAPH_H

