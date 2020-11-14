#pragma once           //防止头文件重复包含
#include <iostream>    //包含输出输入流
using namespace std;   //标准命名空间
#include"worker.h"
#include<fstream>
#define FILE "testfile.txt"
class WorkerManager
{
public:
	WorkerManager();
	void Show_Menu();
	void Exit_System();


	void Add_Worker();
	void save();

	//记录职工人数
	int m_EmpNum;
	Worker ** m_worker;
	~WorkerManager();


private:

};