//文件包含输出路由表、析构函数 
#include "Dijkstra_head.h"

//输出路由表 
void Graph::Display_table(string from)
{
	int i;
	bool flag = false;
    cout << "路由器" << from << "的路由表如下：" << endl;
    for (i = 0; i < this->vernum; i++)
    {
    	if (from.compare(node[i].router) == 0)
    	   flag = true;
	}
	if (flag == false)
	    cout << "无信息！" << endl;
	else
	{
		for (i = 0; i < this->vernum; i++)
	    {
			cout << "目的地：" << node[i].des_router << "  ";
			if (node[i].next_router[2] >= '0' && node[i].next_router[2] <='9')
			    cout << "下一跳：r" << node[i].next_router[1] << node[i].next_router[2] << "  ";
			else
			    cout << "下一跳：r" << node[i].next_router[1] << "  ";
            cout << "权值：" << node[i].value << endl;
        }
	}
    cout<<endl;
}

//析构函数
Graph::~Graph()
{
    delete[] node;                      //释放一维数组node内存
    for (int i = 0; i < MAX_VERNUM; i++)//释放二维数组adjmatrix内存
	{
        delete this->adjmatrix[i];
    }
    delete adjmatrix;
}
