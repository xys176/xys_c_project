#include"manager.h"
//Ĭ�Ϲ��캯��
Manager::Manager()
{

}
//�вι��캯��
Manager::Manager(string name, string pwd)
{
	//��ʼ������Ա����Ϣ
	this->m_Name = name;
	this->m_Pwd = pwd;

	//��ʼ������������ȡ�ļ��е���Ϣ
	this->initvector();
	//��ʼ����������Ϣ
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	ComputerRoom com;
	while (ifs >> com.m_ComId && ifs >> com.m_MaxNum) {
		vCom.push_back(com);
	}
	ifs.close();
	cout << "����������Ϊ" << vCom.size() << endl;
	
}
//��¼����
void Manager::operMenu()
{
	cout << "��ӭ����Ա��" << this->m_Name << "��¼��" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.����˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.�鿴�˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.�鿴����            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.���ԤԼ            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.ע����¼            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}
//����˺�
void Manager::addPerson()
{
	cout << "����������˺ŵ�����" << endl;
	cout << "����\"1\"���ѧ��" << endl;
	cout << "����\"2\"��ӽ�ʦ" << endl;

	string fileName;  //�������ļ��������ĸ��ļ������Ϣ
	string top;       //��ӵ��˺�
	string errortop;  //�ظ��Ĵ�����ʾ
	ofstream ofs;     //�ļ���������

	int select = 0;
	cin >> select;
	if (select == 1) {
		//��ӵ���ѧ��
		fileName = STUDENT_FILE;
		top = "������ѧ��";
		errortop = "ѧ���ظ�������������";
	}
	else {
		fileName = TEACHER_FILE;
		top = "������ְ�����";
		errortop = "ְ�����ظ�������������";
	}
	//����׷�ӵķ�ʽд�ļ�
	ofs.open(fileName, ios::out | ios::app);
	int id;
	string name;
	string pwd;
	cout << top << endl;
	while (true)
	{
		cin >> id;
		bool res=cheakRepeat(id, select);
		if (res) //���ظ�
		{
			cout << errortop << endl;
		}
		else
		{
			break;
		}
	}

	cout << "����������" << endl;
	cin >> name;
	cout << "����������" << endl;
	cin >> pwd;

	//���ļ����������
	ofs << id << " " << name << " " << pwd << endl;
	cout << "��ӳɹ�" << endl;
	system("pause");
	system("cls");
	ofs.close();

	//��ʼ�������Ľӿڣ����»�ȡ�ļ��е����ݣ���ʱ�����ļ��е�����
	this->initvector();
}
void printStudent(Student &s)
{
	cout << "ѧ��" << s.m_Id << " ������" << s.m_Name << " ����" << s.m_Pwd << endl;
}

void printTeacher(Teacher& t)
{
	cout << "ְ����" << t.m_EmpId << " ������" << t.m_Name << " ����" << t.m_Pwd << endl;
}
//�鿴�˺�
void Manager::showPerson()
{
	cout << "��ѡ��鿴������" << endl;
	cout << "1,�鿴ѧ����Ϣ" << endl;
	cout << "2,�鿴��ʦ��Ϣ" << endl;
	int select = 0;//�����û���ѡ��
	cin >> select;
	if (select == 1)
	{
		//�鿴ѧ��
		cout << "���е�ѧ����Ϣ����" << endl;
		for_each(vStu.begin(), vStu.end(), printStudent);
	}
	else
	{
		//�鿴��ʦ
		cout << "���еĽ�ʦ��Ϣ����" << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);
	}
	system("pause");
	system("cls");
}
//�鿴��������Ϣ
void Manager::showComputer()
{
	cout << "��������Ϣ����" << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin();it != vCom.end();it++)
	{
		cout << "�������" << it->m_ComId << "�������������" << it->m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}
//���ԤԼ��¼
void Manager::cleanFile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();
	cout << "��ճɹ�" << endl;
	system("pause");
	system("cls");
}

//��ʼ������
void Manager:: initvector()
{
	//ȷ���ļ�����յ�״̬
	vStu.clear();
	vTea.clear();
	//��ȡ��Ϣ ѧ������ʦ
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if(!ifs.is_open()){
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}
	//��ȡ��Ϣ ѧ��
	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd) 
	{
		vStu.push_back(s);
	}
	cout << "��ǰ��ѧ������Ϊ" << vStu.size() <<endl;
	ifs.close();

	//��ȡ��Ϣ ��ʦ
	ifs.open(TEACHER_FILE, ios::in);
	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		vTea.push_back(t);
	}
	cout << "��ǰ��ʦ������Ϊ" << vTea.size() << endl;
	ifs.close();
}
//����ظ�  ����1��ѧ����/��ʦ�ţ�����2���˺�����
bool Manager::cheakRepeat(int id, int type) 
{
	if (type == 1)
	{
		//���ѧ��
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
		//����ʦ
		for (vector<Teacher>::iterator it = vTea.begin();it != vTea.end();it++)
		{
			if (id == it->m_EmpId)
			{
				return true;
			}
		}
	}
}