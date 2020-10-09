#pragma once
#include "worker.h"
#include <iostream>
using namespace std;
class Jober : public Worker
{
public:
	virtual void showInfo();
	virtual string getDepName();
	Jober(int id, string name, int depid);
};
