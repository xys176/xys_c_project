#include<iostream>
#include<string>
using namespace std;

struct Hero
{
	string name;
	int age;
	string sex;

};

void bubblesort(Hero heroArray[], int len) {
	for (int i = 0;i < len;i++) {
		for (int j = 0;j < len - i - 1;j++) {
			if (heroArray[j].age > heroArray[j + 1].age) {
				Hero temp = heroArray[j];
				heroArray[j] = heroArray[j + 1];
				heroArray[j + 1] = temp;
			}
		}
	}
}

void printfhero(Hero heroArray[], int len) {
	for (int i = 0;i < len;i++) {
		cout << "����" << heroArray[i].name << " ����" << heroArray[i].age << " �Ա�" << heroArray[i].sex << endl;
	}
}

int main() {
	//1.���Ӣ�۽ṹ��
		
	//2.����������Ӣ��
	struct Hero heroArray[5] =
	{
		{"����",23,"��"},
		{"����",22,"��"},
		{"�ŷ�",20,"��"},
		{"����",21,"��"},
		{"����",19,"Ů"},
	};
	int len = sizeof(heroArray) / sizeof(heroArray[0]);
	for (int i = 0;i < len;i++) {
		cout << "����" << heroArray[i].name << " ����" << heroArray[i].age << " �Ա�" << heroArray[i].sex << endl;
	}
	//3.������������򣬰�������������
	bubblesort(heroArray, len);
	cout << "����֮��Ľ��" << endl;
	printfhero(heroArray, len);
	system("pause");



}