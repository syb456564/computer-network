//该文件包含删除边、顶点函数 
#include "Dijkstra_head.h"

//删除边
void Graph::Del_edge()
{
	string from, to;
	int r, i, j;
	cout << "请输入您要删除的边（格式：起点 终点）";
	cin >> from >> to;
	for (i = 0; i < this->vernum; i++)
	{
		if (from.compare(node[i].router) == 0)
			break;
	}
	for (j = 0; j < this->vernum; j++)
	{
		if (to.compare(node[j].router) == 0)
			break;
	}
	adjmatrix[i][j] = MAX_VALUE;        //对邻接矩阵对应上的点赋值
    adjmatrix[j][i] = MAX_VALUE;
    this->edge--;
}

//删除顶点
void Graph::Del_vertex()
{
	string r1;
	int r2, i, j, count = 0;
	cout << "请输入您要删除的路由器：";
	cin >> r1;
	for (r2 = 0; r2 < this->vernum; r2++)
	{
		if (r1.compare(node[r2].router) == 0)
			break;
	}
	for (i = 0; i < this->vernum; i++)  //统计与删除的顶点相关的边数 
	{
		if(adjmatrix[r2][i] != MAX_VALUE)
		    count++;
	}

    for(i = 0;i < this->vernum; i++)    //调整邻接矩阵
    {
        for(j = 0;j < this->vernum; j++)//将邻接矩阵向内紧缩
        {
            if(i > r2 && j > r2)        //调整右下角部分
                adjmatrix[i-1][j-1] = adjmatrix[i][j];
            else if(i > r2)             //调整右上角部分
                adjmatrix[i-1][j] = adjmatrix[i][j];
            else if(j > r2)             //调整左下角部分
                adjmatrix[i][j-1] = adjmatrix[i][j];
        }
    }
    for(i = 0;i < this->vernum; i++)
    	adjmatrix[this->vernum][i] = MAX_VALUE;
    for(i = 0;i < this->vernum; i++)
        adjmatrix[i][this->vernum] = MAX_VALUE;
    for(i = r2; i < this->vernum-1; i++)//调整顶点数组值
        node[i] = node[i+1];
    this->vernum--;
    this->edge = this->edge - count;
}
