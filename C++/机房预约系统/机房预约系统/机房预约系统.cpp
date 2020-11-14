#include<iostream>
#include<fstream>
#include<string>
#include"globalFile.h"
#include"identity.h"
#include"student.h"
#include"teacher.h"
#include"manager.h"
using namespace std;
//����ѧ�����Ӳ˵�
void studentMenu(Identity*& student)
{
	while (true)
	{
		//ѧ���˵�
		student->operMenu();

		Student* stu = (Student*)student;
		int select = 0;

		cin >> select;

		if (select == 1) //����ԤԼ
		{
			stu->applyOrder();
		}
		else if (select == 2) //�鿴����ԤԼ
		{
			stu->showMyorder();
		}
		else if (select == 3) //�鿴����ԤԼ
		{
			stu->showAllOrder();
		}
		else if (select == 4) //ȡ��ԤԼ
		{
			stu->canceOrder();
		}
		else
		{
			delete student;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//�������Ա���Ӳ˵�
void managerMenu(Identity*& manager) {
	while (true) {
		//���ù���Ա���Ӳ˵�
		manager->operMenu();  //��̬������ָ���������ӿ�
		//�������ָ��תΪ�����ָ�룬���Ե������������еĽӿ�
		Manager* man = (Manager*)manager;
		int select = 0;
		cin >> select;
		if (select == 1) {   //����˺�
			cout << "����˺�" << endl;
			man->addPerson();
		}
		else if (select == 2) {//�鿴�˺�
			cout << "�鿴�˺�" << endl;
			man->showPerson();
		}
		else if (select == 3) {//�鿴����
			cout << "�鿴����" << endl;
			man->showComputer();
		}
		else if (select == 4) {//���ԤԼ
			cout << "���ԤԼ" << endl;
			man->cleanFile();
		}
		else {//ע����¼
			delete manager;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}


//��¼�Ĺ��� ����1���������ļ������ƣ�����2����������ݵ�����
void LoginIn(string filename, int type) 
{
	//����ָ�룬����ָ���������
	Identity* person = NULL;//����һ��������ݵ�ָ�룬��ʼָ���

	//���ļ�
	ifstream ifs;
	ifs.open(filename,ios::in);

	//�ж��ļ��Ƿ����
	if(!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}

	//׼�������û���������Ϣ
	int id = 0;
	string name;
	string pwd;
	
	//�ж����
	if(type==1)//ѧ�����
	{
		cout << "���������ѧ��" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "���������ְ����" << endl;
		cin >> id;
	}

	cout << "�������û���" << endl;
	cin >> name;

	cout << "����������" << endl;
	cin >> pwd;

	if (type == 1)
	{
		//ѧ�������֤
		int fId;         //������ļ��ж����id��
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (id == fId && name == fName && pwd == fPwd) {
				cout << "ѧ����֤��¼�ɹ���"<<endl;
				system("pause");
				system("cls");
				person = new Student(id,name,pwd);  //�ÿ�ʼ������ݵ�ָ��ָ���½����������ѧ������
				//����ѧ����ݵ��Ӳ˵�
				studentMenu(person);
				return;
			}
		}

	}
	else if(type==2)
	{
		//��ʦ�����֤
		int fId;         //������ļ��ж����id��
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (id == fId && name == fName && pwd == fPwd) {
				cout << "��ʦ��֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);  //�ÿ�ʼ������ݵ�ָ��ָ���½���������󣨽�ʦ����
				//�����ʦ��ݵ��Ӳ˵�

				return;
			}
		}
	}
	else if(type==3)
	{
		//����Ա�����֤
		string fName; //���ļ��л�õ��û���
		string fPwd;  //���ļ��л�õ�����
		while (ifs >> fName && ifs >> fPwd)
		{
			if (name == fName && pwd == fPwd)
			{
				cout << "����Ա��¼��֤�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				//�������Ա�Ľ���
				managerMenu(person);
				return;
			}
		}
	}
	cout << "��¼ʧ��" << endl;
	system("pause");
	system("cls");
	return;
}
int main() {
	int select = 0;
	while (true) {
		cout << "======================  ��ӭ��������ԤԼϵͳ  ====================="<< endl;
		cout << endl << "�������������" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.ѧ������           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.��    ʦ           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.�� �� Ա           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          0.��    ��           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "��������ѡ��: ";
		cin >> select;  //�û�����
		switch (select)
		{
		case 0:  //�˳�ϵͳ
			cout << "��ӭ�´�ʹ��,��������˳�" << endl;
			system("pause");
			return 0;
			break;
		case 1:  //ѧ�����
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2:  //��ʦ���
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3:  //����Ա���
			LoginIn(ADMIN_FILE, 3);
			break;
		default:
			cout << "��������,������ѡ��" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}