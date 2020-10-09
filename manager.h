#pragma once
#pragma once
#include "worker.h"
#include <iostream>
using namespace std;
class Manager: public Worker
{
public:
	virtual void showInfo();

	virtual string getDepName();
	Manager(int id, string name, int depid);
};