#include "Fileoperation.h"
#ifndef _QUESTION_H
#define _QUESTION_H

class Question
{

//�������������Щ��Ȼ��̳У���ʱ���д
/*public:
	void setuser(const string&);             
	int search_problem(const string&) const;
	int search_report(const string&) const;         */   
};


class Question_student :public Question
{
public:
	Question_student();    
	void setuser(const string&);             //��������û�
	int search_problem(const string&) const;//������ŷ�����Ŀ�ڶ�ά�����λ��
	int search_report() const;              //����ѧ���û�������ѡ���ڶ�ά�����λ��
	void submit_problem();                  //ѧ���ύѡ��
	void submit_report();                   //ѧ���ύ����
	void DELETE(int);                       //ѧ��ɾ��ĳ�����棨����ѡ��ʱ��
	void display_problem()const;                 //��ʾ���п���ѡ��ѡ��

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
	void setuser(const string&);             //��������û�
	int search_problem(const string&) const; //������ŷ�����Ŀ�ڶ�ά�����λ��
	int search_report(const string&) const;
	void create_problem();                  //��ʦ����ѡ��
	void review_problem();                  //��ʦ���ѡ��
	void review_report();                   //��ʦ��˱���

private:
	Fileoperation file;
	vector<Report> report_data;
	vector<Problem> problem_data;
	string user;
};

#endif

