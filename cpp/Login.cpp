#include "±êÍ·.h"
#include <conio.h>
Login::Login()
{
	student_data = file.get_student_data();
	teacher_data = file.get_teacher_data();
	string input_name;
	string input_password;
	while (1)
	{
begin:
		cout << "ÇëÊäÈëÕËºÅ:" ;
		cin >> input_name;
		for (int i = 0; i < student_data.size(); i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (input_name == student_data[i].student_num)
				{
					cout << "ÇëÊäÈëÃÜÂë:" ;
					while (1)
					{
						int i = 0;
						char ch;
						ch = _getch();
						if (ch != '\n' && ch != '\r')
						{
							putchar('*');
							input_password.push_back(ch);
						}
						else
						{
							putchar('\n');
							break;
						}
					}
					if (input_password == student_data[i].password)
					{
						cout << student_data[i].name << "Welcome to student page !\n" << endl;
						goto begin;
					}
					cout << "Password is wrong! Try again!\n";
				}
			}
		}
		for (int i = 0; i < teacher_data.size(); i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (input_name == teacher_data[i].teacher_num)
				{
					cout << "ÇëÊäÈëÃÜÂë:";
					while (1)
					{
						int i = 0;
						char ch;
						ch = _getch();
						if (ch != '\n' && ch != '\r')
						{
							putchar('*');
							input_password.push_back(ch);
						}
						else
						{
							putchar('\n');
							break;
						}
					}
					if (input_password == teacher_data[i].password)
					{
						cout << teacher_data[i].name << "Welcome to teacher page !\n" << endl;
						goto begin;
					}
					cout << "Password is wrong! Try again !\n";
				}
			}
		}
		cout << "Userinfo is wrong! \n";
		cout << "Please choose:\n 1.LeadingAgain \n 2.DropOut \n";
		int x;
		cin >> x;
		if (x == 2)
		{
			exit(0);
		}
	}
}

