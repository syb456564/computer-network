//�˳���������ָ��·����·�ɱ����ļ�Ϊ������
#include "Dijkstra_head.h"

//������
int main(void)
{
    int vernum,edge;
    Graph graph;
    cout << "���������˵�·���������ͱ�������" << endl;
    cin >> vernum >> edge;
    while (! graph.Check(vernum, edge))
	{
        cout << "���벻�Ϸ������������룡" << endl;
        cin >> vernum >> edge;
    }
    graph.Create_graph(vernum, edge);
    system("pause");      //�����������...

    first:
    switch(graph.Menu())
    {
    	case 1:
    	{
    		system("cls");//�����Ļ
			graph.Dijkstra();
			system("pause");
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
