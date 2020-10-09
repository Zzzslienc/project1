#include <iostream>
#include "Msystem.h"
#include "boss.h"
#include "manager.h"
#include "jober.h"
#include "worker.h"
#include <windows.h>

using namespace std;

void test()
{
	Worker *p[3];

	p[0] = new Jober(1, "张三", 101);
	p[0]->showInfo();
	cout << p[0]->getDepName() << endl;
	cout << endl;
	delete p[0];


	p[1] = new Manager(2, "李四", 102);
	p[1]->showInfo();
	cout << p[1]->getDepName() << endl;
	cout << endl;
	delete p[1];

	p[2] = new Boss(3, "赵五", 103);
	p[2]->showInfo();
	cout << p[2]->getDepName() << endl;
	cout << endl;
	delete p[2];
  

}

int main()
{
	
	WorkManger a1;
	int choice = 0;

	while (true)
	{
		a1.show_menu();
		cout << "请输入您要选择的选项:" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:
			a1.exitSystem();
			break;
		case 1:
			a1.Add_person();
			break;
		case 2:
			a1.Show_PeoInfo();
			break;
		case 3:
			a1.deleteP();
			break;
		case 4:
			a1.Mod_Emp();
			break;
		case 5:
			a1.SearchP();
			break;
		case 6:
			a1.SortById();
			break;
		case 7:
			a1.Clean_File();
			break;
		default:
			system("cls");
			break;
		}

	}
	
   system("pause");
   return 0;



}
