#include<iostream>
#include<string>
#include"SpeechManager.h"
#include<ctime>


using namespace std;



int main()
{
	srand(unsigned int(time(NULL)));
	SpeechManager sm;
	//测试选手的创建
	//for (map<int, Speaker>::iterator it = sm.m_Speaker.begin(); it != sm.m_Speaker.end(); it++)
	//{
	//	cout << "选手编号----" << it->first << "    选手姓名----" << it->second.m_Name << "    选手分数----" << it->second.m_Score[0] << endl;
	//}


	int choice = 0;
	while (true)
	{
		sm.show_Menu();
		cout << "请输入你的选择：" ;
		cin >> choice;

		switch (choice)
		{
		case 1:              //开始比赛
			sm.startSpeech();
			break;
		case 2:              //查看记录
			sm.showRecord();
			break;
		case 3:              //清空记录
			sm.clearRecord();
			break;
		case 0:              //退出系统
			sm.exitSystem();
			break;
		default:
			system("cls");
			break;
		}


	}
	system("pause");
	return 0;
}