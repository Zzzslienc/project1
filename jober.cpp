//#include "work.h"
#include "jober.h"
#include "iostream"

using namespace std;
Jober::Jober(int id, string name, int depid)
{
	this->id = id;
	this->name = name;
	this->depid = depid;
}
void Jober::showInfo()
{
	cout << "员工编号:" << this->id << endl;
	cout << "员工姓名:" << this->name << endl;
	cout<< "员工部门:" << this->depid << endl;
}
string Jober::getDepName()
{
	return string("员工");
}
