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
	cout << "������:" << this->id << endl;
	cout << "��������:" << this->name << endl;
	cout<< "������:" << this->depid << endl;
}
string Manager::getDepName()
{
	return string("����");
}
