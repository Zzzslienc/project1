#pragma once
#include<iostream>
#include"jober.h"
#include"boss.h"
#include"manager.h"
#include <fstream>
using namespace std;
#define  FILENAME "file1.txt"

class WorkManger
{
public:
	void show_menu();
	void Add_person();
	void Show_PeoInfo();
	void save();
	void SearchP();
	int isExist(string name);
	int IdisExist(int id);
	void SortById();
	void Clean_File();
	void Mod_Emp();
	void deleteP();
	int exitSystem();
	int getP_num();
	void init_P();
	WorkManger();
	~WorkManger();
	
	bool FileIsEmpty;
	int P_num;
	Worker ** Array;


};
