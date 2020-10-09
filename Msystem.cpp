#include<iostream>
#include"Msystem.h"
#include"windows.h"
#include <fstream>
using namespace std;

void WorkManger::show_menu()
{
	cout << "************************" << endl;
	cout << "*****0.�˳�����ϵͳ*****" << endl;
	cout << "*****1.����һ��ְԱ*****" << endl;
	cout << "*****2.��ʾ����ְԱ*****" << endl;
	cout << "*****3.ɾ��һ��ְԱ*****" << endl;
	cout << "*****4.�޸�һ��ְԱ*****" << endl;
	cout << "*****5.��ѯ��˾ְԱ*****" << endl;
	cout << "*****6.��ְԱ��������***" << endl;
	cout << "*****7.���ְ���ĵ�*****" << endl;
}
WorkManger::WorkManger()
{
	this->P_num= 0;
	this->Array = NULL;

	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	//�ļ����������
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl; //�������
		this->P_num = 0;  //��ʼ������
		this->FileIsEmpty = true; //��ʼ���ļ�Ϊ�ձ�־
		this->Array = NULL; //��ʼ������
		ifs.close(); //�ر��ļ�
		return;
	}
	char ch;
	ifs >> ch;	
	if (ifs.eof())
	{
		cout << "�ļ�Ϊ��!" << endl;
		this->P_num = 0;
		this->FileIsEmpty = true;
		this->Array = NULL;
		ifs.close();
		return;
	}
	int num = this->getP_num();
	cout << "ְ������Ϊ��" << num << endl;  
	this->P_num = num;
	this->Array = new Worker *[this->P_num];
	
	init_P();

	this->FileIsEmpty = false;

	
	for (int i = 0; i < P_num; i++)
	{
		cout << "ְ���ţ� " << this->Array[i]->id
			<< " ְ�������� " << this->Array[i]->name
			<< " ���ű�ţ� " << this->Array[i]->depid << endl;
	}
	
}

WorkManger::~WorkManger()
{
	if (this->Array != NULL)
	{
		delete[] this->Array;
	}
}
void WorkManger::init_P()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker * worker = NULL;
		//���ݲ�ͬ�Ĳ���Id������ͬ����
		if (dId == 1)  // 1��ͨԱ��
		{
			worker = new Jober(id, name, dId);
		}
		else if (dId == 2) //2����
		{
			worker = new Manager(id, name, dId);
		}
		else //�ܲ�
		{
			worker = new Boss(id, name, dId);
		}
		//�����������
		this->Array[index] = worker;
		index++;
	}
}
int WorkManger::exitSystem()
{

	cout << "��лʹ��" << endl;
	cout << endl;
	system("pause");
	exit(0);
}
int WorkManger::isExist(string name)
{
	int flag =-1;
	for (int i = 0; i < P_num; i++)
	{
		

		if (this->Array[i]->name == name)
		{
			return i;

		}
	}
	return -1;
}

int WorkManger::IdisExist(int id)
{
	int flag = -1;
	for (int i = 0; i < P_num; i++)
	{


		if (this->Array[i]->id == id)
		{
			return i;

		}
	}
	return -1;
}

