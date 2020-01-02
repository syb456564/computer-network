//此程序可以输出指定路由器路由表，该文件为主函数
#include "Dijkstra_head.h"

//主函数
int main(void)
{
	Graph graph;
    graph.Create_graph();
    first:
    switch(graph.Menu())
    {
    	case 1:
    	{
    		system("cls");     //清除屏幕
			graph.Dijkstra();  //调用算法主体输出路由表
			system("pause");   //按任意键继续 
			goto first;
		}
		case 2:
    	{
    		system("cls");
    		graph.Del_edge();  //删除边
			system("pause");
			goto first;
		}
		case 3:
    	{
    		system("cls");
    		graph.Add_edge();  //增加边
			system("pause");
			goto first;
		}
		case 4:
    	{
    		system("cls");
    		graph.Del_vertex();//删除顶点
			system("pause");
			goto first;
		}
		case 5:
    	{
    		system("cls");
    		graph.Add_vertex();//增加顶点
			system("pause");
			goto first;
		}
	}
    return 0;
}
