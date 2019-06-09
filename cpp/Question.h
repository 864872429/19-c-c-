#include "Fileoperation.h"
#ifndef _QUESTION_H
#define _QUESTION_H
class Question
{
public:
	Question(string);                        //将登入用户作为参数创建对象
	int search_problem(const string&) const; //输入题号返回题目在二维数组的位置
	int search_report();                     //输入用户名返回选题在二维数组的位置
	void create_problem();                   //老师发布选题
	void submit_problem();                   //学生提交选题
	void submit_report();                    //学生提交报告
	void DELETE(int);                        //学生删除某个报告（更改选题时）
	void review_problem();	                 //老师审核学生选题
	void review_report();                    //老师审核选题报告
	void display_problem();                  //显示所有选题选题


private:
	Fileoperation file;
	vector<Report> report_data;
	vector<Problem> problem_data;
	string user;
};


#endif