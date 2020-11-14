#pragma once   //防止头文件重复包含
#include<iostream>
using namespace std;

//身份抽象的基类，每种身份所必须包含的
class Identity 
{
public:
	//每种身份后对应一种登录菜单，纯虚函数，实现在具体的派生类中
	virtual void operMenu() = 0;
	//用户名
	string m_Name;
	//密码
	string m_Pwd;
};