#include "Fileoperation.h"

Fileoperation::Fileoperation(int x)
{
	fileRead(x);
}

vector<User>& Fileoperation::get_student_data() 
{
	return student_data;
}

vector<Admin>& Fileoperation::get_teacher_data() 
{
	return teacher_data;
}

vector<Report>& Fileoperation::get_report_data()
{
	return report_data;
}

vector<Problem>& Fileoperation::get_problem_data()
{
	return problem_data;
}

User& Fileoperation::get_student_data(const string& temp)
{
	int i;
	for (i = 0; i <= student_data.size(); i++)
		if (student_data[i].student_num == temp)
			break;
	if (i == student_data.size())
	{
		cout << "找不到该学生";
		system("puase");
		return;
	}
	else
		return student_data[i];
}

void Fileoperation::set_student_data(const User& temp)
{
	int i;
	for (i = 0; i <= student_data.size(); i++)
		if (student_data[i].student_num == temp.student_num)
			break;
	if (i == student_data.size())
	{
		cout << "找不到该学生";
		system("puase");
		return;
	}
	else
		student_data[i] = temp;
}

void Fileoperation::set_student_data(const vector<User>& temp)
{
	student_data = temp;
	fileWrite(1);
}

void Fileoperation::set_teacher_data(const vector<Admin>& temp)
{
	teacher_data = temp;
	fileWrite(2);
}

void Fileoperation::set_report_data(const vector<Report>& temp)
{
	report_data = temp;
	fileWrite(4);
}

void Fileoperation::set_problem_data(const vector<Problem>& temp)
{
	problem_data = temp;
	fileWrite(8);
}

void Fileoperation::fileWrite(int x)
{
	if (x & 1)
	{
		student_file.open("student.txt", ios::out | ios::trunc);
		if (!(student_file.is_open()))
		{
			cout << "student.txt can not open\n";
			exit(1);
		}
		for (int i = 0; i < student_data.size(); i++)
		{
			if (i < student_data.size() - 1)
				student_file << student_data[i].student_num << " " << student_data[i].name << " " << student_data[i].password << " " << student_data[i].CLASS << " " << student_data[i].phone << " " << student_data[i].topic << " " << student_data[i].n << endl;
			else
				student_file << student_data[i].student_num << " " << student_data[i].name << " " << student_data[i].password << " " << student_data[i].CLASS << " " << student_data[i].phone << " " << student_data[i].topic << " " << student_data[i].n;
		}
		student_file.close();
	}
	if (x & 2)
	{
		teacher_file.open("teacher.txt", ios::out | ios::trunc);
		if (!teacher_file.is_open())
		{
			cout << "teacher.txt can not open\n";
			exit(1);
		}
		for (int i = 0; i < teacher_data.size(); i++)
		{
			if (i < teacher_data.size() - 1)
				teacher_file << teacher_data[i].teacher_num << " " << teacher_data[i].name << " " << teacher_data[i].password << " " << teacher_data[i].phone << " " << teacher_data[i].n << endl;
			else
				teacher_file << teacher_data[i].teacher_num << " " << teacher_data[i].name << " " << teacher_data[i].password << " " << teacher_data[i].phone << " " << teacher_data[i].n;
		}
		teacher_file.close();
	}
	if (x & 4)
	{
		report_file.open("report.txt", ios::out | ios::trunc);
		if (!report_file.is_open())
		{
			cout << "report.txt can not open\n";
			exit(1);
		}
		for (int i = 0; i < report_data.size(); i++)
		{
			if (i < report_data.size() - 1)
				report_file << report_data[i].problem_mun << endl << report_data[i].student_num << endl << report_data[i].status << endl << report_data[i].content << endl;
			else
				report_file << report_data[i].problem_mun << endl << report_data[i].student_num << endl << report_data[i].status << endl << report_data[i].content;
		}
		report_file.close();
	}
	if (x & 8)
	{
		problem_file.open("problem.txt", ios::out | ios::trunc);
		if (!problem_file.is_open())
		{
			cout << "problem.txt can not open\n";
			exit(1);
		}
		for (int i = 0; i < problem_data.size(); i++)
		{
			if (i < problem_data.size() - 1)
			{
				problem_file << problem_data[i].teacher_num << endl << problem_data[i].problem_mun << endl << problem_data[i].instruction << endl << problem_data[i].max_num << endl << problem_data[i].current_num << endl << problem_data[i].status << endl;
				if (problem_data[i].status == "-1")
					problem_file << problem_data[i].delete_reason << endl;
			}
			else
			{
				if (problem_data[i].status != "-1")			
					problem_file << problem_data[i].teacher_num << endl << problem_data[i].problem_mun << endl << problem_data[i].instruction << endl << problem_data[i].max_num << endl << problem_data[i].current_num << endl << problem_data[i].status;
				else
					problem_file << problem_data[i].teacher_num << endl << problem_data[i].problem_mun << endl << problem_data[i].instruction << endl << problem_data[i].max_num << endl << problem_data[i].current_num << endl << problem_data[i].status << problem_data[i].delete_reason;
			}
		}
		problem_file.close();
	}
}


void Fileoperation::fileRead(int x)
{
	if (x & 1)
	{
		student_data.clear();
		student_file.open("student.txt", ios::in);
		if (!(student_file.is_open()))
		{
			cout << "student.txt can not open\n";
			exit(1);
		}
		while (!student_file.eof())
		{
			User temp = {};
			student_file >> temp.student_num >> temp.name >> temp.password >> temp.CLASS >> temp.phone >> temp.topic >> temp.n;
			student_data.push_back(temp);
		}
		student_file.close();
	}
	if (x & 2)
	{
		teacher_data.clear();
		teacher_file.open("teacher.txt", ios::in);
		if (!teacher_file.is_open())
		{
			cout << "teacher.txt can not open\n";
			exit(1);
		}
		while (!teacher_file.eof())
		{
			Admin temp = {};
			teacher_file >> temp.teacher_num >> temp.name >> temp.password >> temp.phone >> temp.n;
			teacher_data.push_back(temp);
		}
		teacher_file.close();
	}
	if (x & 4)
	{
		report_data.clear();
		report_file.open("report.txt", ios::in);
		if (!report_file.is_open())
		{
			cout << "report.txt can not open\n";
			exit(1);
		}
		while (!report_file.eof())
		{
			Report temp = {};
			getline(report_file, temp.problem_mun);
			getline(report_file, temp.student_num);
			getline(report_file, temp.status);
			if (temp.status != "-1")
				getline(report_file, temp.content);
			report_data.push_back(temp);
		}
		report_file.close();
	}
	if (x & 8)
	{
		problem_data.clear();
		problem_file.open("problem.txt", ios::in);
		if (!problem_file.is_open())
		{
			cout << "problem.txt can not open\n";
			exit(1);
		}
		while (!problem_file.eof())
		{
			Problem temp = {};
			getline(problem_file, temp.teacher_num);
			getline(problem_file, temp.problem_mun);
			getline(problem_file, temp.instruction);
			getline(problem_file, temp.max_num);
			getline(problem_file, temp.current_num);
			getline(problem_file, temp.status);
			if(temp.status =="-1")
				getline(problem_file, temp.delete_reason);
			problem_data.push_back(temp);		
		}
		problem_file.close();
	}
}
