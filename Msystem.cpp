#include<iostream>
#include"Msystem.h"
#include"windows.h"
#include <fstream>
using namespace std;

void WorkManger::show_menu()
{
	cout << "************************" << endl;
	cout << "*****0.退出管理系统*****" << endl;
	cout << "*****1.增加一个职员*****" << endl;
	cout << "*****2.显示所有职员*****" << endl;
	cout << "*****3.删除一个职员*****" << endl;
	cout << "*****4.修改一个职员*****" << endl;
	cout << "*****5.查询公司职员*****" << endl;
	cout << "*****6.对职员进行排序***" << endl;
	cout << "*****7.清空职工文档*****" << endl;
}
WorkManger::WorkManger()
{
	this->P_num= 0;
	this->Array = NULL;

	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	//文件不存在情况
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl; //测试输出
		this->P_num = 0;  //初始化人数
		this->FileIsEmpty = true; //初始化文件为空标志
		this->Array = NULL; //初始化数组
		ifs.close(); //关闭文件
		return;
	}
	char ch;
	ifs >> ch;	
	if (ifs.eof())
	{
		cout << "文件为空!" << endl;
		this->P_num = 0;
		this->FileIsEmpty = true;
		this->Array = NULL;
		ifs.close();
		return;
	}
	int num = this->getP_num();
	cout << "职工个数为：" << num << endl;  
	this->P_num = num;
	this->Array = new Worker *[this->P_num];
	
	init_P();

	this->FileIsEmpty = false;

	
	for (int i = 0; i < P_num; i++)
	{
		cout << "职工号： " << this->Array[i]->id
			<< " 职工姓名： " << this->Array[i]->name
			<< " 部门编号： " << this->Array[i]->depid << endl;
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
		//根据不同的部门Id创建不同对象
		if (dId == 1)  // 1普通员工
		{
			worker = new Jober(id, name, dId);
		}
		else if (dId == 2) //2经理
		{
			worker = new Manager(id, name, dId);
		}
		else //总裁
		{
			worker = new Boss(id, name, dId);
		}
		//存放在数组中
		this->Array[index] = worker;
		index++;
	}
}
int WorkManger::exitSystem()
{

	cout << "感谢使用" << endl;
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
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{

		string pname;
		cout << "请输入你要删除员工的姓名:" << endl;
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
			cout << "删除成功！" << endl;
		}
		else
		{
			
			cout << "删除失败，未找到该职工" << endl;
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
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{

		string pname;
		cout << "请输入你要查找员工的姓名:" << endl;
		cin >> pname;
		cout << endl;

		if (isExist(pname) != -1)
		{
			cout << "该员工的信息为:" << endl;
			this->Array[isExist(pname)]->showInfo();
		}
		else
		{

			cout << "该员工的不存在!" << endl;
			cout << endl;
		}
	}

	system("pause");
	system("cls");


}
void WorkManger::Add_person()
{
	cout << "请输入增加职工数量： " << endl;

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

			cout << "请输入第 " << i + 1 << " 个新职工编号：" << endl;
			cin >> id;


			cout << "请输入第 " << i + 1 << " 个新职工姓名：" << endl;
			cin >> name;


			cout << "请选择该职工的岗位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
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


		cout << "成功添加" << addNum << "名新职工！" << endl;
	}
	else
	{
		cout << "输入有误" << endl;
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
		//记录人数
		num++;
	}
	ifs.close();

	return num;
}
void WorkManger::Show_PeoInfo()
{  
	if (this->FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		for (int i = 0; i < P_num; i++)
		{
			//利用多态调用接口
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
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		cout << "请输入修改职工的编号：" << endl;
		int id;
		cin >> id;

		int ret = this->IdisExist(id);
		if (ret != -1)
		{
			//查找到编号的职工

			delete this->Array[ret];

			int newId = 0;
			string newName = "";
			int dSelect = 0;

			cout << "查到： " << id << "号职工，请输入新职工号： " << endl;
			cin >> newId;

			cout << "请输入新姓名： " << endl;
			cin >> newName;

			cout << "请输入岗位： " << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
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
				cout << "输入有误，只能在1,2,3中选择！" << endl;
				break;
			}

			this->Array[ret] = worker;

			cout << "修改成功！" << endl;
			this->save();
		}
		else
		{
			cout << "修改失败，查无此人" << endl;
		}
	}

	system("pause");
	system("cls");

}
void WorkManger::SortById()
{

	if (this->FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择排序方式： " << endl;
		cout << "1、按职工号进行升序" << endl;
		cout << "2、按职工号进行降序" << endl;

		int select = 0;
		cin >> select;


		for (int i = 0; i < P_num; i++)
		{
			int minOrMax = i;
			for (int j = i + 1; j < P_num; j++)
			{
				if (select == 1) //升序
				{
					if (Array[minOrMax]->id > Array[j]->id)
					{
						minOrMax = j;
					}
				}
				else  //降序
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

		cout << "排序成功,排序后结果为：" << endl;
		this->save();
		this->Show_PeoInfo();
		

	}
}
void WorkManger::Clean_File()
{

	cout << "确认清空？" << endl;
	cout << "1、确认" << endl;
	cout << "2、返回" << endl;

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
		cout << "清空成功！" << endl;
	}

	system("pause");
	system("cls");

}