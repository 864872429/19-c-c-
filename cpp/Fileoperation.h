#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
using namespace std;

#ifndef _FILEOPERATION_H
#define _FILEOPERATION_H

struct Student
{
	string stu_num;  //ѧ��
	string name;     //����
	string password; //����
	string CLASS;    //�༶��class�ǹؼ��֣����Դ�д
	string phone;    //�绰
	int* topic;      //ѡ���������
	int topic_size;  //ѡ����
	bool n;          //����ɾ������ֵΪ0
	//�������ݴ�����
};

struct Teacher
{
	string tea_num;  //����
	string name;     //����
	string password; //����
	string phone;    //�绰
	bool n;          //����ɾ������ֵΪ0
	//�������ݴ�����
};


class Fileoperation
{
public:
	Fileoperation();

	vector< Student > getstudent_data() const;
	vector< Teacher > getteacher_data() const;

	void setstudent_data(vector< Student >temp);
	void setteacher(vector< Teacher >temp);

	~Fileoperation();

private:
	fstream student_file;
	fstream teacher_file;
	vector< Student > student_data;
	vector< Teacher > teacher_data;
};

#endif // !Fileoperation.h

