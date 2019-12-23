//此程序可以输出指定路由器路由表，该文件为主函数
 
#include "Dijkstra_head.h"

//主函数
int main(void)
{
    int vernum,edge;
    Graph graph;
    cout << "请输入拓扑的顶点个数和边条数：" << endl;
    cin >> vernum >> edge;
    while (! graph.Check(vernum, edge))
	{
        cout << "输入不合法！请重新输入！" << endl;
        cin >> vernum >> edge;
    }
    graph.Create_graph(vernum, edge);
    graph.Display_adjmatrix();
    system("pause");//按任意键继续...

    first:
    switch(graph.Menu())
    {
    	case 1:
    	{
    		system("cls"); //清除屏幕
    		int i;
			cout<<"请输入您想输出的路由表：r";
			cin>>i; 
			cout<<endl;
			graph.Dijkstra(i);
            graph.Display_table(i);
            graph.Display_adjmatrix();
			system("pause");
			goto first;
		}
		case 2:
    	{
    		system("cls");
    		graph.Del_edge();
			graph.Display_adjmatrix();
			system("pause");
			goto first;
		}
		case 3:
    	{
    		system("cls");
    		graph.Add_edge();
			graph.Display_adjmatrix();
			system("pause");
			goto first;
		}
		case 4:
    	{
    		system("cls");
    		graph.Del_vertex();
			graph.Display_adjmatrix();
			system("pause");
			goto first;
		}
		case 5:
    	{
    		system("cls");
    		graph.Add_vertex();
			graph.Display_adjmatrix();
			system("pause");
			goto first;
		}
	}
    return 0;
}
