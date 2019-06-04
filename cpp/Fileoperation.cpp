#include "Fileoperation.h"

Fileoperation::Fileoperation()
{
	teacher_file.open("teacher.txt", ios::in);
	if (!teacher_file.is_open())
	{
		cout << "teacher.txt can not open\n";
		exit(1);
	}
	while (!teacher_file.eof())
	{
		Teacher temp = {};
		teacher_file >> temp.tea_num >> temp.name >> temp.password >> temp.phone >> temp.n;
		teacher_data.push_back(temp);
	}
	student_file.open("student.txt", ios::in);
	if (!(student_file.is_open()))
	{
		cout << "student.txt can not open\n";
		exit(1);
	}
	while (!student_file.eof())
	{
		Student temp = {};
		student_file >> temp.stu_num >> temp.name >> temp.password >> temp.CLASS >> temp.phone >> temp.topic_size;
		if (temp.topic_size)
			temp.topic = new int[temp.topic_size];
		else
			temp.topic = NULL;
		for (int i = 0; i < temp.topic_size; i++)
			student_file >> temp.topic[i];
		student_file >> temp.n;
		student_data.push_back(temp);
	}
}

vector<Student> Fileoperation::getstudent_data() const
{
	return student_data;
}

vector<Teacher> Fileoperation::getteacher_data() const
{
	return teacher_data;
}

void Fileoperation::setstudent_data(vector<Student>temp)
{
	student_data = temp;
}

void Fileoperation::setteacher(vector<Teacher>temp)
{
	teacher_data = temp;
}

Fileoperation::~Fileoperation()
{
	student_file.close();
	teacher_file.close();
	for (int i = 0; i < student_data.size(); i++)
	{
		delete []student_data[i].topic;
		student_data[i].topic = NULL;
	}
}