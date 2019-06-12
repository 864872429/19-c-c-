#include "Question.h"

//void display(vector<User> , vector<Admin> , vector<Report> , vector<Problem>);//这是一个测试函数，测试数据是否正确读取

int main()
{
	Question_student test;
	test.setuser("S0001");
	test.submit_report();
	test.submit_problem();
	return 0;
}

//void display(vector<User> student_data, vector<Admin> teacher_data, vector<Report> report_data, vector<Problem> problem_data)//这是一个测试函数，测试数据是否正确读取
//{
//	system("cls");
//
//	cout << "下面是教师信息:\n"<< "工号	" << "姓名	" << "电话\n";
//	for (int i = 0; i < teacher_data.size(); i++)
//		if (teacher_data[i].n)//n=0意味着该项被删除
//			cout << teacher_data[i].tea_num << "	" << teacher_data[i].name << "	" << teacher_data[i].phone << endl;
//
//	cout << "下面是学生信息:\n"<< "工号	" << "姓名	" << "电话	" << "	选题\n";
//	for (int i = 0; i < student_data.size(); i++)
//		if (student_data[i].n)//n=0意味着该项被删除
//		{
//			cout << student_data[i].stu_num << "	" << student_data[i].name << "	" << student_data[i].phone ;
//				if(student_data[i].topic == "-1")
//					cout << " " << endl;
//				else
//					cout<<"	"<<student_data[i].topic  << endl;
//		}
//	cout << "下面是学生选题报告信息\n"  << "题号	" << "选题学生学号  " << "状态 " << "报告内容\n";
//	for (int i = 0; i < report_data.size(); i++)
//	{		
//		cout << report_data[i].problem_mun << "	" << report_data[i].stu_num << "      	" << report_data[i].status << "   " << report_data[i].content << endl;
//	}
//	cout << "下面是题目信息\n" << "发布老师工号	" << "题号	" << "说明		" << "最大选题人数 " << "当前选题人数 " << "删除理由\n";
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
