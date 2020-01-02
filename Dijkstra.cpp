//文件包含算法主体函数，利用迪杰斯拉算法计算最短路径 

#include "Dijkstra_head.h"
//算法主体
void Graph::Dijkstra()
{
    int f, i, j, k;
    string from;
	cout<<"请输入您想输出的路由表：";
	cin >> from;
	cout << endl;
	for (f = 0; f < this->vernum; f++)
	{
		if (from.compare(node[f].router) == 0)
			break;
	}
    for (i = 0; i < this->vernum; i++)
	{                           //初始化node数组
        node[i].next_router = node[i].router;
        node[i].des_router = node[i].router;
        node[i].value = adjmatrix[f][i];
        node[i].visit = false;
    }
    node[f].value = 0;          //设置起点的到起点的路径为0
    node[f].visit = true;

    for (i = 1; i < this->vernum; i++)
	{                           //计算剩余的顶点的最短路径
        int temp = 0;           //temp用于保存当前node数组中最小的那个下标
        int min = MAX_VALUE;    //min记录的当前的最小值
        for (j = 0; j < this->vernum; j++)
		{
            if (!node[j].visit && node[j].value < min)
			{
                min = node[j].value;
                temp = j;
            }
        }
        node[temp].visit = true;//把temp对应的顶点加入到已经找到的最短路径的集合中
        for (k = 0; k < this->vernum; k++)
		{
            if (!node[k].visit && adjmatrix[temp][k] != MAX_VALUE && (node[temp].value + adjmatrix[temp][k]) < node[k].value)
			{                   //如果新得到的边可以影响其他为访问的顶点，则更新它的最短路径和长度
                node[k].des_router = node[k].router;
                node[k].next_router = node[temp].next_router + node[k].router;
                node[k].value = node[temp].value + adjmatrix[temp][k];
            }
        }
    }
    Display_table(from);        //打印路由表
}
