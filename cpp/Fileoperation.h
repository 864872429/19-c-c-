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
	string student_num;      //学号
	string name;             //姓名
	string password;         //密码
	string CLASS;            //班级，class是关键字，所以大写
	string phone;            //电话
	string topic;            //选题号 -1表示未选题 0表示待审核
	bool n;                  //若被删除，该值为0
	//其他数据待补充
};

struct Admin                 //因为Teacher被作为类名了，就叫Admin吧。
{
	string teacher_num;      //工号
	string name;             //姓名
	string password;         //密码
	string phone;            //电话
	bool n;                  //若被删除，该值为0
	//其他数据待补充
};

struct Report                //选题报告
{
	string problem_mun;      //题号
	string student_num;      //选题学生学号
	string status;           //状态(-2-选题未通过 -1-待审核 0-未提交 1-已提交 2-已通过 3-报告未通过 4-被老师删除 5-被删除)
	string content;          //报告内容
	//其他数据待补充
};

struct Problem                    //题目
{
	string teacher_num;           //发布老师工号
	string problem_mun;           //题号
	string instruction;           //说明
	string max_num;               //最大选题人数
	string current_num;           //当前选题人数
	string status;                //若被删除，该值为0或-1，-1表示有删除理由
	string delete_reason;         //删除理由
	//其他数据待补充
};

class Fileoperation
{
public:
	Fileoperation(int = 15);

	vector<User>& get_student_data();
	vector<Admin>& get_teacher_data();
	vector<Report>& get_report_data();
	vector<Problem>& get_problem_data();
	User& get_student_data(const string&);

	void set_student_data(const User&);
	void set_student_data(const vector<User>&);
	void set_teacher_data(const vector<Admin>&);
	void set_report_data(const vector<Report>&);
	void set_problem_data(const vector<Problem>&);


	void fileWrite(int);//输入0-15;1-学生，2-老师，4-报告，8-选题。
	void fileRead(int); //输入0-15;1-学生，2-老师，4-报告，8-选题。

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

