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
	cout << "�ϰ���:" << this->id << endl;
		cout << "�ϰ�����:" << this->name << endl;
	cout<< "�ϰ岿��:" << this->depid << endl;
}
string Boss::getDepName()
{
	return string("�ϰ�");
}
