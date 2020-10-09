#include "manager.h"
#include "iostream"
using namespace std;
Manager::Manager(int id, string name, int depid)
{
	this->id = id;
	this->name = name;
	this->depid = depid;
}
void Manager::showInfo()
{
	cout << "经理编号:" << this->id << endl;
	cout << "经理姓名:" << this->name << endl;
	cout<< "经理部门:" << this->depid << endl;
}
string Manager::getDepName()
{
	return string("经理");
}
