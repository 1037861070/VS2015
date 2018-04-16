#ifndef TOURISM
#define TOURISM

void CreateGraph(Graph *p);//读取文件，创建景点图

void GetSpotInfo(Graph *p);//查询指定景点信息，显示到相邻景点的距离

void TravelPath(Graph *p);//旅游景点导航

void findShortPath(Graph *p);//搜索最短路径

void DesingPath(Graph *p);//铺设电路
#endif 
