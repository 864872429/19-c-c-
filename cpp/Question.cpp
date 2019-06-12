#include "Question.h"

Question_student::Question_student()
{
	report_data = file.get_report_data();
	problem_data = file.get_problem_data();
}

void Question_student::setuser(const string &x)
{
	user = x;
}

int Question_student::search_problem(const string& x) const
{
	for (int i = 0; i < problem_data.size(); i++)
		if (problem_data[i].problem_mun == x)
			return i;
	return -1;
}

int Question_student::search_report() const
{
	for (int i = 0; i < report_data.size(); i++)
		if (report_data[i].student_num== user&& report_data[i].status!="5")
			return i;
	return -1;
}

void Question_student::submit_problem()
{
	int i = search_report();
	if ( i != -1)
	{
		if (report_data[i].status == "2")
		{
			cout << "您当前已有选题，且报告已通过，无法更改选题";
			system("pause");
			return;
		}
		else if (report_data[i].status == "4")
		{
			cout << "您当前选题被老师删除，请重选\n";
			DELETE(i);
		}
		else if (report_data[i].status == "-2")
		{
			cout << "您当前选题未通过，请重选\n";
			DELETE(i);
		}
		else
		{
			cout << "您当前已有选题，处于";
			switch (stoi(report_data[i].status))
			{
			case -1:cout << "待审核"; break;
			case 0:cout << "未提交"; break;
			case 1:cout << "已提交"; break; 
			case 2:cout << "已通过"; break;
			case 3:cout << "未通过"; break;
			}
			cout << "状态\n" << "您想要更改选题吗？（y/n）";
			char ch;
			cin >> ch;
			if (ch != 'y' && ch != 'Y')
				return;
			else
				DELETE(i);
		}
	}
	while (1)
	{
		display_problem();
		Report temp;
		temp.student_num = user;
		temp.status = "-1";
		temp.content = "   ";
		cout << "请输入想选的题号（直接输入-1退出）：";
		getline(cin, temp.problem_mun);
		if (temp.problem_mun == "-1")
			return;
		if(search_problem(temp.problem_mun)==-1)
		{
			cout << "输入无效，请重试\n";
			system("pause");
		}
		else if (problem_data[search_problem(temp.problem_mun)].max_num > problem_data[search_problem(temp.problem_mun)].current_num)
		{
			problem_data[search_problem(temp.problem_mun)].current_num//选题人数加1
		    = to_string(stoi(problem_data[search_problem(temp.problem_mun)].current_num)+1);
			report_data.push_back(temp);
			file.set_report_data(report_data);
			file.set_problem_data(problem_data);
			cout << "选题成功，等待老师审核\n";
			system("pause");
			return;
		}
	}
}

void Question_student::submit_report()
{
	int i = search_report();
	if (i == -1)
	{
		cout << "您当前没有选题，赶紧选题呀老铁\n";
		system("pause");
		return;
	}
	else
	{
		cout << "下面是您目前的选题：\n";
		cout << "题号：" << report_data[i].problem_mun << endl;
		if (report_data[i].status == "-2")
		{
			cout << "该选题请求未通过审核，请重新选题\n";
			system("pause");
			return;
		}
		else if (report_data[i].status == "-1")
		{
			cout << "该选题请求正在审核中\n";
			system("pause");
			return;
		}
		if (report_data[i].status == "0")
		{
			cout << "选题请求已通过，请输入报告（请在一行内输入，回车结束，直接输入-1取消）\n";
			string x;
			getline(cin, x);
			if (x == "-1")
				return;
			report_data[i].content = x;
			report_data[i].status = "1";
			file.set_report_data(report_data);
			cout << "提交成功！\n";
			return;
		}
		if(report_data[i].status == "1")
		{
			cout << "内容：" << report_data[i].content << endl;
			cout << "选题报告正在审核中\n"
			 << "\n输入- 1更改,输入任意键继续\n";
			string x;
			getline(cin, x);
			if (x != "-1")
				return;
			getline(cin, x);
			report_data[i].content = x;
			report_data[i].status = "1";
			file.set_report_data(report_data);
			cout << "提交成功！\n";
			system("pause");
			return;
		}
		if (report_data[i].status == "2")
		{
			cout << "您的选题报告已通过，无需修改！\n";
			system("pause");
		}
		if (report_data[i].status == "3")
		{
			cout << "内容：" << report_data[i].content << endl;
			cout << "选题报告未通过，可更改重试或重新选题，输入- 1更改,输入任意键继续\n";
			string x;
			getline(cin, x);
			if (x != "-1")
				return;
			getline(cin, x);
			report_data[i].content = x;
			report_data[i].status = "1";
			file.set_report_data(report_data);
			report_data[i].status = "1";
			cout << "提交成功！\n";
			system("pause");
			return;
		}
		if (report_data[i].status == "4")
		{
			cout << "您的选题被老师删除，理由为：\n" << problem_data[search_problem(report_data[i].problem_mun)].delete_reason
				<<endl<<"请重新选题\n";
			system("pause");
		}
	}
}

