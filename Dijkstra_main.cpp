//�˳���������ָ��·����·�ɱ����ļ�Ϊ������
#include "Dijkstra_head.h"

//������
int main(void)
{
	Graph graph;
    graph.Create_graph();
    first:
    switch(graph.Menu())
    {
    	case 1:
    	{
    		system("cls");     //�����Ļ
			graph.Dijkstra();  //�����㷨�������·�ɱ�
			system("pause");   //����������� 
			goto first;
		}
		case 2:
    	{
    		system("cls");
    		graph.Del_edge();  //ɾ����
			system("pause");
			goto first;
		}
		case 3:
    	{
    		system("cls");
    		graph.Add_edge();  //���ӱ�
			system("pause");
			goto first;
		}
		case 4:
    	{
    		system("cls");
    		graph.Del_vertex();//ɾ������
			system("pause");
			goto first;
		}
		case 5:
    	{
    		system("cls");
    		graph.Add_vertex();//���Ӷ���
			system("pause");
			goto first;
		}
	}
    return 0;
}
