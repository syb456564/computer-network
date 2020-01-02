//该文件包含创建图函数
#include "Dijkstra_head.h"

//创建图
void Graph::Create_graph()
{
	ifstream in("dijkstra.txt");
	int vernum,edge;
    in >> vernum >> edge;                     //文件录入信息
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
    while (count < this->edge)
	{
        in >> start >> end >> value;          //文件录入信息 
        adjmatrix[start - 1][end - 1] = value;//对邻接矩阵对应上的点赋值
        adjmatrix[end - 1][start - 1] = value;
        count++;
    }

    for (int i = 0; i < this->vernum; i++)    //初始化node数组的路由器编号router 
	{
        node[i].router = "r" + to_string(i + 1);
    }
    in.close();
}
