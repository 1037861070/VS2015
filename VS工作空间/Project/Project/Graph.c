#include"Graph.h"

int count = 0;
Vex aVexs[20];

char *trim(char *str)
{
	char *p = str;
	while (*p == ' ' || *p == '\t' || *p == '\r' || *p == '\n')
		p++;
	str = p;
	p = str + strlen(str) - 1;
	while (*p == ' ' || *p == '\t' || *p == '\r' || *p == '\n')
		--p;
	*(p + 1) = '\0';
	return str;
}

void Init() {
	int i;
	memset(Matrix, 0, sizeof(Matrix));
	for (i = 0; i < 20; i++) 
		aVexs[i].num = 0;
	VexNum = 0;
}

void CreatGraph() {
	FILE *fp = fopen("Vex.txt","r");
	FILE * in = fopen("Edge.txt", "r");
	char Array[1024];
	char * ch;
	int Address[50], Num[3];
	int length;
	int line = 1, i, j, m, k;

	memset(Matrix, 0, sizeof(Matrix));

	if (!fp || !in)
		exit(-1);	

	if (fgets(Array, sizeof(Array), fp)) {
		ch = trim(Array);
		length = strlen(ch);
		for (j = 0; j < length; j++) {
			m = Array[j] - '0';
			VexNum = VexNum * 10 + m;
		}
	}
	while (fgets(Array, sizeof(Array), fp) != NULL) {
		ch = trim(Array);
		length = strlen(ch);
		if (line % 3)
			i = line / 3;
		else
			i = line / 3 - 1;
		if (line % 3 == 1) {
			for (j = 0; j < length; j++) {
				m = Array[j] - '0';
				aVexs[i].num = aVexs[i].num * 10 + m;
			}
		}
		else if (line % 3 == 2) {
			strncpy(aVexs[i].name, Array, 19);
		}
		else {
			strcpy(aVexs[i].desc, Array);
		}
		line++;
	}
	fclose(fp);
	fp = NULL;

	while (fgets(Array, sizeof(Array), in) != NULL){
		ch = trim(Array);
		length = strlen(ch);
		Address[0] = -1;
		j = 1;
		for (i = 0; i < length; i++) {
			if (Array[i] == ' ') {
				Address[j] = i;
				j++;
			}
		}
		Address[j] = length;
		memset(Num, 0, sizeof(Num));
		for (k = 0; k < j; k++) {		
			for (i = Address[k] + 1; i < Address[k + 1]; i++) {
				m = Array[i] - '0';
				Num[k] = Num[k] * 10 + m;
			}
		}
		Matrix[Num[0]][Num[1]] = Num[2];
		Matrix[Num[1]][Num[0]] = Num[2];
	}
	fclose(in);
	in = NULL;
}

Vex getVex(int i) {
	return aVexs[i];
}


void Initcount() {
	count = 0;
}

int DFS(int v, int mark[], int aPath[], int index) {
	int i;
	mark[v] = 1;
	aPath[index++] = v;
	if (index == VexNum) {
		for (i = 0; i < VexNum; i++) 
			Path[count][i] = aPath[i];
		count++;
	}
	else {
		for (i = 0; i < VexNum; i++) {
			if (Matrix[v][i] && !mark[i]) {
				DFS(i, mark, aPath, index);
				mark[i] = 0;
			}
		}
	}
	return count;
}

void FindShortPath(int start, int aPath[]) {
	int num = 0;
	int mark[20];
	int i, j, m, min;
	int arr[20][20];
	int weight1[20];
	for (i = 0; i < VexNum; i++) {
		for (j = 0; j < VexNum; j++) {
			if (Matrix[i][j])
				arr[i][j] = Matrix[i][j];
			else
				arr[i][j] = 0xfffffff;
		}
	}
	for (i = 0; i < VexNum; i++) {
		weight1[i] = arr[start][i];
		aPath[i] = start;
	}
	memset(mark, 0, sizeof(mark));
	mark[start] = 1;
	for (i = 1; i < VexNum; i++) {
		min = 0xfffffff;
		m = -1;
		for (j = 0; j < VexNum; j++) {
			if (!mark[j] && weight1[j] < min) {
				min = weight1[j];
				m = j;
			}
		}
		mark[m] = 1;
		for (j = 0; j < VexNum; j++) {
			if (!mark[j] && min + arr[m][j] < weight1[j]) {
				weight1[j] = min + arr[m][j];
				aPath[j] = m;
			}
		}
	}
}

void prim() {
	int i, j, k, min;
	int arr[20][20];
	for (i = 0; i < VexNum; i++) {
		for (j = 0; j < VexNum; j++) {
			if (Matrix[i][j])
				arr[i][j] = Matrix[i][j];
			else
				arr[i][j] = 0xfffffff;
		}
	}
	closedge[0].vex = -1;
	closedge[0].lowcost = 0;
	for (i = 1; i < VexNum; i++) {
		closedge[i].vex = 0;
		closedge[i].lowcost = arr[0][i];
	}
	for (i = 0; i < VexNum - 1; i++) {
		min = 0xfffff;
		for (k = 0; k < VexNum; k++) {
			if (closedge[k].lowcost && closedge[k].lowcost < min) {
				min = closedge[k].lowcost;
				j = k;
			}
		}
		closedge[j].lowcost = 0;
		result[i] = j;
		for (k = 0; k < VexNum; k++) {
			if (closedge[k].lowcost && arr[j][k] < closedge[k].lowcost) {
				closedge[k].lowcost = arr[j][k];
				closedge[k].vex = j;
			}
		}
	}
}