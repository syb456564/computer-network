//���ļ���������ͼ����
#include "Dijkstra_head.h"

//����ͼ
void Graph::Create_graph(int vernum, int edge)
{
    this->vernum = vernum;                    //��ʼ���������ͱ���
    this->edge = edge;
    node = new Node[MAX_VERNUM];              //����������Ϣ�����й���MAX_VERNUM����
    adjmatrix = new int*[MAX_VERNUM];         //����һά����ΪMAX_VERNUM
    for (int i = 0; i < MAX_VERNUM; i++)
	{
        adjmatrix[i] = new int[MAX_VERNUM];   //�����ά����ҲΪMAX_VERNUM
        for (int k = 0; k < MAX_VERNUM; k++)
		{
            adjmatrix[i][k] = MAX_VALUE;      //�ڽӾ����ʼ��Ϊ�����
        }
    }

	int start, end, value, count = 0;
    cout << "������ÿ���ߵ������յ㣨·������Ŵ�1��ʼ���Լ���Ȩֵ" << endl;
    while (count < this->edge)
	{
        cin >> start >> end >> value;
        adjmatrix[start - 1][end - 1] = value;//���ڽӾ����Ӧ�ϵĵ㸳ֵ
        adjmatrix[end - 1][start - 1] = value;
        count++;
    }

    for (int i = 0; i < this->vernum; i++)    //��ʼ��node�����·�������router 
	{
        node[i].router = "r" + to_string(i + 1);
    }
}
