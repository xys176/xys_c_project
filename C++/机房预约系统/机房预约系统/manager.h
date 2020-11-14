#pragma once
#include<iostream>
#include<string>
#include"identity.h"
#include<fstream>
#include"globalFile.h"
#include<vector>
#include"student.h"
#include"teacher.h"
#include<algorithm>
#include"computerRoom.h"
using namespace std;

//管理员类
class Manager :public Identity
{
public:
	//默认构造函数
	Manager();
	//有参构造函数
	Manager(string name, string pwd);
	//登录界面
	void operMenu();
	//添加账号
	void addPerson();
	//查看账号
	void showPerson();
	//查看机房的信息
	void showComputer();
	//清空预约记录
	void cleanFile();
	//检测重复  参数1：学生号/教师号，参数2：账号类型
	bool cheakRepeat(int id,int type);
	//初始化容器
	void initvector();
	//学生容器
	vector<Student>vStu;
	//教师容器
	vector<Teacher>vTea;
	//机房容器,存储机房的信息
	vector<ComputerRoom>vCom;
};