//该文件包含删除边、顶点函数 

#include "Dijkstra_head.h"

//删除边
void Graph::Del_edge()
{
	int from, to;
	cout << "请输入您要删除的边（格式：起点 终点）";
	cin >> from >> to;
	adjmatrix[from - 1][to - 1] = MAX_VALUE;//对邻接矩阵对应上的点赋值
    adjmatrix[to - 1][from - 1] = MAX_VALUE;
    this->edge--;
}

//删除顶点
void Graph::Del_vertex()
{
	int r, i, j, count = 0;
	cout << "请输入您要删除的路由器r";
	cin >> r;
	r = r - 1;
	
	for (i = 0; i < this->vernum; i++)      //统计与删除的顶点相关的边数 
	{
		if(adjmatrix[r][i] != MAX_VALUE)
		    count++;
	}
    for(i = 0;i < this->vernum; i++)        //调整邻接矩阵
    {
        for(j = 0;j < this->vernum; j++)    //将邻接矩阵向内紧缩
        {
            if(i > r && j > r)              //调整右下角部分 
                adjmatrix[i-1][j-1] = adjmatrix[i][j];
            else if(i > r)                  //调整右上角部分
                adjmatrix[i-1][j] = adjmatrix[i][j];
            else if(j > r)                  //调整左下角部分
                adjmatrix[i][j-1] = adjmatrix[i][j];
        }
    }

    for(i = 0;i < this->vernum; i++)
    	adjmatrix[this->vernum][i] = MAX_VALUE;
    for(i = 0;i < this->vernum; i++)
        adjmatrix[i][this->vernum] = MAX_VALUE;
    for(i = r; i < this->vernum-1; i++)     //调整顶点数组值
        node[i] = node[i+1];
    this->vernum--;
    this->edge = this->edge - count;
}
