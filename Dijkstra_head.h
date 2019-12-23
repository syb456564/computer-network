#ifndef DIJKSTRA_HEAD_H_
#define DIJKSTRA_HEAD_H_
#include<string>
//�ļ�������¼��㵽ÿ����������·������Ϣ�ṹ���Լ�ͼ��

#include<iostream>
#define MAX_VERNUM 20//��󶥵���
#define MAX_VALUE 999//���Ȩֵ
using namespace std;

//��¼��㵽ÿ����������·������Ϣ
struct Node
{
    string path;                                //·��
    int value;                                  //·��Ȩֵ
    bool visit;                                 //�Ƿ���ʹ�
    Node(){visit = false; value = 0; path = "";}//���캯������ʼ��
};

//ͼ��
class Graph
{
public:
    Graph(){}//���캯��
    ~Graph();//��������
    bool Check(int Vexnum, int edge);//�������ı����붥��Ĺ�ϵ�Ƿ���� 
    void Create_graph(int vernum, int edge);//����ͼ
    void Display_adjmatrix();//����ڽӾ���
    void Dijkstra(int from);//��˹���㷨���������·��
    void Display_table(int from);//���·�ɱ� 
    void Add_edge();//��ӱ�
	void Del_edge();//ɾ����
	void Add_vertex();//��Ӷ���
	void Del_vertex();//ɾ������
	int Menu();//����˵�
private:
    int vernum;   //ͼ�Ķ������
    int edge;     //ͼ�ı���
    int **adjmatrix;   //�ڽӾ���
    Node *node;   //��¼�����������·������Ϣ
};

#endif
