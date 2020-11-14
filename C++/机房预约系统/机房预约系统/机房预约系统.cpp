#include<iostream>
#include<fstream>
#include<string>
#include"globalFile.h"
#include"identity.h"
#include"student.h"
#include"teacher.h"
#include"manager.h"
using namespace std;
//进入学生的子菜单
void studentMenu(Identity*& student)
{
	while (true)
	{
		//学生菜单
		student->operMenu();

		Student* stu = (Student*)student;
		int select = 0;

		cin >> select;

		if (select == 1) //申请预约
		{
			stu->applyOrder();
		}
		else if (select == 2) //查看自身预约
		{
			stu->showMyorder();
		}
		else if (select == 3) //查看所有预约
		{
			stu->showAllOrder();
		}
		else if (select == 4) //取消预约
		{
			stu->canceOrder();
		}
		else
		{
			delete student;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//进入管理员的子菜单
void managerMenu(Identity*& manager) {
	while (true) {
		//调用管理员的子菜单
		manager->operMenu();  //多态，父类指针调用子类接口
		//将父类的指针转为子类的指针，可以调用子类中特有的接口
		Manager* man = (Manager*)manager;
		int select = 0;
		cin >> select;
		if (select == 1) {   //添加账号
			cout << "添加账号" << endl;
			man->addPerson();
		}
		else if (select == 2) {//查看账号
			cout << "查看账号" << endl;
			man->showPerson();
		}
		else if (select == 3) {//查看机房
			cout << "查看机房" << endl;
			man->showComputer();
		}
		else if (select == 4) {//清空预约
			cout << "清空预约" << endl;
			man->cleanFile();
		}
		else {//注销登录
			delete manager;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}


//登录的功能 参数1，操作的文件的名称，参数2，操作的身份的类型
void LoginIn(string filename, int type) 
{
	//父类指针，用于指向子类对象
	Identity* person = NULL;//定义一个表明身份的指针，开始指向空

	//读文件
	ifstream ifs;
	ifs.open(filename,ios::in);

	//判断文件是否存在
	if(!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}

	//准备接受用户的输入信息
	int id = 0;
	string name;
	string pwd;
	
	//判断身份
	if(type==1)//学生身份
	{
		cout << "请输入你的学号" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "请输入你的职工号" << endl;
		cin >> id;
	}

	cout << "请输入用户名" << endl;
	cin >> name;

	cout << "请输入密码" << endl;
	cin >> pwd;

	if (type == 1)
	{
		//学生身份验证
		int fId;         //代表从文件中读入的id号
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (id == fId && name == fName && pwd == fPwd) {
				cout << "学生验证登录成功！"<<endl;
				system("pause");
				system("cls");
				person = new Student(id,name,pwd);  //让开始表明身份的指针指向新建的子类对象（学生对象）
				//进入学生身份的子菜单
				studentMenu(person);
				return;
			}
		}

	}
	else if(type==2)
	{
		//教师身份验证
		int fId;         //代表从文件中读入的id号
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (id == fId && name == fName && pwd == fPwd) {
				cout << "教师验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);  //让开始表明身份的指针指向新建的子类对象（教师对象）
				//进入教师身份的子菜单

				return;
			}
		}
	}
	else if(type==3)
	{
		//管理员身份验证
		string fName; //从文件中获得的用户名
		string fPwd;  //从文件中获得的密码
		while (ifs >> fName && ifs >> fPwd)
		{
			if (name == fName && pwd == fPwd)
			{
				cout << "管理员登录验证成功" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				//进入管理员的界面
				managerMenu(person);
				return;
			}
		}
	}
	cout << "登录失败" << endl;
	system("pause");
	system("cls");
	return;
}
int main() {
	int select = 0;
	while (true) {
		cout << "======================  欢迎来到机房预约系统  ====================="<< endl;
		cout << endl << "请输入您的身份" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.学生代表           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.老    师           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.管 理 员           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          0.退    出           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "输入您的选择: ";
		cin >> select;  //用户输入
		switch (select)
		{
		case 0:  //退出系统
			cout << "欢迎下次使用,按任意键退出" << endl;
			system("pause");
			return 0;
			break;
		case 1:  //学生身份
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2:  //老师身份
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3:  //管理员身份
			LoginIn(ADMIN_FILE, 3);
			break;
		default:
			cout << "输入有误,请重新选择" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}