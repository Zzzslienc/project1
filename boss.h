#pragma once
#include "worker.h"
#include <iostream>
using namespace std;
class Boss : public Worker
{
public:
	virtual void showInfo();
	virtual string getDepName();
	Boss(int id, string name, int depid);
};
