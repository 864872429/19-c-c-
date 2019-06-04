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
	string stu_num;  //学号
	string name;     //姓名
	string password; //密码
	string CLASS;    //班级，class是关键字，所以大写
	string phone;    //电话
	int* topic;      //选题题号数组
	int topic_size;  //选题数
	bool n;          //若被删除，该值为0
	//其他数据待补充
};

struct Teacher
{
	string tea_num;  //工号
	string name;     //姓名
	string password; //密码
	string phone;    //电话
	bool n;          //若被删除，该值为0
	//其他数据待补充
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

