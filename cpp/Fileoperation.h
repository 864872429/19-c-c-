#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
using namespace std;

#ifndef _FILEOPERATION_H
#define _FILEOPERATION_H

struct User                  //��ΪStudent����Ϊ�����ˣ��ͽ�User�ɡ�
{
	string stu_num;          //ѧ��
	string name;             //����
	string password;         //����
	string CLASS;            //�༶��class�ǹؼ��֣����Դ�д
	string phone;            //�绰
	string topic;               //ѡ��� -1��ʾδѡ�� 0��ʾ�����
	bool n;                  //����ɾ������ֵΪ0
	//�������ݴ�����
};

struct Admin                 //��ΪTeacher����Ϊ�����ˣ��ͽ�Admin�ɡ�
{
	string tea_num;          //����
	string name;             //����
	string password;         //����
	string phone;            //�绰
	bool n;                  //����ɾ������ֵΪ0
	//�������ݴ�����
};

struct Report                //ѡ�ⱨ��
{
	string problem_mun;      //���
	string stu_num;          //ѡ��ѧ��ѧ��
	string status;           //״̬(-1-δ�ύ 0-����� 1-��ͨ�� 2-δͨ�� 3-����ʦɾ��)
	string content;          //��������
	//�������ݴ�����
};

struct Problem                    //��Ŀ
{
	string tea_num;               //������ʦ����
	string munber;                //���
	string instruction;           //˵��
	string max_num;               //���ѡ������
	string current_num;           //��ǰѡ������
	string status;                //����ɾ������ֵΪ0����Ϊ-1������ɾ������
	string delete_reason;         //ɾ������
	//�������ݴ�����
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


	void fileWrite(int);//����0-15;1-ѧ����2-��ʦ��4-���棬8-ѡ�⡣
	void fileRead(int); //����0-15;1-ѧ����2-��ʦ��4-���棬8-ѡ�⡣

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

