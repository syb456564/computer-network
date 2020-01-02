//文件包含程序菜单、检查输入边数
#include "Dijkstra_head.h"

//程序菜单 
int Graph::Menu()
{
	int i;
	do{
		system("cls");
		cout<<"**********路由表生成系统菜单********"<<endl<<endl;
		cout<<"            1.输出路由表            "<<endl;
		cout<<"            2.删除边                "<<endl;
		cout<<"            3.添加边                "<<endl;
		cout<<"            4.删除顶点              "<<endl;
		cout<<"            5.添加顶点              "<<endl;
		cout<<"            6.退出程序              "<<endl;	
		cout<<"            请输入您的选择：";
		cin>>i;
		}while(i<1||i>6);
	return i;
}
