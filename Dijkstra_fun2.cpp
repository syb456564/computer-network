//���ļ�����ɾ���ߡ����㺯�� 

#include "Dijkstra_head.h"

//ɾ����
void Graph::Del_edge()
{
	int from, to;
	cout << "��������Ҫɾ���ıߣ���ʽ����� �յ㣩";
	cin >> from >> to;
	adjmatrix[from - 1][to - 1] = MAX_VALUE;//���ڽӾ����Ӧ�ϵĵ㸳ֵ
    adjmatrix[to - 1][from - 1] = MAX_VALUE;
    this->edge--;
}

//ɾ������
void Graph::Del_vertex()
{
	int r, i, j, count = 0;
	cout << "��������Ҫɾ����·����r";
	cin >> r;
	r = r - 1;
	
	for (i = 0; i < this->vernum; i++)      //ͳ����ɾ���Ķ�����صı��� 
	{
		if(adjmatrix[r][i] != MAX_VALUE)
		    count++;
	}
    for(i = 0;i < this->vernum; i++)        //�����ڽӾ���
    {
        for(j = 0;j < this->vernum; j++)    //���ڽӾ������ڽ���
        {
            if(i > r && j > r)              //�������½ǲ��� 
                adjmatrix[i-1][j-1] = adjmatrix[i][j];
            else if(i > r)                  //�������Ͻǲ���
                adjmatrix[i-1][j] = adjmatrix[i][j];
            else if(j > r)                  //�������½ǲ���
                adjmatrix[i][j-1] = adjmatrix[i][j];
        }
    }

    for(i = 0;i < this->vernum; i++)
    	adjmatrix[this->vernum][i] = MAX_VALUE;
    for(i = 0;i < this->vernum; i++)
        adjmatrix[i][this->vernum] = MAX_VALUE;
    for(i = r; i < this->vernum-1; i++)     //������������ֵ
        node[i] = node[i+1];
    this->vernum--;
    this->edge = this->edge - count;
}
