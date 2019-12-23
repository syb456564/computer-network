//�ļ�������¼��㵽ÿ����������·������Ϣ�ṹ���Լ�ͼ��
#ifndef DIJKSTRA_HEAD_H_
#define DIJKSTRA_HEAD_H_
#include <string>
#include <fstream>
#include <iostream>
#define MAX_VERNUM 20//��󶥵���
#define MAX_VALUE 999//���Ȩֵ
using namespace std;

//��¼��㵽ÿ����������·������Ϣ
struct Node
{
    string path;                            //·��
    string router;                          //·�������
    int value;                              //·��Ȩֵ
    bool visit;                             //�Ƿ���ʹ�
    Node(){visit = false; value = 0; router = ""; path = "";}
};                                          //���캯������ʼ��

//ͼ��
class Graph
{
public:
    Graph(){}                               //���캯��
    ~Graph();                               //�������� 
    void Create_graph();                    //����ͼ
    void Dijkstra();                        //��˹���㷨���������·��
    void Display_table(string from);        //���·�ɱ� 
    void Add_edge();                        //��ӱ�
	void Del_edge();                        //ɾ����
	void Add_vertex();                      //��Ӷ���
	void Del_vertex();                      //ɾ������
	int Menu();                             //����˵�
private:
    int vernum;                             //ͼ�Ķ������
    int edge;                               //ͼ�ı���
    int **adjmatrix;                        //�ڽӾ���
    Node *node;                             //��¼�����������·������Ϣ
};

#endif
