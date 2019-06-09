#include "Fileoperation.h"
#ifndef _QUESTION_H
#define _QUESTION_H
class Question
{
public:
	Question(string);                        //�������û���Ϊ������������
	int search_problem(const string&) const; //������ŷ�����Ŀ�ڶ�ά�����λ��
	int search_report();                     //�����û�������ѡ���ڶ�ά�����λ��
	void create_problem();                   //��ʦ����ѡ��
	void submit_problem();                   //ѧ���ύѡ��
	void submit_report();                    //ѧ���ύ����
	void DELETE(int);                        //ѧ��ɾ��ĳ�����棨����ѡ��ʱ��
	void review_problem();	                 //��ʦ���ѧ��ѡ��
	void review_report();                    //��ʦ���ѡ�ⱨ��
	void display_problem();                  //��ʾ����ѡ��ѡ��


private:
	Fileoperation file;
	vector<Report> report_data;
	vector<Problem> problem_data;
	string user;
};


#endif