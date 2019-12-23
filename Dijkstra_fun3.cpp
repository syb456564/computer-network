//文件包含算法主体函数，利用迪杰斯拉算法计算最短路径 

#include "Dijkstra_head.h"

//算法主体
void Graph::Dijkstra(int from)
{
    int i, j, k;
    for (i = 0; i < this->vernum; i++)//初始化node数组
	{                                 //设置当前的路径
        node[i].path = "r" + to_string(from) + "-->r" + to_string(i + 1);
        node[i].value = adjmatrix[from - 1][i];
        node[i].visit = false;
    }
    node[from - 1].value = 0;         //设置起点的到起点的路径为0
    node[from - 1].visit = true;

    for (i = 1; i < this->vernum; i++)//计算剩余的顶点的最短路径
	{
        int temp = 0;                 //temp用于保存当前node数组中最小的那个下标
        int min = MAX_VALUE;          //min记录的当前的最小值
        for (j = 0; j < this->vernum; j++)
		{
            if (!node[j].visit && node[j].value < min)
			{
                min = node[j].value;
                temp = j;
            }
        }
        node[temp].visit = true;     //把temp对应的顶点加入到已经找到的最短路径的集合中
        for (k = 0; k < this->vernum; k++)
		{//条件adjmatrix[temp][i]!=MAX_VALUE必须加，不然会出现溢出，从而造成程序异常
            if (!node[k].visit && adjmatrix[temp][k]!=MAX_VALUE && (node[temp].value + adjmatrix[temp][k]) < node[k].value)
			{//如果新得到的边可以影响其他为访问的顶点，则更新它的最短路径和长度
                node[k].value = node[temp].value + adjmatrix[temp][k];
                node[k].path = node[temp].path + "-->r" + to_string(k + 1);
            }
        }
    }
}
