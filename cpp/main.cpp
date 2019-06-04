#include "Fileoperation.h"

void display(vector< Student > , vector< Teacher > );//这是一个测试函数，测试数据是否正确读取

int main()
{
	Fileoperation test;   //在构造函数时会从文件中读取数据存入结构体数组
	vector<Student> student_data= test.getstudent_data();//使用getstudent_data和getteacher_data函数获取存有文件数据的结构体数组
	vector<Teacher> teacher_data= test.getteacher_data();
	display( student_data,teacher_data );
	//test.setstudent_data(student_data);//可用setstudent_data函数将更改的数据写回文件（暂时还没写）
	//test.setteacher_data(teacher_data);
	return 0;
}

void display(vector< Student> student_data, vector< Teacher > teacher_data)//这是一个测试函数，测试数据是否正确读取
{
	system("cls");

	cout << "下面是教师信息:\n";
	cout << "工号	" << "姓名	" << "电话\n";
	for (int i = 0; i < teacher_data.size(); i++)
		if (teacher_data[i].n)//n=0意味着该项被删除
			cout << teacher_data[i].tea_num << "	" << teacher_data[i].name << "	" << teacher_data[i].phone << endl;

	cout << "下面是学生信息:\n";
	cout << "工号	" << "姓名	" << "电话	" << "	选题\n";
	for (int i = 0; i < student_data.size(); i++)
		if (student_data[i].n)//n=0意味着该项被删除
		{
			cout << student_data[i].stu_num << "	" << student_data[i].name << "	" << student_data[i].phone;
			for (int j = 0; j < student_data[i].topic_size; j++)
				cout << "	" << student_data[i].topic[j];
			cout << endl;
		}

}