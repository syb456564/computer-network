//�ļ��������·�ɱ��������� 
#include "Dijkstra_head.h"

//���·�ɱ� 
void Graph::Display_table(string from)
{
	int i;
	bool flag = false;
    cout << "·����" << from << "��·�ɱ����£�" << endl;
    for (i = 0; i < this->vernum; i++)
    {
    	if (from.compare(node[i].router) == 0)
    	   flag = true;
	}
	if (flag == false)
	    cout << "����Ϣ��" << endl;
	else
	{
		for (i = 0; i < this->vernum; i++)
	    {
			cout << "Ŀ�ĵأ�" << node[i].path[node[i].path.length()-1] << "  ";
			cout << "��һ����" << node[i].path[6] << "  ";
            cout << "Ȩֵ��" << node[i].value << endl;
        }
	}
    cout<<endl;
}

//��������
Graph::~Graph()
{
    delete[] node;                      //�ͷ�һά����node�ڴ� 
    for (int i = 0; i < MAX_VERNUM; i++)//�ͷŶ�ά����adjmatrix�ڴ�
	{
        delete this->adjmatrix[i];
    }
    delete adjmatrix;
}
