#include<iostream>
#include<string>
#include"workerMessager.h"
#include"Worker.h"
#include"Employee.h"
#include"Boss.h"
#include"Mannager.h"


using namespace std;

int main()
{
	//Worker *worker = NULL;
	//worker = new Employee(1, "����", 1);
	//worker->showInfo();
	//delete worker;

	//worker = new Mannager(2, "����", 1);
	//worker->showInfo();
	//delete worker;

	//worker = new Boss(3, "Echo", 1);
	//worker->showInfo();
	//delete worker;


	int choice = 0;
	//ʵ��������
	WorkerMannager wm;


	while (true)
	{
		//��ʾ��ʼ����
		wm.Show_Menu();
		//ѡ�����
		cin >> choice;
		switch (choice)
		{
		case 1:             //1������ְ����Ϣ
			wm.Add_Emp();
			break;
		case 2:             //2����ʾְ����Ϣ
			wm.Show_Emp();
			break;
		case 3:             //3��ɾ����ְְ��
			wm.Del_Emp();
			break;
		case 4:             //4���޸�ְ����Ϣ
			wm.Mod_Emp();
			break;
		case 5:             //5������ְ����Ϣ
			wm.Find_Emp();
			break;
		case 6:             //6�����ձ������
			wm.Sort_Emp();
			break;
		case 7:             //7����������ĵ�
			wm.Clean_File();
			break;
		case 0:             //0���˳�����ϵͳ
			wm.exitSystem();
			break;
		default:
			cout << "�����������������^^" << endl;
			system("pause");
			system("cls");
		}
	}

	system("pause");
	return 0;
}