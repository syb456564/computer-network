//文件包含添加边、顶点函数 
#include "Dijkstra_head.h"

//添加边
void Graph::Add_edge()
{
	string from, to;
	int f, t, value;
	cout << "请输入您要添加的边（格式：起点 终点 权值）";
	cin >> from >> to >> value;
	for (f = 0; f < this->vernum; f++)    //找到起点对应的数组坐标 
	{
		if (from.compare(node[f].router) == 0)
		    break;
    }
    for (t = 0; t < this->vernum; t++)    //找到终点对应的数组坐标 
	{
		if (to.compare(node[t].router) == 0)
			break;
	}
	adjmatrix[f][t] = value;              //对邻接矩阵对应上的点赋值
    adjmatrix[t][f] = value;
    this->edge++;
}

//添加顶点
void Graph::Add_vertex()
{
    int i, j, e, value;
    string from, to;
	cout << "请输入与添加的路由器相邻的边数：";
	cin >> e;
	cout << "请依次输入每条边及其权值（格式：起点 终点 权值）" << endl;
	for(i = 0; i < e; i++)
	{
		cin >> from >> to >> value;
		for (j = 0; j < this->vernum; j++)//找到终点对应的数组坐标 
	    {
		    if (to.compare(node[j].router) == 0)
		    	break;
	    }
		adjmatrix[this->vernum][j] = value;
		adjmatrix[j][this->vernum] = value;
		node[this->vernum].router = from;
	}
	this->vernum++;
	this->edge = this->edge + e;
}
