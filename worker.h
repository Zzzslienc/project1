#pragma once
#include <string>

#include <iostream>
using namespace std;
class Worker
{
public:
	virtual void showInfo() = 0;
	virtual string getDepName() = 0;
	int id;
	string name;
	int depid;
};
