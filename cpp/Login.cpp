#include "±êÍ·.h"
#include <conio.h>
Login::Login()
{
	student_data = file.get_student_data();
	teacher_data = file.get_teacher_data();
	while (1)
	{
		string input_name;
		string input_password;
		cout << "****************************" << endl;
		cout << "**      ÇëÊäÈëÕËºÅ:       **" << endl;
		cin >> input_name;
		for (int i = 0; i < student_data.size(); i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (input_name == student_data[i].stu_num)
				{
					cout << "**                        **" << endl;
					cout << "**      ÇëÊäÈëÃÜÂë:       **" << endl;
					cout << "****************************" << endl;
					while (1)
					{
						int i = 0;
						char ch;
						ch = _getch();
						if (ch != '\n' && ch != '\r')
						{
							putchar('*');
							input_password[i++] = ch;
						}
						else
							break;
					}
					//password = student_data[i].password;
					cin >> input_password;
					if (input_password == student_data[i].password)
					{
						cout << student_data[i].name << "Welcome to student page !" << endl;
						continue;
					}
					cout << "Password is wrong! Try again!";
				}
			}
		}
		for (int i = 0; i < teacher_data.size(); i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (input_name == teacher_data[i].tea_num)
				{
					cout << "**                        **" << endl;
					cout << "**      ÇëÊäÈëÃÜÂë:       **" << endl;
					cout << "****************************" << endl;
					while (1)
					{
						int i = 0;
						char ch;
						ch = _getch();
						if (ch != '\n' && ch != '\r')
						{
							putchar('*');
							input_password[i++] = ch;
						}
						else
							break;
					}
					//password = teacher_data[i].password;
					cin >> input_password;
					if (input_password == teacher_data[i].password)
					{
						cout << teacher_data[i].name << "Welcome to teacher page !" << endl;
						continue;
					}
					cout << "Password is wrong! Try again !";
				}
			}
			cout << "Userinfo is wrong! \n";
			cout << "Please choose 1.LeadingAgain or 2.DropOut ";
			int x;
			cin >> x;
			if (x == 2)
			{
				exit(0);
			}
		}
	}
}

