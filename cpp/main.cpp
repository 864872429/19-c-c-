#include "Fileoperation.h"

//void display(vector<User> , vector<Admin> , vector<Report> , vector<Problem>);//����һ�����Ժ��������������Ƿ���ȷ��ȡ

int main()
{
	Fileoperation test;   //�ڹ��캯��ʱ����ļ��ж�ȡ���ݴ���ṹ������
	vector<User> student_data= test.get_student_data();//ʹ��getstudent_data��getteacher_data������ȡ�����ļ����ݵĽṹ������
	vector<Admin> teacher_data= test.get_teacher_data();
	vector<Report> report_data = test.get_report_data();
	vector<Problem> problem_data = test.get_problem_data();
//	display( student_data,teacher_data, report_data, problem_data);
	test.set_student_data(student_data);//����setstudent_data���������ĵ�����д���ļ�
	test.set_teacher_data(teacher_data);
	return 0;
}

//void display(vector<User> student_data, vector<Admin> teacher_data, vector<Report> report_data, vector<Problem> problem_data)//����һ�����Ժ��������������Ƿ���ȷ��ȡ
//{
//	system("cls");
//
//	cout << "�����ǽ�ʦ��Ϣ:\n"<< "����	" << "����	" << "�绰\n";
//	for (int i = 0; i < teacher_data.size(); i++)
//		if (teacher_data[i].n)//n=0��ζ�Ÿ��ɾ��
//			cout << teacher_data[i].tea_num << "	" << teacher_data[i].name << "	" << teacher_data[i].phone << endl;
//
//	cout << "������ѧ����Ϣ:\n"<< "����	" << "����	" << "�绰	" << "	ѡ��\n";
//	for (int i = 0; i < student_data.size(); i++)
//		if (student_data[i].n)//n=0��ζ�Ÿ��ɾ��
//		{
//			cout << student_data[i].stu_num << "	" << student_data[i].name << "	" << student_data[i].phone ;
//				if(student_data[i].topic == "-1")
//					cout << " " << endl;
//				else
//					cout<<"	"<<student_data[i].topic  << endl;
//		}
//	cout << "������ѧ��ѡ�ⱨ����Ϣ\n"  << "���	" << "ѡ��ѧ��ѧ��  " << "״̬ " << "��������\n";
//	for (int i = 0; i < report_data.size(); i++)
//	{		
//		cout << report_data[i].problem_mun << "	" << report_data[i].stu_num << "      	" << report_data[i].status << "   " << report_data[i].content << endl;
//	}
//	cout << "��������Ŀ��Ϣ\n" << "������ʦ����	" << "���	" << "˵��		" << "���ѡ������ " << "��ǰѡ������ " << "ɾ������\n";
//	for (int i = 0; i < problem_data.size(); i++)
//	{
//		if (problem_data[i].status != "0")
//		{
//			cout << problem_data[i].tea_num << "		" << problem_data[i].munber << "	" << problem_data[i].instruction << "	" << problem_data[i].max_num << "	     " << problem_data[i].current_num;
//			if (problem_data[i].status != "-1")
//				cout << " " << endl;
//			else
//				cout << "	  	" << problem_data[i].delete_reason << endl;
//		}
//	}
//}
