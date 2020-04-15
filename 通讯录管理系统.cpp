#include<iostream>
#include<string>
#define MAX 1000 //宏定义

using namespace std;

//显示初始界面
void showMenu() 
{
	cout << "***************" << endl;
	cout << "*1、添加联系人*\n*2、显示联系人*\n*3、删除联系人*\n*4、查找联系人*\n*5、修改联系人*\n*6、清空联系人*\n*0、退出通讯录*" << endl;
	cout << "***************" << endl;
	cout << "请选择操作：";
}

struct Person    //通讯录人员信息结构体
{
	string m_Name;
	int m_Sex;
	int m_Age;
	string m_Phone;
	string m_Addr;
};

struct Addressbooks   //通讯录结构体
{
	struct Person personArray[MAX];  //保存联系人数组
	int m_Size;   //通讯录人员个数
};

//添加联系人
void addPerson(Addressbooks *abs)  //接收地址，左端改变地址
{
	if (abs->m_Size == MAX)
	{
		cout << "通讯录已满" << endl;
	}
	else
	{
		//姓名
		string name;
		cout << "请输入姓名：";
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name; //将姓名放到通讯录中
		//性别
		cout << "请输入性别：";
		cout << "1--男" << "  " << "2--女" << endl;
		
		int sex = 0;
		while (true)
		{
			cout << "请输入性别：";
			//只能输入1 、 2
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}
		//年龄
		cout << "请输入年龄：" ;
		int age = 0;
		while (true)
		{
			cin >> age;
			if (age < 0 || age > 120)
			{
				cout << "输入有误，请重新输入" << endl;
			}
			else
			{
				abs->personArray[abs->m_Size].m_Age = age;
				break;
			}
		}
		//电话
		cout << "请输入电话：";
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;
		//地址
		cout << "请输入地址: ";
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;

		//更新通讯录人数
		abs->m_Size++;
		cout << "添加成功！！！" << endl;

		system("pause"); //请按任意键
		system("cls"); //清屏操作
	}
}

//显示联系人
void showPerson(Addressbooks *abs)
{
	if (abs->m_Size == 0)
	{
		cout << "当前记录为空 ！！！" << endl;
		system("pause"); //请按任意键
		system("cls"); //清屏操作
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "姓名：" << abs->personArray[i].m_Name << "  ";
			cout << "性别：" << (abs->personArray[i].m_Sex == 1 ? "男" : "女") << "  ";  //三目运算符
			cout << "年龄：" << abs->personArray[i].m_Age << "  ";
			cout << "电话：" << abs->personArray[i].m_Phone << "  ";
			cout << "地址：" << abs->personArray[i].m_Addr << endl;
		}
		system("pause"); //请按任意键
		system("cls"); //清屏操作
	}
}


//检测联系人是否存在
int isExist(Addressbooks *abs, string name) //有参返回
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		//找到用户姓名
		if (abs->personArray[i].m_Name == name)
		{
			return i;
		}
	}
	//没找到返回-1
	return -1;
}

//删除联系人
void delePerson(Addressbooks *abs)
{
	cout << "请输入您要删除的联系人" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1)
	{
		//用数据前移的操作进行删除
		for (int i = ret; i < abs->m_Size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;//更新人数
		cout << "删除成功！！！" << endl;
	}
	else
	{
		cout << "查无此人 ,请重新输入！！！" << endl;
	}
	system("pause"); //请按任意键
	system("cls"); //清屏操作
}

//查找联系人
void findPerson(Addressbooks *abs)
{
	cout << "请输入您要查找的联系人：";
	string name;
	cin >> name;

	//判断
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "姓名：" << abs->personArray[ret].m_Name << "  ";
		cout << "性别：" << (abs->personArray[ret].m_Sex == 1 ? "男" : "女") << "  ";  //三目运算符
		cout << "年龄：" << abs->personArray[ret].m_Age << "  ";
		cout << "电话：" << abs->personArray[ret].m_Phone << "  ";
		cout << "地址：" << abs->personArray[ret].m_Addr << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause"); //请按任意键
	system("cls"); //清屏操作
}


//修改联系人
void modPerson(Addressbooks *abs)
{
	cout << "请输入你要修改的联系人：";
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "请输入你要修改的联系人信息！！！" << endl;
		cout << "请输入姓名：";
		cin >> name;
		abs->personArray[ret].m_Name = name; //将姓名放到通讯录中
		//性别
		cout << "请输入性别：";
		cout << "1--男" << "  " << "2--女" << endl;

		int sex = 0;
		while (true)
		{
			cout << "请输入性别：";
			//只能输入1 、 2
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}
		//年龄
		cout << "请输入年龄：";
		int age = 0;
		while (true)
		{
			cin >> age;
			if (age < 0 || age > 120)
			{
				cout << "输入有误，请重新输入" << endl;
			}
			else
			{
				abs->personArray[ret].m_Age = age;
				break;
			}
		}
		//电话
		cout << "请输入电话：";
		string phone;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;
		//地址
		cout << "请输入地址: ";
		string address;
		cin >> address;
		abs->personArray[ret].m_Addr = address;

		//更新通讯录人数
		cout << "修改成功！！！" << endl;
	}
	else
	{
		cout << "查无此人 ,请重新输入！！！" << endl;
	}
	system("pause"); //请按任意键
	system("cls"); //清屏操作
}

//清空联系人
void cleanPerson(Addressbooks *abs)
{
	int judge;
	cout << "是否要清空全部联系人，按1---是 2---否" << endl;
	cin >> judge;
	if (judge == 1)
	{
		abs->m_Size = 0;
		cout << "通讯录已清空！！！" << endl;
	}
	else if(judge == 2)
	{
		cout << "已退出" << endl;;
	}

	system("pause"); //请按任意键
	system("cls"); //清屏操作
}

int main()
{
	int select = 0;
	//创建通讯录结构体变量
	Addressbooks abs;
	//初始化通讯录人员个数
	abs.m_Size = 0;

	while (true)
	{
		//显示初始界面
		showMenu();
		//选择操作
		cin >> select;
		switch (select)
		{
		case 1:             //1、添加联系人
			addPerson(&abs);  //传添加人地址
			break;
		case 2:             //2、显示联系人
			showPerson(&abs);
			break;
		case 3:             //3、删除联系人
			delePerson(&abs);
			break;
		case 4:             //4、查找联系人
			findPerson(&abs);
			break;
		case 5:             //5、修改联系人
			modPerson(&abs);
			break;
		case 6:             //6、清空联系人
			cleanPerson(&abs);
			break;
		case 0:             //0、退出通讯录
			cout << "欢迎下次使用，再见^^" << endl;
			return 0;
			break;
		default:
			cout << "输入错误，请重新输入^^" << endl;
			break;
		}
	}
	
	system("pause");
	return 0;
}