void Question_student::DELETE(int i)
{
	problem_data[search_problem(report_data[i].problem_mun)].current_num//选题人数减1
	= to_string(stoi(problem_data[search_problem(report_data[i].problem_mun)].current_num)-1);
	report_data[i].status = '5';
	file.set_problem_data(problem_data);
	file.set_report_data(report_data);
}


void Question_student::display_problem() const
{
	system("cls");
	cout << "当前有以下选题可选：\n" << "题号	" << "发布老师工号	"  << "说明		" << "最大选题人数 " << "当前选题人数\n";
	for (int i = 0; i < problem_data.size(); i++)
		if (problem_data[i].status != "0"&& problem_data[i].status != "-1"&& problem_data[i].max_num>problem_data[i].current_num)
			cout << problem_data[i].problem_mun << "	" << problem_data[i].teacher_num << "		" << problem_data[i].instruction << "	" << problem_data[i].max_num << "	     " << problem_data[i].current_num<<endl;
}

Question_teacher::Question_teacher()
{
	report_data = file.get_report_data();
	problem_data = file.get_problem_data();
}

void Question_teacher::setuser(const string& x)
{
	user = x;
}

int Question_teacher::search_problem(const string& x) const
{
	for (int i = 0; i < problem_data.size(); i++)
		if (problem_data[i].problem_mun == x)
			return i;
	return -1;
}

int Question_teacher::search_report(const string& x) const
{
	for (int i = 0; i < report_data.size(); i++)
		if (report_data[i].problem_mun ==x && report_data[i].status != "5")
			return i;
	return -1;
}



void Question_teacher::create_problem()
{
	Problem temp;
	temp.teacher_num = user;
	cout << "请输入题号：";
	getline(cin, temp.problem_mun);
	cout << "请输入题目说明";
	getline(cin, temp.instruction);
	cout << "请输入最大选题人数";
	getline(cin, temp.max_num);
	temp.current_num = "0";
	temp.delete_reason = "";
	temp.status = "1";
	problem_data.push_back(temp);
	file.set_problem_data(problem_data);
	cout << "题目发布成功！";
}


void Question_teacher::review_problem()
{
	cout << "当前有以下待审核选题：\n" << "题号 学生学号 	题目说明	当前选题人数	";
	for (int i = 0; i < report_data.size(); i++)
		if (report_data[i].status == "-1")
		{
			cout << report_data[i].problem_mun << "	" << report_data[i].student_num << "	"
				<< problem_data[search_problem(report_data[i].problem_mun)].instruction << ""
				<< problem_data[search_problem(report_data[i].problem_mun)].current_num << endl;

		}
	string x;
	while (1)
	{
		cout << "请选择要操作的题号(直接输入-1退出)：";
		cin >> x;
		if (x == "-1")
			return;
		if (report_data[search_report(x)].status == "-1")
			break;
		cout << "输入无效请重试";
	}
	system("cls");
	while (1)
	{
		int temp;
		cout << "您当前选择" << x << "题，请输入你想进行的操作：\n" << "1.同意选题 \n" << "2.不同意选题"
			<< "3.退出";
		cin >> temp;
		switch (temp)
		{
		case 1:report_data[search_report(x)].status = "0"; file.set_report_data(report_data); return;
		case 2:report_data[search_report(x)].status = "-2"; file.set_report_data(report_data); return;
		case 3: return;
		}
	}
}

void Question_teacher::review_report()
{
	cout << "当前有以下待审核报告：\n" << "题号 学生学号 	题目说明	当前选题人数	";
	for (int i = 0; i < report_data.size(); i++)
		if (report_data[i].status == "1")
		{
			cout << report_data[i].problem_mun << "	" << report_data[i].student_num << "	"
				<< problem_data[search_problem(report_data[i].problem_mun)].instruction << ""
				<< problem_data[search_problem(report_data[i].problem_mun)].current_num << endl;

		}
	string x;
	while (1)
	{
		cout << "请选择要操作的题号(直接输入-1退出)：";
		cin >> x;
		if (x == "-1")
			return;
		if (report_data[search_report(x)].status == "1")
			break;
		cout << "输入无效请重试";
	}
	system("cls");
	while (1)
	{
		int temp;
		cout << "您当前选择" << x << "题，请输入你想进行的操作：\n" << "1.通过报告 \n" << "2.不通过报告"
			<< "3.退出";
		cin >> temp;
		switch (temp)
		{
		case 1:report_data[search_report(x)].status = "2"; file.set_report_data(report_data); return;
		case 2:report_data[search_report(x)].status = "3"; file.set_report_data(report_data); return;
		case 3: return;
		}
	}
}
