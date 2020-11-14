#include<iostream>
#include<Windows.h>
using namespace std;
#define MAX 1000
struct Person
{
	string name;
	int age;
	int sex;
	string telephone;
	string address;
};

struct Addressbook
{
	struct Person personArray[MAX];
	int size;
};

//�˵�
void showMean() {
	cout << "************" << endl;
	cout << "1.�����ϵ��" << endl;
	cout << "2.��ʾ��ϵ��" << endl;
	cout << "3.ɾ����ϵ��" << endl;
	cout << "4.������ϵ��" << endl;
	cout << "5.�޸���ϵ��" << endl;
	cout << "6.�����ϵ��" << endl;
	cout << "0.�˳�ͨѶ¼" << endl;
}
//�����ϵ��

void AddPerson(Addressbook* abs) {
	if (abs->size == MAX) {
		cout << "ͨѶ¼����" << endl;
	}
	else {
		string name;
		cout << "����������" << endl;
		cin >> name;
		abs->personArray[abs->size].name = name;
		while (true) {
			int sex;
		    cout << "�������Ա�,1�����У�2����Ů" << endl;
		    cin >> sex;
		    if (sex == 1 || sex == 2) {
			    abs->personArray[abs->size].sex = sex;
			    break;  //���������������
		       }
		         cout << "����������" << endl;
	    }
		cout << "����������" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->size].age = age;
		cout << "���������" << endl;
		string telephone;
		cin >> telephone;
		abs->personArray[abs->size].telephone = telephone;
		cout << "�������ַ" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->size].address = address;
		abs->size++;
		cout << "��ӳɹ�" << endl;
		system("pause");
		system("cls");
	}

}

//��ʾ���е���ϵ��
void ShowPerson(Addressbook *abs) {
	if (abs->size == 0) {
		cout << "��ǰ��¼Ϊ��" << endl;
	}
	else {
		for (int i = 0;i < abs->size;i++) {
			cout << "������" << abs->personArray[i].name << "\t";
			cout << "�Ա�" << (abs->personArray[i].sex == 1 ?"��":"Ů")<< "\t";
			cout << "���䣺" << abs->personArray[i].age << "\t";
			cout << "���룺" << abs->personArray[i].telephone << "\t";
			cout << "סַ��" << abs->personArray[i].address << endl;
		}
	}
	system("pause");
	system("cls");
}

//�����ϵ���Ƿ���ڣ����ڷ��������е��±꣬�����ڷ���-1
int isExist(Addressbook* abs,string name) {
	for (int i = 0;i < abs->size;i++) {
		if (abs->personArray[i].name == name) {
			return i;
		}
		return - 1;
	}
}

//ɾ��ָ������ϵ��
void deletePerson(Addressbook* abs) {
	cout << "����Ҫɾ����ϵ�˵�����" << endl;
	string name;
	cin >> name;
	int result = isExist(abs, name);
	if (result != -1) {
		cout << "û�д����޷�ɾ��" << endl;
	}
	else {
		for (int i = result;i < abs->size;i++) {
			abs->personArray[i] = abs->personArray[i + 1];   //���ݴ�Ҫɾ����λ��֮����ǰ��
		 }
		abs->size--;
		cout << "ɾ���ɹ�" << endl;
	}
	system("pause");
	system("cls");
}

//������ϵ��
void findPerson(Addressbook* abs) {
	cout << "������Ҫ���ҵ���ϵ��" << endl;
	if (abs->size == 0) {
		cout << "ͨѶ¼Ϊ�գ�û����ϵ��"<<endl;
	}
	else {
		string name1;
		cin >> name1;
		int ret = isExist(abs, name1);
		if (ret != -1) {
			cout << "����" << abs->personArray[ret].name << "\t";
			cout << "����" << abs->personArray[ret].age << "\t";
			cout << "�Ա�" << abs->personArray[ret].sex << "\t";
			cout << "����" << abs->personArray[ret].telephone << "\t";
			cout << "��ַ" << abs->personArray[ret].address << endl;
		}
		else {
			cout << "���޴���" << endl;
		}
	}
	system("pause");
	system("cls");
}

//�޸���ϵ��
void modiyPerson(Addressbook* abs) {
	cout << "������Ҫ�޸ĵ���ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {
		string name;
		cout << "�������޸ĺ������" << endl;
		cin >> name;
		abs->personArray[ret].name = name;
		int sex = 0;
		while (true) {
			cout << "�������޸ĺ���Ա�,1�����У�2����Ů" << endl;
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[ret].sex = sex;
				break;
			}
			cout << "����������" << endl;
		}
		cout << "�������޸ĺ������" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[ret].age = age;
		cout << "�������޸ĺ�ĺ���" << endl;
		string telephone;
		cin >> telephone;
		abs->personArray[ret].telephone = telephone;
		cout << "�������޸ĺ�ĵ�ַ" << endl;
		string address;
		cin >> address;
		abs->personArray[ret].address = address;
		cout << "�޸ĳɹ�" << endl;	
		cout << "�޸ĺ����ϵ����Ϣ" << endl;
		ShowPerson(abs);
	}
	else {
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}

//�����ϵ��
void clearPerson(Addressbook* abs) {
	abs->size = 0;
	cout << "ͨѶ¼�����" << endl;
	system("pause");
	system("cls");
}
int main() {
	Addressbook abs;
	//��ʼ��ͨѶ¼
	abs.size = 0;


	int select = 0;
	while (true) {
		showMean();
		cout << "������" << endl;
		cin >> select;
		switch (select) {
		case 1:  //1.�����ϵ��
			AddPerson(&abs);   //����ֵ����ʵ���޷��ı䣬����Ҫ�ô��ݵ�ַ
			break;
		case 2:  //2.��ʾ��ϵ��
			ShowPerson(&abs);
			break;
		case 3:  //3.ɾ����ϵ��
		{
			//cout << "������ɾ����ϵ�˵�����" << endl;
			//string nametemp;
			//cin >> nametemp;
			//if (isExist(&abs, nametemp) == -1) {
			//	cout << "���޴���" << endl;
			//}
			//cout << "�鵽����" << endl;
			deletePerson(&abs);
			break;
		}
		case 4:  //4.������ϵ��
			findPerson(&abs);
			break;
		case 5:  //5.�޸���ϵ��
			modiyPerson(&abs);
			break;
		case 6:  //6.�����ϵ��
			clearPerson(&abs);
			break;
		case 0:  //0.�˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "�������" << endl;
		}

	}

	system("pause");
	return 0;
}