void WorkManger::deleteP()
{

	if (this->FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{

		string pname;
		cout << "��������Ҫɾ��Ա��������:" << endl;
		cin >> pname;
		cout << endl;
		
		if (isExist(pname) != -1)
		{
			for (int i = isExist(pname); i < this->P_num - 1; i++)
			{
				this->Array[i] = this->Array[i + 1];
			}
			this->P_num--;

			this->save(); 
			cout << "ɾ���ɹ���" << endl;
		}
		else
		{
			
			cout << "ɾ��ʧ�ܣ�δ�ҵ���ְ��" << endl;
			cout << endl;
		}
	}

	system("pause");
	system("cls");

}
void WorkManger::SearchP()
{


	if (this->FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{

		string pname;
		cout << "��������Ҫ����Ա��������:" << endl;
		cin >> pname;
		cout << endl;

		if (isExist(pname) != -1)
		{
			cout << "��Ա������ϢΪ:" << endl;
			this->Array[isExist(pname)]->showInfo();
		}
		else
		{

			cout << "��Ա���Ĳ�����!" << endl;
			cout << endl;
		}
	}

	system("pause");
	system("cls");


}
void WorkManger::Add_person()
{
	cout << "����������ְ�������� " << endl;

	int addNum = 0;
	cin >> addNum;

	if (addNum > 0)
	{
		int newSize = this->P_num + addNum;
		Worker ** newSpace = new Worker*[newSize];
		if (this->Array != NULL)
		{
			for (int i = 0; i < this->P_num; i++)
			{
				newSpace[i] = this->Array[i];
			}
		}
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;

			cout << "������� " << i + 1 << " ����ְ����ţ�" << endl;
			cin >> id;


			cout << "������� " << i + 1 << " ����ְ��������" << endl;
			cin >> name;


			cout << "��ѡ���ְ���ĸ�λ��" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> dSelect;
			cout << endl;


			Worker * worker = NULL;
			switch (dSelect)
			{
			case 1: 
				worker = new Jober(id, name, 1);
				break;
			case 2: 
				worker = new Manager(id, name, 2);
				break;
			case 3: 
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}


			newSpace[this->P_num + i] = worker;
		}

		
		delete[] this->Array;

		this->Array = newSpace;


		this->P_num = newSize;

		this->FileIsEmpty = false;


		cout << "�ɹ����" << addNum << "����ְ����" << endl;
	}
	else
	{
		cout << "��������" << endl;
	}
	this->save();

	system("pause");
	system("cls");
}


void WorkManger::save()
{
	ofstream ofs;
	ofs.open("file1.txt",ios::out);

	for (int i = 0; i < this->P_num; i++)
	{
		ofs << this->Array[i]->id<< " "
			<< this->Array[i]->name<< " "
			<< this->Array[i]->depid << endl;
	}

	ofs.close();


}
int WorkManger::getP_num()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		//��¼����
		num++;
	}
	ifs.close();

	return num;
}
void WorkManger::Show_PeoInfo()
{  
	if (this->FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		for (int i = 0; i < P_num; i++)
		{
			//���ö�̬���ýӿ�
			this->Array[i]->showInfo();
			cout << endl;
		}
	}
	
	system("pause");
	system("cls");
}

void WorkManger::Mod_Emp()
{
	if (this->FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		cout << "�������޸�ְ���ı�ţ�" << endl;
		int id;
		cin >> id;

		int ret = this->IdisExist(id);
		if (ret != -1)
		{
			//���ҵ���ŵ�ְ��

			delete this->Array[ret];

			int newId = 0;
			string newName = "";
			int dSelect = 0;

			cout << "�鵽�� " << id << "��ְ������������ְ���ţ� " << endl;
			cin >> newId;

			cout << "�������������� " << endl;
			cin >> newName;

			cout << "�������λ�� " << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> dSelect;

			Worker * worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Jober(newId, newName, dSelect);
				break;
			case 2:
				worker = new Manager(newId, newName, dSelect);
				break;
			case 3:
				worker = new Boss(newId, newName, dSelect);
				break;
			default:
				cout << "��������ֻ����1,2,3��ѡ��" << endl;
				break;
			}

			this->Array[ret] = worker;

			cout << "�޸ĳɹ���" << endl;
			this->save();
		}
		else
		{
			cout << "�޸�ʧ�ܣ����޴���" << endl;
		}
	}

	system("pause");
	system("cls");

}
void WorkManger::SortById()
{

	if (this->FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѡ������ʽ�� " << endl;
		cout << "1����ְ���Ž�������" << endl;
		cout << "2����ְ���Ž��н���" << endl;

		int select = 0;
		cin >> select;


		for (int i = 0; i < P_num; i++)
		{
			int minOrMax = i;
			for (int j = i + 1; j < P_num; j++)
			{
				if (select == 1) //����
				{
					if (Array[minOrMax]->id > Array[j]->id)
					{
						minOrMax = j;
					}
				}
				else  //����
				{
					if (Array[minOrMax]->id < Array[j]->id)
					{
						minOrMax = j;
					}
				}
			}

			if (i != minOrMax)
			{
				Worker * temp = Array[i];
				Array[i] = Array[minOrMax];
				Array[minOrMax] = temp;
			}

		}

		cout << "����ɹ�,�������Ϊ��" << endl;
		this->save();
		this->Show_PeoInfo();
		

	}
}
void WorkManger::Clean_File()
{

	cout << "ȷ����գ�" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2������" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		if (this->Array != NULL)
		{
			for (int i = 0; i < this->P_num; i++)
			{
				if (this->Array[i] != NULL)
				{
					delete this->Array[i];
				}
			}
			this->P_num = 0;
			delete[] this->Array;
			this->Array = NULL;
			this->FileIsEmpty = true;
		}
		cout << "��ճɹ���" << endl;
	}

	system("pause");
	system("cls");

}