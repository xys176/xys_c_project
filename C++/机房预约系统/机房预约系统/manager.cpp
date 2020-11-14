#include"manager.h"
//默认构造函数
Manager::Manager()
{

}
//有参构造函数
Manager::Manager(string name, string pwd)
{
	//初始化管理员的信息
	this->m_Name = name;
	this->m_Pwd = pwd;

	//初始化容器，并获取文件中的信息
	this->initvector();
	//初始化机房的信息
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	ComputerRoom com;
	while (ifs >> com.m_ComId && ifs >> com.m_MaxNum) {
		vCom.push_back(com);
	}
	ifs.close();
	cout << "机房的数量为" << vCom.size() << endl;
	
}
//登录界面
void Manager::operMenu()
{
	cout << "欢迎管理员：" << this->m_Name << "登录！" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.添加账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.查看账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.查看机房            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.清空预约            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.注销登录            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "请选择您的操作： " << endl;
}
//添加账号
void Manager::addPerson()
{
	cout << "请输入添加账号的类型" << endl;
	cout << "输入\"1\"添加学生" << endl;
	cout << "输入\"2\"添加教师" << endl;

	string fileName;  //操作的文件名，向哪个文件添加信息
	string top;       //添加的账号
	string errortop;  //重复的错误提示
	ofstream ofs;     //文件操作对象

	int select = 0;
	cin >> select;
	if (select == 1) {
		//添加的是学生
		fileName = STUDENT_FILE;
		top = "请输入学号";
		errortop = "学号重复，请重新输入";
	}
	else {
		fileName = TEACHER_FILE;
		top = "请输入职工编号";
		errortop = "职工号重复，请重新输入";
	}
	//利用追加的方式写文件
	ofs.open(fileName, ios::out | ios::app);
	int id;
	string name;
	string pwd;
	cout << top << endl;
	while (true)
	{
		cin >> id;
		bool res=cheakRepeat(id, select);
		if (res) //有重复
		{
			cout << errortop << endl;
		}
		else
		{
			break;
		}
	}

	cout << "请输入姓名" << endl;
	cin >> name;
	cout << "请输入密码" << endl;
	cin >> pwd;

	//向文件中添加数据
	ofs << id << " " << name << " " << pwd << endl;
	cout << "添加成功" << endl;
	system("pause");
	system("cls");
	ofs.close();

	//初始化容器的接口，重新获取文件中的数据，及时更新文件中的数据
	this->initvector();
}
void printStudent(Student &s)
{
	cout << "学号" << s.m_Id << " 姓名：" << s.m_Name << " 密码" << s.m_Pwd << endl;
}

void printTeacher(Teacher& t)
{
	cout << "职工号" << t.m_EmpId << " 姓名：" << t.m_Name << " 密码" << t.m_Pwd << endl;
}
//查看账号
void Manager::showPerson()
{
	cout << "请选择查看的内容" << endl;
	cout << "1,查看学生信息" << endl;
	cout << "2,查看教师信息" << endl;
	int select = 0;//接受用户的选择
	cin >> select;
	if (select == 1)
	{
		//查看学生
		cout << "所有的学生信息如下" << endl;
		for_each(vStu.begin(), vStu.end(), printStudent);
	}
	else
	{
		//查看教师
		cout << "所有的教师信息如下" << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);
	}
	system("pause");
	system("cls");
}
//查看机房的信息
void Manager::showComputer()
{
	cout << "机房的信息如下" << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin();it != vCom.end();it++)
	{
		cout << "机房编号" << it->m_ComId << "机房的最大容量" << it->m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}
//清空预约记录
void Manager::cleanFile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();
	cout << "清空成功" << endl;
	system("pause");
	system("cls");
}

//初始化容器
void Manager:: initvector()
{
	//确保文件是清空的状态
	vStu.clear();
	vTea.clear();
	//读取信息 学生，教师
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if(!ifs.is_open()){
		cout << "文件读取失败" << endl;
		return;
	}
	//读取信息 学生
	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd) 
	{
		vStu.push_back(s);
	}
	cout << "当前的学生数量为" << vStu.size() <<endl;
	ifs.close();

	//读取信息 教师
	ifs.open(TEACHER_FILE, ios::in);
	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		vTea.push_back(t);
	}
	cout << "当前教师的数量为" << vTea.size() << endl;
	ifs.close();
}
//检测重复  参数1：学生号/教师号，参数2：账号类型
bool Manager::cheakRepeat(int id, int type) 
{
	if (type == 1)
	{
		//检测学生
		for (vector<Student>::iterator it = vStu.begin();it != vStu.end();it++)
		{
			if (id == it->m_Id)
			{
				return true;
			}
		}
	}
	else
	{
		//检测教师
		for (vector<Teacher>::iterator it = vTea.begin();it != vTea.end();it++)
		{
			if (id == it->m_EmpId)
			{
				return true;
			}
		}
	}
}