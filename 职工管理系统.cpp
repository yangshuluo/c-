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
	//worker = new Employee(1, "张三", 1);
	//worker->showInfo();
	//delete worker;

	//worker = new Mannager(2, "李四", 1);
	//worker->showInfo();
	//delete worker;

	//worker = new Boss(3, "Echo", 1);
	//worker->showInfo();
	//delete worker;


	int choice = 0;
	//实例化对象
	WorkerMannager wm;


	while (true)
	{
		//显示初始界面
		wm.Show_Menu();
		//选择操作
		cin >> choice;
		switch (choice)
		{
		case 1:             //1、增加职工信息
			wm.Add_Emp();
			break;
		case 2:             //2、显示职工信息
			wm.Show_Emp();
			break;
		case 3:             //3、删除离职职工
			wm.Del_Emp();
			break;
		case 4:             //4、修改职工信息
			wm.Mod_Emp();
			break;
		case 5:             //5、查找职工信息
			wm.Find_Emp();
			break;
		case 6:             //6、按照编号排序
			wm.Sort_Emp();
			break;
		case 7:             //7、清空所有文档
			wm.Clean_File();
			break;
		case 0:             //0、退出管理系统
			wm.exitSystem();
			break;
		default:
			cout << "输入错误，请重新输入^^" << endl;
			system("pause");
			system("cls");
		}
	}

	system("pause");
	return 0;
}