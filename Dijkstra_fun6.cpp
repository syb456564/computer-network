//文件包含输出路由表、析构函数 

#include "Dijkstra_head.h"

//输出路由表 
void Graph::Display_table(int from)
{
    string str;
    str = "r" + to_string(from);//将数字常量from转换为字符串，返回值为转换完毕的字符串
    cout << "路由器" << str << "的路由表如下：" << endl;
    for (int i = 0; i < this->vernum; i++)
	{
        if(node[i].value != MAX_VALUE)
        {
			cout << "目的地：" << node[i].path[node[i].path.length()-1] << "  ";
			cout << "下一跳：" << node[i].path[6] << "  ";
            cout << "权值：" << node[i].value << endl;
        }
    }
    cout<<endl;
}

//析构函数
Graph::~Graph()
{
    delete[] node;//释放一维数组node内存 
    for (int i = 0; i < MAX_VERNUM; i++)//释放二维数组adjmatrix内存
	{
        delete this->adjmatrix[i];
    }
    delete adjmatrix;
}
