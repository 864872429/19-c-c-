#include "Fileoperation.h"
#ifndef _QUESTION_H
#define _QUESTION_H

class Question
{

//打算在这里放这些，然后继承，有时间就写
/*public:
	void setuser(const string&);             
	int search_problem(const string&) const;
	int search_report(const string&) const;         */   
};


class Question_student :public Question
{
public:
	Question_student();    
	void setuser(const string&);             //输入登入用户
	int search_problem(const string&) const;//输入题号返回题目在二维数组的位置
	int search_report() const;              //根据学生用户名返回选题在二维数组的位置
	void submit_problem();                  //学生提交选题
	void submit_report();                   //学生提交报告
	void DELETE(int);                       //学生删除某个报告（更改选题时）
	void display_problem()const;                 //显示所有可用选题选题

private:
	Fileoperation file;
	vector<Report> report_data;
	vector<Problem> problem_data;
	string user;
};

class Question_teacher :public Question
{
public:
	Question_teacher();
	void setuser(const string&);             //输入登入用户
	int search_problem(const string&) const; //输入题号返回题目在二维数组的位置
	int search_report(const string&) const;
	void create_problem();                  //老师发布选题
	void review_problem();                  //老师审核选题
	void review_report();                   //老师审核报告

private:
	Fileoperation file;
	vector<Report> report_data;
	vector<Problem> problem_data;
	string user;
};

#endif

