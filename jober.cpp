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
	cout << "Ա�����:" << this->id << endl;
	cout << "Ա������:" << this->name << endl;
	cout<< "Ա������:" << this->depid << endl;
}
string Jober::getDepName()
{
	return string("Ա��");
}
