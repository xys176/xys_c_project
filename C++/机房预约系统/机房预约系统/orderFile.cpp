#include"orderFile.h"

//���캯��
OrderFile::OrderFile()
{
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	string date;        //��ȡ������
	string interval;    //ʱ���
	string stuId;       //ѧ�����
	string stuName;     //ѧ������
	string roomId;      //ѧ��ѧ��
	string status;      //���״̬

	this->m_size = 0;
	while (ifs >> date && ifs >> interval && ifs >> stuId && ifs >> stuName && ifs >> roomId && ifs >> status)
	{
		//	cout << date << endl;
		//	cout << interval << endl;
		//	cout << stuId << endl;
		//	cout << stuName << endl;
		//	cout << roomId << endl;
		//	cout << status << endl;
		//���Խ��
		//date:1
		//interval : 1
		//stuId : 1
		//stuName : Ѧ��ʢ
		//room : 1
		//statue : 1

		//date:1
		string key;
		string value;
		map<string, string>m;

		//date:1 ��ȡ����
		int pos = date.find(":");   //�ҵ����±�Ϊ4 ,d0 a1 t2 e3 :4
		if (pos != -1) {
			key = date.substr(0, pos);    //����date  key="date"
			value = date.substr(pos + 1, date.size());
			m.insert(make_pair(key, value));
		}
		//cout << "key= " << key << endl;
		//cout << "value= " << value << endl;
		//interval : 1 ��ȡʱ���
		pos = interval.find(":");  
		if (pos != -1) {
			key = interval.substr(0, pos);   
			value = interval.substr(pos + 1, interval.size());
			m.insert(make_pair(key, value));
		}
		//stuId : 1  ��ȡѧ����
		pos = stuId.find(":");  
		if (pos != -1) {
			key = stuId.substr(0, pos);    
			value = stuId.substr(pos + 1, stuId.size());
			m.insert(make_pair(key, value));
		}
		//stuName : Ѧ��ʢ  ��ȡ����
		pos = stuName.find(":");   
		if (pos != -1) {
			key = stuName.substr(0, pos);   
			value = stuName.substr(pos + 1, stuName.size());
			m.insert(make_pair(key, value));
		}
		//room : 1  ��ȡ������
		pos = roomId.find(":");   
		if (pos != -1) {
			key = roomId.substr(0, pos);   
			value = roomId.substr(pos + 1, roomId.size());
			m.insert(make_pair(key, value));
		}
		//statue : 1 ��ȡ���״̬
		pos = status.find(":");   
		if (pos != -1) {
			key = status.substr(0, pos);   
			value = status.substr(pos + 1, status.size());
			m.insert(make_pair(key, value));
		}

		//��Сmap�ŵ��������map��
		this->m_orderData.insert(make_pair(this->m_size, m));
		this->m_size++;
	}
	ifs.close();


	//��������map����
	//for (map<int, map<string, string>>::iterator it = m_orderData.begin();it != m_orderData.end();it++)
	//{
	//	cout << "����Ϊ�� " << it->first <<" value:"<< endl;
	//	for (map<string, string>::iterator mit = (*it).second.begin();mit != it->second.end();mit++)
	//	{
	//		cout << "key= " << mit->first << " value= " << mit->second << " ";
	//	}
	//	cout << endl;
	//}
}
//����ԤԼ
void OrderFile::updateOrder()
{
	if (this->m_size == 0)
	{
		return;
	}
	ofstream ofs;
	for (int i = 0;i < this->m_size;i++)
	{
		ofs << "date:" << this->m_orderData[i]["date"] << " ";
		ofs << "interval:" << this->m_orderData[i]["interval"] << " ";
		ofs << "stuId:" << this->m_orderData[i]["stuId"] << " ";
		ofs << "stuName:" << this->m_orderData[i]["stuName"] << " ";
		ofs << "roomId:" << this->m_orderData[i]["roomId"] << " ";
		ofs << "status:" << this->m_orderData[i]["status"] << endl;
	}
	ofs.close();
}