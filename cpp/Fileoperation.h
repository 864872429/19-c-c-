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
	string student_num;      //ѧ��
	string name;             //����
	string password;         //����
	string CLASS;            //�༶��class�ǹؼ��֣����Դ�д
	string phone;            //�绰
	string topic;            //ѡ��� -1��ʾδѡ�� 0��ʾ�����
	bool n;                  //����ɾ������ֵΪ0
	//�������ݴ�����
};

struct Admin                 //��ΪTeacher����Ϊ�����ˣ��ͽ�Admin�ɡ�
{
	string teacher_num;      //����
	string name;             //����
	string password;         //����
	string phone;            //�绰
	bool n;                  //����ɾ������ֵΪ0
	//�������ݴ�����
};

struct Report                //ѡ�ⱨ��
{
	string problem_mun;      //���
	string student_num;      //ѡ��ѧ��ѧ��
	string status;           //״̬(-2-ѡ��δͨ�� -1-����� 0-δ�ύ 1-���ύ 2-��ͨ�� 3-����δͨ�� 4-����ʦɾ�� 5-��ɾ��)
	string content;          //��������
	//�������ݴ�����
};

struct Problem                    //��Ŀ
{
	string teacher_num;           //������ʦ����
	string problem_mun;           //���
	string instruction;           //˵��
	string max_num;               //���ѡ������
	string current_num;           //��ǰѡ������
	string status;                //����ɾ������ֵΪ0��-1��-1��ʾ��ɾ������
	string delete_reason;         //ɾ������
	//�������ݴ�����
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


	void fileWrite(int);//����0-15;1-ѧ����2-��ʦ��4-���棬8-ѡ�⡣
	void fileRead(int); //����0-15;1-ѧ����2-��ʦ��4-���棬8-ѡ�⡣

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

