#include "fileoperation.h"

Fileoperation::Fileoperation(int x)
{
    fileRead(x);
}

QVector<User>& Fileoperation::get_student_data()
{
    fileRead(1);
	return student_data;
}

QVector<ADMIN>& Fileoperation::get_teacher_data()
{
    fileRead(2);
	return teacher_data;
}

QVector<Report>& Fileoperation::get_report_data()
{
    fileRead(4);
	return report_data;
}

QVector<Problem>& Fileoperation::get_problem_data()
{
    fileRead(8);
	return problem_data;
}

User& Fileoperation::get_student_data(const QString& temp)
{
	int i;
	for (i = 0; i <= student_data.size(); i++)
		if (student_data[i].student_num == temp)
			break;
	if (i == student_data.size())
	{
		cout << "找不到该学生";
		system("puase");
		exit(0);
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

void Fileoperation::set_student_data(const QVector<User>& temp)//其实可以不用传参
{
	student_data = temp;
    fileWrite(1);
}

void Fileoperation::set_teacher_data(const QVector<ADMIN>& temp)
{
	teacher_data = temp;
    fileWrite(2);
}

void Fileoperation::set_report_data(const QVector<Report>& temp)
{
	report_data = temp;
    fileWrite(4);
}

void Fileoperation::set_problem_data(const QVector<Problem>& temp)
{
	problem_data = temp;
    fileWrite(8);
}

void Fileoperation::fileWrite(int x)
{
	if (x & 1)
	{
        QFile temp_file(".\\student.txt");
        if(!temp_file.open(QIODevice::ReadWrite| QIODevice::Truncate))
        {
            cout<<"Can't open the student.txt!"<<endl;
        }
        QTextStream stream(&temp_file);
		for (int i = 0; i < student_data.size(); i++)
		{           
			if (i < student_data.size() - 1)
            {
                stream<<student_data[i].student_num.toUtf8()<<endl
                     <<student_data[i].name.toUtf8()<<endl
                    <<student_data[i].password.toUtf8()<<endl
                    <<student_data[i].CLASS.toUtf8()<<endl
                    <<student_data[i].phone.toUtf8()<<endl
                    <<student_data[i].topic.toUtf8()<<endl
                    <<student_data[i].score.toUtf8()<<endl
                    <<student_data[i].n.toUtf8()<<endl;
            }
            else
            {
                stream<<student_data[i].student_num.toUtf8()<<endl
                     <<student_data[i].name.toUtf8()<<endl
                    <<student_data[i].password.toUtf8()<<endl
                    <<student_data[i].CLASS.toUtf8()<<endl
                    <<student_data[i].phone.toUtf8()<<endl
                    <<student_data[i].topic.toUtf8()<<endl
                    <<student_data[i].score.toUtf8()<<endl
                    <<student_data[i].n.toUtf8();
            }
        }
        temp_file.close();
	}
	if (x & 2)
	{
        QFile temp_file(".\\teacher.txt");
        if(!temp_file.open(QIODevice::ReadWrite| QIODevice::Truncate))
        {
            cout<<"Can't open the teacher.txt!"<<endl;
        }
        QTextStream stream(&temp_file);
        for (int i = 0; i < teacher_data.size(); i++)
        {
            if (i < teacher_data.size() - 1)
            {
                stream<< teacher_data[i].teacher_num.toUtf8() << endl
                      << teacher_data[i].name.toUtf8() << endl
                      << teacher_data[i].password.toUtf8() << endl
                      << teacher_data[i].phone.toUtf8() << endl
                      << teacher_data[i].n.toUtf8() << endl;
            }
            else
            {
                stream<< teacher_data[i].teacher_num.toUtf8() << endl
                      << teacher_data[i].name.toUtf8() << endl
                      << teacher_data[i].password.toUtf8() << endl
                      << teacher_data[i].phone.toUtf8() << endl
                      << teacher_data[i].n.toUtf8();
            }
        }
        temp_file.close();
	}
	if (x & 4)
	{
        QFile temp_file(".\\report.txt");
        if(!temp_file.open(QIODevice::ReadWrite| QIODevice::Truncate))
        {
            cout<<"Can't open the report.txt!"<<endl;
        }
        QTextStream stream(&temp_file);
        for (int i = 0; i < report_data.size(); i++)
        {
            if (i < report_data.size() - 1)
            {
                stream<< report_data[i].problem_mun.toUtf8() << endl <<
                         report_data[i].student_num.toUtf8() << endl <<
                         report_data[i].status.toUtf8() << endl <<
                         report_data[i].content.toUtf8() << endl;
            }
            else
            {
                stream<< report_data[i].problem_mun.toUtf8() << endl <<
                         report_data[i].student_num.toUtf8() << endl <<
                         report_data[i].status.toUtf8() << endl <<
                         report_data[i].content.toUtf8();
            }
        }
        temp_file.close();
	}
	if (x & 8)
    {
        QFile temp_file(".\\problem.txt");
        if(!temp_file.open(QIODevice::ReadWrite| QIODevice::Truncate))
        {
            cout<<"Can't open the problem.txt!"<<endl;
        }
        QTextStream stream(&temp_file);
        for (int i = 0; i < problem_data.size(); i++)
        {
            if (i < problem_data.size() - 1)
            {
                stream<<problem_data[i].problem_num.toUtf8() << endl <<
                        problem_data[i].instruction.toUtf8() << endl <<
                        problem_data[i].max_num.toUtf8() << endl <<
                        problem_data[i].current_num.toUtf8() << endl <<
                        problem_data[i].status.toUtf8() << endl<<
                        problem_data[i].delete_reason.toUtf8()<<endl;

            }
            else
            {
                stream<<problem_data[i].problem_num.toUtf8() << endl <<
                        problem_data[i].instruction.toUtf8() << endl <<
                        problem_data[i].max_num.toUtf8() << endl <<
                        problem_data[i].current_num.toUtf8() << endl <<
                        problem_data[i].status.toUtf8() << endl<<
                        problem_data[i].delete_reason.toUtf8();
        temp_file.close();
            }
        }
    }
        }

void Fileoperation::fileRead(int x)
{
    if (x & 1)
    {
        QFile temp_file(".\\student.txt");
        if(!temp_file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            cout<<"Can't open the student.txt!"<<endl;
        }
        student_data.clear();
        QTextStream stream(&temp_file);
        while (!stream.atEnd())
        {
            User temp = {};
            QString cnt = stream.readLine();
            cnt = cnt.trimmed();
            temp.student_num=cnt;
            cnt = stream.readLine();
            cnt = cnt.trimmed();
            temp.name=cnt;
            cnt = stream.readLine();
            cnt = cnt.trimmed();
            temp.password=cnt;
            cnt = stream.readLine();
            cnt = cnt.trimmed();
            temp.CLASS=cnt;
            cnt = stream.readLine();
            cnt = cnt.trimmed();
            temp.phone=cnt;
            cnt = stream.readLine();
            cnt = cnt.trimmed();
            temp.topic=cnt;
            cnt = stream.readLine();
            cnt = cnt.trimmed();
            temp.score=cnt;
            cnt = stream.readLine();
            cnt = cnt.trimmed();
            temp.n=cnt;
            student_data.push_back(temp);
        }
        temp_file.close();
	}
	if (x & 2)
	{
        QFile temp_file(".\\teacher.txt");
        if(!temp_file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            cout<<"Can't open the teacher.txt!"<<endl;
        }
        teacher_data.clear();
        QTextStream stream(&temp_file);
        while (!stream.atEnd())
        {
            ADMIN temp = {};
            QString cnt = stream.readLine();
            cnt = cnt.trimmed();
            temp.teacher_num=cnt;
            cnt = stream.readLine();
            cnt = cnt.trimmed();
            temp.name=cnt;
            cnt = stream.readLine();
            cnt = cnt.trimmed();
            temp.password=cnt;
            cnt = stream.readLine();
            cnt = cnt.trimmed();
            temp.phone=cnt;
            cnt = stream.readLine();
            cnt = cnt.trimmed();
            temp.n=cnt;
            teacher_data.push_back(temp);
        }
        temp_file.close();
	}
	if (x & 4)
	{
        QFile temp_file(".\\report.txt");
        if(!temp_file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            cout<<"Can't open the report.txt!"<<endl;
        }
        report_data.clear();
        QTextStream stream(&temp_file);
        while (!stream.atEnd())
        {
            Report temp = {};
            QString cnt = stream.readLine();
            cnt = cnt.trimmed();
            temp.problem_mun=cnt;
            cnt = stream.readLine();
            cnt = cnt.trimmed();
            temp.student_num=cnt;
            cnt = stream.readLine();
            cnt = cnt.trimmed();
            temp.status=cnt;
            cnt = stream.readLine();
            cnt = cnt.trimmed();
            temp.content=cnt;
			report_data.push_back(temp);
		}
        temp_file.close();
	}
	if (x & 8)
	{
        QFile temp_file(".\\problem.txt");
        if(!temp_file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            cout<<"Can't open the problem.txt!"<<endl;
        }
        problem_data.clear();
        QTextStream stream(&temp_file);
        while (!stream.atEnd())
        {
            Problem temp = {};
            QString cnt = stream.readLine();
            cnt = cnt.trimmed();
            temp.problem_num=cnt;
            cnt = stream.readLine();
            cnt = cnt.trimmed();
            temp.instruction=cnt;
            cnt = stream.readLine();
            cnt = cnt.trimmed();
            temp.max_num=cnt;
            cnt = stream.readLine();
            cnt = cnt.trimmed();
            temp.current_num=cnt;
            cnt = stream.readLine();
            cnt = cnt.trimmed();
            temp.status=cnt;
            cnt = stream.readLine();
            cnt = cnt.trimmed();
            temp.delete_reason=cnt;
            problem_data.push_back(temp);
        }       
        temp_file.close();
    }
}

Fileoperation& Fileoperation::getFile()
{
    static Fileoperation file;
    return file;
}
