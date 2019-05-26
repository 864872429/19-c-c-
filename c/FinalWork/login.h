//Author：liqiyang
//data:2019/05/26
//LastEditTime: 2019/05/26

#ifndef _LOGIN_H
#define _LOGIN_H

#include<stdio.h>
#include<string.h>
#include<conio.h>

int login()
{
	int i, j = 0;
	char user[] = "zhang";
	char pass[] = "abc123";//因为以后要从文件中读取用户名和密码，所以先用变量存储
	char username[100];
	char password[100];
	printf("please input username and password.\n");
	for (i = 1; i <= 3;)
	{
		printf("username:");
		gets(username);		
		printf("password:");
		while (j < 98)
		{
			fflush(stdin);
			password[j] = getch();
			if (password[j] == '\n'|| password[j] == '\r')
			{
				password[j] = '\0';
				break;
			}
			printf("*");
			j++;
		}
		if (strcmp(username, user) == 0
			&& strcmp(password, pass) == 0)
		{
			printf("\nwelcome %s\n", username);
			printf("密码正常，调用菜单函数");//日后这里放菜单函数的调用
			break;
		}
		else
		{
			printf("\nsorry,wrong number,please try again\n");
			i++;
		}	
	}
	exit(0);
}
#endif //_LOGIN_H