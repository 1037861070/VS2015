#include"Tourism.h"

void GetGraphInfo() {
	int i, j;
	Vex vex;
	printf("顶点数目：%d\n", VexNum);
	printf("---------顶点-----------\n");
	for (i = 0; i < VexNum; i++) {
		vex = getVex(i);
		printf("%d-%s\n", vex.num, vex.name);
	}
	printf("----------边------------\n");
	for (i = 0; i < VexNum; i++)
		for (j = 0; j < VexNum; j++)
			if (j > i && Matrix[i][j])
				printf("<v%d,v%d> %d\n", i, j, Matrix[i][j]);
/*	for (i = 0; i < VexNum; i++) {
		for (j = 0; j < VexNum; j++)
			printf("%5d", Matrix[i][j]);
		printf("\n");
	}*/
}

void GetSpotInfo() {
	int i, v;
	Vex vex1, vex2;
	printf("请输入想要查询的景点编号：");
	scanf("%d", &v);
	vex1 = getVex(v);
	printf("%s\n%s\n", vex1.name, vex1.desc);
	printf("-------周边景区-------\n");
	for (i = 0; i < VexNum; i++)
		if (Matrix[v][i]) {
			vex2 = getVex(i);
			printf("%s->%s %dm\n", vex1.name, vex2.name, Matrix[v][i]);
		}
}

void GetPointInfo() {
	int i;
	Vex vex;
	for (i = 0; i < VexNum; i++) {
		vex = getVex(i);
		printf("%d-%s\n", vex.num, vex.name);
	}
}

void TravelPath() {
	int mark[20];
	int aPath[20];
	int index = 0, i, j, m;
	int count;
	int v;
	Vex vex;
	printf("请输入起始点编号：");
	scanf("%d", &v);
	memset(mark, 0, sizeof(mark));
	Initcount();
	count = DFS(v, mark, aPath, index);
	printf("导航路线为：\n");
	for (i = 0; i < count; i++) {
		vex = getVex(v);
		printf("路线%d: %s",i + 1,vex.name);
		for (j = 1; j < VexNum; j++) {
			m = Path[i][j];
			vex = getVex(m);
			printf(" -> %s", vex.name);
		}
		printf("\n");
	}
}

void FindSP() {
	int start, end;
	int aPath[20];
	int result[20];
	int num, i, m, n, weight = 0;
	Vex vex;
	printf("请输入起点的编号:");
	scanf("%d", &start);
	printf("请输入终点的编号:");
	scanf("%d", &end);
	FindShortPath(start, aPath);
	m = end;
	result[0] = end;
	num = 1;
	while (aPath[m] != start) {
		result[num] = aPath[m];
		m = aPath[m];
		num++;
	}
	result[num] = start;
	printf("最短路径为:");
	vex = getVex(start);
	printf("%s", vex.name);
	for (i = num; i > 0; i--) {
		n = result[i];
		m = result[i - 1];
		vex = getVex(m);
		weight += Matrix[n][m];
		printf("->%s", vex.name);
	}
	printf("\n最短距离为:%d\n",weight);
}

void DesignPath() {
	int i, j, k;
	Vex vex1, vex2;
	int sum = 0;
	prim();
	
	printf("在以下两个景点之间铺设电路:\n");
	for (i = 0; i < VexNum - 1; i++) {
		j = result[i];
		k = closedge[j].vex;
		vex1 = getVex(j);
		vex2 = getVex(k);
		printf("%s - %s  %dm\n", vex2.name, vex1.name, Matrix[k][j]);
		sum += Matrix[k][j];
	}
	printf("铺设电路的总长度为:%d\n", sum);
}