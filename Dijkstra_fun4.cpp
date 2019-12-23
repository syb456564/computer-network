//文件输出邻接矩阵函数 

#include "Dijkstra_head.h"

//输出邻接矩阵
void Graph::Display_adjmatrix()
{
    cout << "拓扑的邻接矩阵为：" << endl;
    int count_row;
    int count_col;
    for (count_row = 0; count_row < this->vernum; count_row++)
	{
        count_col = 0;
        for (count_col = 0; count_col < this->vernum; count_col++)
		{
            if (adjmatrix[count_row][count_col] == MAX_VALUE)
                cout << "∞" << " ";
            else
                cout << adjmatrix[count_row][count_col] << " ";
        }
        cout << endl;
    }
}
