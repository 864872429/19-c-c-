#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
using namespace std;

#ifndef _FILEOPERATION_H
#define _FILEOPERATION_H

struct User                  //因为Student被作为类名了，就叫User吧。
{
	string stu_num;          //学号
	string name;             //姓名
	string password;         //密码
	string CLASS;            //班级，class是关键字，所以大写
	string phone;            //电话
	string topic;               //选题号 -1表示未选题 0表示待审核
	bool n;                  //若被删除，该值为0
	//其他数据待补充
};

struct Admin                 //因为Teacher被作为类名了，就叫Admin吧。
{
	string tea_num;          //工号
	string name;             //姓名
	string password;         //密码
	string phone;            //电话
	bool n;                  //若被删除，该值为0
	//其他数据待补充
};

struct Report                //选题报告
{
	string problem_mun;      //题号
	string stu_num;          //选题学生学号
	string status;           //状态(-1-未提交 0-待审核 1-已通过 2-未通过 3-被老师删除)
	string content;          //报告内容
	//其他数据待补充
};

struct Problem                    //题目
{
	string tea_num;               //发布老师工号
	string munber;                //题号
	string instruction;           //说明
	string max_num;               //最大选题人数
	string current_num;           //当前选题人数
	string status;                //若被删除，该值为0，若为-1，则有删除理由
	string delete_reason;         //删除理由
	//其他数据待补充
};

class Fileoperation
{
public:
	Fileoperation();

	vector<User> get_student_data();
	vector<Admin> get_teacher_data();
	vector<Report> get_report_data();
	vector<Problem> get_problem_data();

	void set_student_data(vector<User>temp);
	void set_teacher_data(vector<Admin>temp);
	void set_report_data(vector<Report>temp);
	void set_problem_data(vector<Problem>temp);


	void fileWrite(int);//输入0-15;1-学生，2-老师，4-报告，8-选题。
	void fileRead(int); //输入0-15;1-学生，2-老师，4-报告，8-选题。

	~Fileoperation();
private:
	fstream student_file;
	fstream teacher_file;
	fstream report_file;
	fstream problem_file;
	vector<User> student_data;
	vector<Admin> teacher_data;
	vector<Report> report_data;
	vector<Problem> problem_data;
};

#endif // !Fileoperation.h

