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
    		system("cls");  //清除屏幕
			graph.Dijkstra();
			system("pause");//按任意键继续 
			goto first;
		}
		case 2:
    	{
    		system("cls");
    		graph.Del_edge();
			system("pause");
			goto first;
		}
		case 3:
    	{
    		system("cls");
    		graph.Add_edge();
			system("pause");
			goto first;
		}
		case 4:
    	{
    		system("cls");
    		graph.Del_vertex();
			system("pause");
			goto first;
		}
		case 5:
    	{
    		system("cls");
    		graph.Add_vertex();
			system("pause");
			goto first;
		}
	}
    return 0;
}
