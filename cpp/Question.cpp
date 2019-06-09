#include "Question.h"

Question::Question(string x)
{
	user = x;
	report_data = file.get_report_data();
	problem_data = file.get_problem_data();
}

int Question::search_problem(const string& x) const
{
	for (int i = 0; i < problem_data.size(); i++)
		if (problem_data[i].problem_mun == x)
			return i;
	return -1;
}

int Question::search_report()
{
	for (int i = 0; i < report_data.size(); i++)
		if (report_data[i].problem_mun == user&& report_data[i].status!="-5")
			return i;
	return -1;
}

void Question::create_problem()
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
}

void Question::submit_problem()
{
	int i = search_report();
	if ( i != -1)
	{
		if (report_data[i].status == "2")
		{
			cout << "����ǰ����ѡ�⣬�ұ�����ͨ��";
			system("pause");
			return;
		}
		else if (report_data[i].status == "4")
		{
			cout << "����ǰѡ�ⱻ��ʦɾ��������ѡ\n";
			DELETE(i);
			system("pause");
		}
		else if (report_data[i].status == "-2")
		{
			cout << "����ǰѡ��δͨ��������ѡ\n";
			DELETE(i);
			system("pause");
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
			if (ch != 'y' || ch != 'Y')
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
			cout << "ѡ��ɹ����ȴ���ʦ���\n";
			system("pause");
			return;
		}
	}
}

void Question::submit_report()
{
	int i = search_report();
	if (i == -1)
	{
		cout << "����ǰû��ѡ��\n";
		system("pause");
		return;
	}
	else
	{
		cout << "��������Ŀǰ��ѡ�⣺\n";
		cout << "��ţ�" << report_data[i].problem_mun << endl;
		cout << "���ݣ�" << report_data[i].content << endl;
		if (report_data[i].status == "-2")
		{
			cout << "��ѡ������δͨ����ˣ�������ѡ��";
			system("pause");
			return;
		}
		else if (report_data[i].status == "-1")
		{
			cout << "��ѡ���������������";
			system("pause");
			return;
		}
		if (report_data[i].status == "0")
		{
			cout << "ѡ��������ͨ���������뱨�棨����һ�������룬�س�������ֱ������-1ȡ����";
			string x;
			getline(cin, x);
			if (x == "-1")
				return;
			report_data[i].content = x;
			cout << "�ύ�ɹ���";
			return;
		}
		if(report_data[i].status == "1")
		{
			cout << "ѡ�ⱨ�����������,��������Ϊ:\n";
			cout << report_data[i].content << "\n����- 1����,�������������";
			string x;
			getline(cin, x);
			if (x == "-1")
				return;
			getline(cin, x);
			report_data[i].content = x;
			cout << "�ύ�ɹ���";
			system("pause");
		}
		if (report_data[i].status == "2")
			cout << "ѡ�ⱨ������Ϊ:\n" << report_data[i].content<<"ѡ�ⱨ����ͨ����\n";
		if (report_data[i].status == "3")
		{
			cout << "ѡ�ⱨ��δͨ�������������뱨�棨����һ�������룬�س�������ֱ������-1ȡ����";
			string x;
			getline(cin, x);
			if (x == "-1")
				return;
			report_data[i].content = x;
			cout << "�ύ�ɹ���";
			return;
		}
		if (report_data[i].status == "4")
		{
			cout << "����ѡ�ⱻ��ʦɾ��������Ϊ��\n" << problem_data[search_problem(report_data[i].problem_mun)].delete_reason<<
				"������ѡ��";
		}
	}
}

void Question::DELETE(int i)
{
	problem_data[search_problem(report_data[i].problem_mun)].current_num//ѡ��������1
	= to_string(stoi(problem_data[search_problem(report_data[i].problem_mun)].current_num)-1);
	report_data[i].status = '5';
}


void Question::display_problem()
{
	system("cls");
	cout << "��ǰ������ѡ���ѡ��\n"<< "������ʦ����	" << "���	" << "˵��		" << "���ѡ������ " << "��ǰѡ������ " << "ɾ������\n";
	for (int i = 0; i < problem_data.size(); i++)
		if (problem_data[i].status != "0"&& problem_data[i].status != "-1"&& problem_data[i].max_num>problem_data[i].current_num)
			cout << problem_data[i].teacher_num << "		" << problem_data[i].problem_mun << "	" << problem_data[i].instruction << "	" << problem_data[i].max_num << "	     " << problem_data[i].current_num;
}




