#include<iostream>
#include<string>
#include"SpeechManager.h"
#include<ctime>


using namespace std;



int main()
{
	srand(unsigned int(time(NULL)));
	SpeechManager sm;
	//����ѡ�ֵĴ���
	//for (map<int, Speaker>::iterator it = sm.m_Speaker.begin(); it != sm.m_Speaker.end(); it++)
	//{
	//	cout << "ѡ�ֱ��----" << it->first << "    ѡ������----" << it->second.m_Name << "    ѡ�ַ���----" << it->second.m_Score[0] << endl;
	//}


	int choice = 0;
	while (true)
	{
		sm.show_Menu();
		cout << "���������ѡ��" ;
		cin >> choice;

		switch (choice)
		{
		case 1:              //��ʼ����
			sm.startSpeech();
			break;
		case 2:              //�鿴��¼
			sm.showRecord();
			break;
		case 3:              //��ռ�¼
			sm.clearRecord();
			break;
		case 0:              //�˳�ϵͳ
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