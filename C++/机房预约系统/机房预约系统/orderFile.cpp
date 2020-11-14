#include"orderFile.h"

//构造函数
OrderFile::OrderFile()
{
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	string date;        //读取的日期
	string interval;    //时间段
	string stuId;       //学生编号
	string stuName;     //学生姓名
	string roomId;      //学生学号
	string status;      //审核状态

	this->m_size = 0;
	while (ifs >> date && ifs >> interval && ifs >> stuId && ifs >> stuName && ifs >> roomId && ifs >> status)
	{
		//	cout << date << endl;
		//	cout << interval << endl;
		//	cout << stuId << endl;
		//	cout << stuName << endl;
		//	cout << roomId << endl;
		//	cout << status << endl;
		//测试结果
		//date:1
		//interval : 1
		//stuId : 1
		//stuName : 薛屹盛
		//room : 1
		//statue : 1

		//date:1
		string key;
		string value;
		map<string, string>m;

		//date:1 截取日期
		int pos = date.find(":");   //找到的下标为4 ,d0 a1 t2 e3 :4
		if (pos != -1) {
			key = date.substr(0, pos);    //截走date  key="date"
			value = date.substr(pos + 1, date.size());
			m.insert(make_pair(key, value));
		}
		//cout << "key= " << key << endl;
		//cout << "value= " << value << endl;
		//interval : 1 截取时间段
		pos = interval.find(":");  
		if (pos != -1) {
			key = interval.substr(0, pos);   
			value = interval.substr(pos + 1, interval.size());
			m.insert(make_pair(key, value));
		}
		//stuId : 1  截取学生号
		pos = stuId.find(":");  
		if (pos != -1) {
			key = stuId.substr(0, pos);    
			value = stuId.substr(pos + 1, stuId.size());
			m.insert(make_pair(key, value));
		}
		//stuName : 薛屹盛  截取姓名
		pos = stuName.find(":");   
		if (pos != -1) {
			key = stuName.substr(0, pos);   
			value = stuName.substr(pos + 1, stuName.size());
			m.insert(make_pair(key, value));
		}
		//room : 1  截取机房号
		pos = roomId.find(":");   
		if (pos != -1) {
			key = roomId.substr(0, pos);   
			value = roomId.substr(pos + 1, roomId.size());
			m.insert(make_pair(key, value));
		}
		//statue : 1 截取审核状态
		pos = status.find(":");   
		if (pos != -1) {
			key = status.substr(0, pos);   
			value = status.substr(pos + 1, status.size());
			m.insert(make_pair(key, value));
		}

		//将小map放到大的容器map中
		this->m_orderData.insert(make_pair(this->m_size, m));
		this->m_size++;
	}
	ifs.close();


	//测试最大的map容器
	//for (map<int, map<string, string>>::iterator it = m_orderData.begin();it != m_orderData.end();it++)
	//{
	//	cout << "条数为： " << it->first <<" value:"<< endl;
	//	for (map<string, string>::iterator mit = (*it).second.begin();mit != it->second.end();mit++)
	//	{
	//		cout << "key= " << mit->first << " value= " << mit->second << " ";
	//	}
	//	cout << endl;
	//}
}
//更新预约
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