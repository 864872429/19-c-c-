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
			cout << "����ǰ����ѡ�⣬�ұ�����ͨ�����޷�����ѡ��";
			system("pause");
			return;
		}
		else if (report_data[i].status == "4")
		{
			cout << "����ǰѡ�ⱻ��ʦɾ��������ѡ\n";
			DELETE(i);
		}
		else if (report_data[i].status == "-2")
		{
			cout << "����ǰѡ��δͨ��������ѡ\n";
			DELETE(i);
		}
		else
		{
			cout << "����ǰ����ѡ�⣬����";
			switch (stoi(report_data[i].status))
			{
			case -1:cout << "�����"; break;
			case 0:cout << "δ�ύ"; break;
			case 1:cout << "���ύ"; break; 
			case 2:cout << "��ͨ��"; break;
			case 3:cout << "δͨ��"; break;
			}
			cout << "״̬\n" << "����Ҫ����ѡ���𣿣�y/n��";
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
		cout << "��������ѡ����ţ�ֱ������-1�˳�����";
		getline(cin, temp.problem_mun);
		if (temp.problem_mun == "-1")
			return;
		if(search_problem(temp.problem_mun)==-1)
		{
			cout << "������Ч��������\n";
			system("pause");
		}
		else if (problem_data[search_problem(temp.problem_mun)].max_num > problem_data[search_problem(temp.problem_mun)].current_num)
		{
			problem_data[search_problem(temp.problem_mun)].current_num//ѡ��������1
		    = to_string(stoi(problem_data[search_problem(temp.problem_mun)].current_num)+1);
			report_data.push_back(temp);
			file.set_report_data(report_data);
			file.set_problem_data(problem_data);
			cout << "ѡ��ɹ����ȴ���ʦ���\n";
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
		cout << "����ǰû��ѡ�⣬�Ͻ�ѡ��ѽ����\n";
		system("pause");
		return;
	}
	else
	{
		cout << "��������Ŀǰ��ѡ�⣺\n";
		cout << "��ţ�" << report_data[i].problem_mun << endl;
		if (report_data[i].status == "-2")
		{
			cout << "��ѡ������δͨ����ˣ�������ѡ��\n";
			system("pause");
			return;
		}
		else if (report_data[i].status == "-1")
		{
			cout << "��ѡ���������������\n";
			system("pause");
			return;
		}
		if (report_data[i].status == "0")
		{
			cout << "ѡ��������ͨ���������뱨�棨����һ�������룬�س�������ֱ������-1ȡ����\n";
			string x;
			getline(cin, x);
			if (x == "-1")
				return;
			report_data[i].content = x;
			report_data[i].status = "1";
			file.set_report_data(report_data);
			cout << "�ύ�ɹ���\n";
			return;
		}
		if(report_data[i].status == "1")
		{
			cout << "���ݣ�" << report_data[i].content << endl;
			cout << "ѡ�ⱨ�����������\n"
			 << "\n����- 1����,�������������\n";
			string x;
			getline(cin, x);
			if (x != "-1")
				return;
			getline(cin, x);
			report_data[i].content = x;
			report_data[i].status = "1";
			file.set_report_data(report_data);
			cout << "�ύ�ɹ���\n";
			system("pause");
			return;
		}
		if (report_data[i].status == "2")
		{
			cout << "����ѡ�ⱨ����ͨ���������޸ģ�\n";
			system("pause");
		}
		if (report_data[i].status == "3")
		{
			cout << "���ݣ�" << report_data[i].content << endl;
			cout << "ѡ�ⱨ��δͨ�����ɸ������Ի�����ѡ�⣬����- 1����,�������������\n";
			string x;
			getline(cin, x);
			if (x != "-1")
				return;
			getline(cin, x);
			report_data[i].content = x;
			report_data[i].status = "1";
			file.set_report_data(report_data);
			report_data[i].status = "1";
			cout << "�ύ�ɹ���\n";
			system("pause");
			return;
		}
		if (report_data[i].status == "4")
		{
			cout << "����ѡ�ⱻ��ʦɾ��������Ϊ��\n" << problem_data[search_problem(report_data[i].problem_mun)].delete_reason
				<<endl<<"������ѡ��\n";
			system("pause");
		}
	}
}

void Question_student::DELETE(int i)
{
	problem_data[search_problem(report_data[i].problem_mun)].current_num//ѡ��������1
	= to_string(stoi(problem_data[search_problem(report_data[i].problem_mun)].current_num)-1);
	report_data[i].status = '5';
	file.set_problem_data(problem_data);
	file.set_report_data(report_data);
}


void Question_student::display_problem() const
{
	system("cls");
	cout << "��ǰ������ѡ���ѡ��\n" << "���	" << "������ʦ����	"  << "˵��		" << "���ѡ������ " << "��ǰѡ������\n";
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
	cout << "��������ţ�";
	getline(cin, temp.problem_mun);
	cout << "��������Ŀ˵��";
	getline(cin, temp.instruction);
	cout << "���������ѡ������";
	getline(cin, temp.max_num);
	temp.current_num = "0";
	temp.delete_reason = "";
	temp.status = "1";
	problem_data.push_back(temp);
	file.set_problem_data(problem_data);
	cout << "��Ŀ�����ɹ���";
}


void Question_teacher::review_problem()
{
	cout << "��ǰ�����´����ѡ�⣺\n" << "��� ѧ��ѧ�� 	��Ŀ˵��	��ǰѡ������	";
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
		cout << "��ѡ��Ҫ���������(ֱ������-1�˳�)��";
		cin >> x;
		if (x == "-1")
			return;
		if (report_data[search_report(x)].status == "-1")
			break;
		cout << "������Ч������";
	}
	system("cls");
	while (1)
	{
		int temp;
		cout << "����ǰѡ��" << x << "�⣬������������еĲ�����\n" << "1.ͬ��ѡ�� \n" << "2.��ͬ��ѡ��"
			<< "3.�˳�";
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
	cout << "��ǰ�����´���˱��棺\n" << "��� ѧ��ѧ�� 	��Ŀ˵��	��ǰѡ������	";
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
		cout << "��ѡ��Ҫ���������(ֱ������-1�˳�)��";
		cin >> x;
		if (x == "-1")
			return;
		if (report_data[search_report(x)].status == "1")
			break;
		cout << "������Ч������";
	}
	system("cls");
	while (1)
	{
		int temp;
		cout << "����ǰѡ��" << x << "�⣬������������еĲ�����\n" << "1.ͨ������ \n" << "2.��ͨ������"
			<< "3.�˳�";
		cin >> temp;
		switch (temp)
		{
		case 1:report_data[search_report(x)].status = "2"; file.set_report_data(report_data); return;
		case 2:report_data[search_report(x)].status = "3"; file.set_report_data(report_data); return;
		case 3: return;
		}
	}
}
