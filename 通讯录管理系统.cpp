#include<iostream>
#include<string>
#define MAX 1000 //�궨��

using namespace std;

//��ʾ��ʼ����
void showMenu() 
{
	cout << "***************" << endl;
	cout << "*1�������ϵ��*\n*2����ʾ��ϵ��*\n*3��ɾ����ϵ��*\n*4��������ϵ��*\n*5���޸���ϵ��*\n*6�������ϵ��*\n*0���˳�ͨѶ¼*" << endl;
	cout << "***************" << endl;
	cout << "��ѡ�������";
}

struct Person    //ͨѶ¼��Ա��Ϣ�ṹ��
{
	string m_Name;
	int m_Sex;
	int m_Age;
	string m_Phone;
	string m_Addr;
};

struct Addressbooks   //ͨѶ¼�ṹ��
{
	struct Person personArray[MAX];  //������ϵ������
	int m_Size;   //ͨѶ¼��Ա����
};

//�����ϵ��
void addPerson(Addressbooks *abs)  //���յ�ַ����˸ı��ַ
{
	if (abs->m_Size == MAX)
	{
		cout << "ͨѶ¼����" << endl;
	}
	else
	{
		//����
		string name;
		cout << "������������";
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name; //�������ŵ�ͨѶ¼��
		//�Ա�
		cout << "�������Ա�";
		cout << "1--��" << "  " << "2--Ů" << endl;
		
		int sex = 0;
		while (true)
		{
			cout << "�������Ա�";
			//ֻ������1 �� 2
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "������������������" << endl;
		}
		//����
		cout << "���������䣺" ;
		int age = 0;
		while (true)
		{
			cin >> age;
			if (age < 0 || age > 120)
			{
				cout << "������������������" << endl;
			}
			else
			{
				abs->personArray[abs->m_Size].m_Age = age;
				break;
			}
		}
		//�绰
		cout << "������绰��";
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;
		//��ַ
		cout << "�������ַ: ";
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;

		//����ͨѶ¼����
		abs->m_Size++;
		cout << "��ӳɹ�������" << endl;

		system("pause"); //�밴�����
		system("cls"); //��������
	}
}

//��ʾ��ϵ��
void showPerson(Addressbooks *abs)
{
	if (abs->m_Size == 0)
	{
		cout << "��ǰ��¼Ϊ�� ������" << endl;
		system("pause"); //�밴�����
		system("cls"); //��������
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "������" << abs->personArray[i].m_Name << "  ";
			cout << "�Ա�" << (abs->personArray[i].m_Sex == 1 ? "��" : "Ů") << "  ";  //��Ŀ�����
			cout << "���䣺" << abs->personArray[i].m_Age << "  ";
			cout << "�绰��" << abs->personArray[i].m_Phone << "  ";
			cout << "��ַ��" << abs->personArray[i].m_Addr << endl;
		}
		system("pause"); //�밴�����
		system("cls"); //��������
	}
}


//�����ϵ���Ƿ����
int isExist(Addressbooks *abs, string name) //�вη���
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		//�ҵ��û�����
		if (abs->personArray[i].m_Name == name)
		{
			return i;
		}
	}
	//û�ҵ�����-1
	return -1;
}

//ɾ����ϵ��
void delePerson(Addressbooks *abs)
{
	cout << "��������Ҫɾ������ϵ��" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1)
	{
		//������ǰ�ƵĲ�������ɾ��
		for (int i = ret; i < abs->m_Size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;//��������
		cout << "ɾ���ɹ�������" << endl;
	}
	else
	{
		cout << "���޴��� ,���������룡����" << endl;
	}
	system("pause"); //�밴�����
	system("cls"); //��������
}

//������ϵ��
void findPerson(Addressbooks *abs)
{
	cout << "��������Ҫ���ҵ���ϵ�ˣ�";
	string name;
	cin >> name;

	//�ж�
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "������" << abs->personArray[ret].m_Name << "  ";
		cout << "�Ա�" << (abs->personArray[ret].m_Sex == 1 ? "��" : "Ů") << "  ";  //��Ŀ�����
		cout << "���䣺" << abs->personArray[ret].m_Age << "  ";
		cout << "�绰��" << abs->personArray[ret].m_Phone << "  ";
		cout << "��ַ��" << abs->personArray[ret].m_Addr << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause"); //�밴�����
	system("cls"); //��������
}


//�޸���ϵ��
void modPerson(Addressbooks *abs)
{
	cout << "��������Ҫ�޸ĵ���ϵ�ˣ�";
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "��������Ҫ�޸ĵ���ϵ����Ϣ������" << endl;
		cout << "������������";
		cin >> name;
		abs->personArray[ret].m_Name = name; //�������ŵ�ͨѶ¼��
		//�Ա�
		cout << "�������Ա�";
		cout << "1--��" << "  " << "2--Ů" << endl;

		int sex = 0;
		while (true)
		{
			cout << "�������Ա�";
			//ֻ������1 �� 2
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "������������������" << endl;
		}
		//����
		cout << "���������䣺";
		int age = 0;
		while (true)
		{
			cin >> age;
			if (age < 0 || age > 120)
			{
				cout << "������������������" << endl;
			}
			else
			{
				abs->personArray[ret].m_Age = age;
				break;
			}
		}
		//�绰
		cout << "������绰��";
		string phone;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;
		//��ַ
		cout << "�������ַ: ";
		string address;
		cin >> address;
		abs->personArray[ret].m_Addr = address;

		//����ͨѶ¼����
		cout << "�޸ĳɹ�������" << endl;
	}
	else
	{
		cout << "���޴��� ,���������룡����" << endl;
	}
	system("pause"); //�밴�����
	system("cls"); //��������
}

//�����ϵ��
void cleanPerson(Addressbooks *abs)
{
	int judge;
	cout << "�Ƿ�Ҫ���ȫ����ϵ�ˣ���1---�� 2---��" << endl;
	cin >> judge;
	if (judge == 1)
	{
		abs->m_Size = 0;
		cout << "ͨѶ¼����գ�����" << endl;
	}
	else if(judge == 2)
	{
		cout << "���˳�" << endl;;
	}

	system("pause"); //�밴�����
	system("cls"); //��������
}

int main()
{
	int select = 0;
	//����ͨѶ¼�ṹ�����
	Addressbooks abs;
	//��ʼ��ͨѶ¼��Ա����
	abs.m_Size = 0;

	while (true)
	{
		//��ʾ��ʼ����
		showMenu();
		//ѡ�����
		cin >> select;
		switch (select)
		{
		case 1:             //1�������ϵ��
			addPerson(&abs);  //������˵�ַ
			break;
		case 2:             //2����ʾ��ϵ��
			showPerson(&abs);
			break;
		case 3:             //3��ɾ����ϵ��
			delePerson(&abs);
			break;
		case 4:             //4��������ϵ��
			findPerson(&abs);
			break;
		case 5:             //5���޸���ϵ��
			modPerson(&abs);
			break;
		case 6:             //6�������ϵ��
			cleanPerson(&abs);
			break;
		case 0:             //0���˳�ͨѶ¼
			cout << "��ӭ�´�ʹ�ã��ټ�^^" << endl;
			return 0;
			break;
		default:
			cout << "�����������������^^" << endl;
			break;
		}
	}
	
	system("pause");
	return 0;
}