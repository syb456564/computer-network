//该文件包含创建图函数
#include "Dijkstra_head.h"

//创建图
void Graph::Create_graph(int vernum, int edge)
{
    this->vernum = vernum;                    //初始化顶点数和边数
    this->edge = edge;
    node = new Node[MAX_VERNUM];              //保留顶点信息，其中共有MAX_VERNUM条边
    adjmatrix = new int*[MAX_VERNUM];         //数组一维长度为MAX_VERNUM
    for (int i = 0; i < MAX_VERNUM; i++)
	{
        adjmatrix[i] = new int[MAX_VERNUM];   //数组二维长度也为MAX_VERNUM
        for (int k = 0; k < MAX_VERNUM; k++)
		{
            adjmatrix[i][k] = MAX_VALUE;      //邻接矩阵初始化为无穷大
        }
    }

	int start, end, value, count = 0;
    cout << "请输入每条边的起点和终点（路由器编号从1开始）以及其权值" << endl;
    while (count < this->edge)
	{
        cin >> start >> end >> value;
        adjmatrix[start - 1][end - 1] = value;//对邻接矩阵对应上的点赋值
        adjmatrix[end - 1][start - 1] = value;
        count++;
    }

    for (int i = 0; i < this->vernum; i++)    //初始化node数组的路由器编号router 
	{
        node[i].router = "r" + to_string(i + 1);
    }
}
