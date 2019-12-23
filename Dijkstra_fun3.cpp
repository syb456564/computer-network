//�ļ������㷨���庯�������õϽ�˹���㷨�������·�� 

#include "Dijkstra_head.h"

//�㷨����
void Graph::Dijkstra(int from)
{
    int i, j, k;
    for (i = 0; i < this->vernum; i++)//��ʼ��node����
	{                                 //���õ�ǰ��·��
        node[i].path = "r" + to_string(from) + "-->r" + to_string(i + 1);
        node[i].value = adjmatrix[from - 1][i];
        node[i].visit = false;
    }
    node[from - 1].value = 0;         //�������ĵ�����·��Ϊ0
    node[from - 1].visit = true;

    for (i = 1; i < this->vernum; i++)//����ʣ��Ķ�������·��
	{
        int temp = 0;                 //temp���ڱ��浱ǰnode��������С���Ǹ��±�
        int min = MAX_VALUE;          //min��¼�ĵ�ǰ����Сֵ
        for (j = 0; j < this->vernum; j++)
		{
            if (!node[j].visit && node[j].value < min)
			{
                min = node[j].value;
                temp = j;
            }
        }
        node[temp].visit = true;     //��temp��Ӧ�Ķ�����뵽�Ѿ��ҵ������·���ļ�����
        for (k = 0; k < this->vernum; k++)
		{//����adjmatrix[temp][i]!=MAX_VALUE����ӣ���Ȼ�����������Ӷ���ɳ����쳣
            if (!node[k].visit && adjmatrix[temp][k]!=MAX_VALUE && (node[temp].value + adjmatrix[temp][k]) < node[k].value)
			{//����µõ��ı߿���Ӱ������Ϊ���ʵĶ��㣬������������·���ͳ���
                node[k].value = node[temp].value + adjmatrix[temp][k];
                node[k].path = node[temp].path + "-->r" + to_string(k + 1);
            }
        }
    }
}
