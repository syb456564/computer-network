//文件包含添加边、顶点函数 

#include "Dijkstra_head.h"

//添加边
void Graph::Add_edge()
{
	int from, to, value;
	cout << "请输入您要添加的边（格式：起点 终点 权值）";
	cin >> from >> to >> value;
	adjmatrix[from - 1][to - 1] = value;//对邻接矩阵对应上的点赋值
    adjmatrix[to - 1][from - 1] = value;
    this->edge++;
}

//添加顶点
void Graph::Add_vertex()
{
    int i, e, to, value;
	cout<<"请输入与添加的顶点r"<<this->vernum+1<<"相邻的边数"<<endl;
	cin >> e;
	cout<<"请依次输入每条边及其权值（格式：终点 权值）"<<endl; 
	for(i = 0; i < e; i++)
	{
		cin >> to >> value;
		adjmatrix[this->vernum][to-1] = value;
		adjmatrix[to-1][this->vernum] = value;
	}
	this->vernum++;
	this->edge = this->edge + e;
}
