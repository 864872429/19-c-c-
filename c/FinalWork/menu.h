//Author��linhao
//data:2019/05/26

#ifndef _MENU_H
#define _MENU_H
#include<stdio.h>
#include<stdlib.h>
void menu()
{
	int i = 0,j = 0;
	printf("* * * * * * * * * * * * * ����ϵͳ* * * * * * * * * * * \n");/*60ge*/
	printf("*              1....                                   *\n");
	printf("*              2....                                   *\n");
	printf("*              3....                                   *\n");
	printf("*              4....                                   *\n");
	printf("*              5....                                   *\n");
	printf("*              6....                                   *\n");
	printf("*              7....                                   *\n");
	printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * \n��������ѡ��1-7��: ");
	scanf("%d",&j);
	while(j>7||j<1)
	{
		printf("  ���ڷ�Χ�����������롾1-7��:");	
		scanf("%d",&j);
	}
	switch(j)
	{
		case 1:
			;
		case 2:
			;
		case 3:
			;
		case 4:
			;
		case 5:
			;
		case 6:
			;
		case 7:
			;
	}	
}

#endif