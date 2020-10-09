#include "boss.h"
#include "iostream"
using namespace std;
Boss::Boss(int id, string name, int depid)
{
	this->id = id;
	this->name = name;
	this->depid = depid;
}
void Boss::showInfo()
{
	cout << "老板编号:" << this->id << endl;
		cout << "老板姓名:" << this->name << endl;
	cout<< "老板部门:" << this->depid << endl;
}
string Boss::getDepName()
{
	return string("老板");
}
