/***************************************************
Copyright (c) <year> <copyright holders>
"Anti 996" License Version 1.0 (Draft)
Permission is hereby granted to any individual or legal entity
obtaining a copy of this licensed work (including the source code,
documentation and/or related items, hereinafter collectively referred
to as the "licensed work"), free of charge, to deal with the licensed
work for any purpose, including without limitation, the rights to use,
reproduce, modify, prepare derivative works of, distribute, publish
and sublicense the licensed work, subject to the following conditions:
1. The individual or the legal entity must conspicuously display,
without modification, this License and the notice on each redistributed
or derivative copy of the Licensed Work.
2. The individual or the legal entity must strictly comply with all
applicable laws, regulations, rules and standards of the jurisdiction
relating to labor and employment where the individual is physically
located or where the individual was born or naturalized; or where the
legal entity is registered or is operating (whichever is stricter). In
case that the jurisdiction has no such laws, regulations, rules and
standards or its laws, regulations, rules and standards are
unenforceable, the individual or the legal entity are required to
comply with Core International Labor Standards.
3. The individual or the legal entity shall not induce, suggest or force
its employee(s), whether full-time or part-time, or its independent
contractor(s), in any methods, to agree in oral or written form, to
directly or indirectly restrict, weaken or relinquish his or her
rights or remedies under such laws, regulations, rules and standards
relating to labor and employment as mentioned above, no matter whether
such written or oral agreements are enforceable under the laws of the
said jurisdiction, nor shall such individual or the legal entity
limit, in any methods, the rights of its employee(s) or independent
contractor(s) from reporting or complaining to the copyright holder or
relevant authorities monitoring the compliance of the license about
its violation(s) of the said license.
THE LICENSED WORK IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE COPYRIGHT HOLDER BE LIABLE FOR ANY CLAIM,
DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
OTHERWISE, ARISING FROM, OUT OF OR IN ANY WAY CONNECTION WITH THE
LICENSED WORK OR THE USE OR OTHER DEALINGS IN THE LICENSED WORK.
author:lumanke
version:3.1
date:2019/03/09
latsUpdate:2019/04/15
****************************************************/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define random(x) (rand() % x)
//#define scanf scanf_s//»Ù±®¥Ì«Î◊¢ Õ

void GetProblem(int[][4]);
void WrongOrCorrect(int);
void GetGrade(int[][4], int* grade);
void End(int*);

int main()
{
	int Problem[10][4], grade = 0;
	srand((int)time(NULL));
	while (1)
	{
		system("cls");
		GetProblem(Problem);
		GetGrade(Problem, &grade);
		End(&grade);
	}
}
void GetProblem(int Problem[10][4])
{
	int i=0;
	while(i<10)
	{
		Problem[i][0] = random(50);
		Problem[i][1] = random(2); 
		Problem[i][2] = random(50);
		switch (Problem[i][1])
		{
		case 0:
			Problem[i][1] = '+';
			if (Problem[i][0] + Problem[i][2] > 50)
			{
				continue;
			}
			Problem[i][3] = Problem[i][0] + Problem[i][2];
			break;
		case 1:
			Problem[i][1] = '-';
			if (Problem[i][0] - Problem[i][2] < 0)
			{
				continue;
			}
			Problem[i][3] = Problem[i][0] - Problem[i][2];
		}
		i++;
	}	
}

void GetGrade(int Problem[10][4], int* grade)
{
	int i, j, answer;
	for (i = 0; i < 10; i++)
	{
		printf("\n-----------------------------------------------------------------------------\nProblem %d :   \n",i + 1);
		for (j = 0; j < 3; j++)
		{
			printf("%d%c%d=", Problem[i][0], Problem[i][1], Problem[i][2]);
			scanf("%d", &answer);
			if (answer == Problem[i][3])
			{
				WrongOrCorrect(0);
				*grade += (20 + j * j - 7 * j) / 2;
				break;
			}
			else if (j == 2) 
				printf("%d%c%d=%d\n", Problem[i][0], Problem[i][1], Problem[i][2], Problem[i][3]);
			WrongOrCorrect(1);
		}
	}
}

void WrongOrCorrect(int i)
{
	char put[8][40] = { "Very good!","xcellent!","Nice work!","Keep up the good work!","Wrong.Try once more.","No.Don\'t give up!","Not correct.Keep trying.","No.Please try again." };
	puts(*(put + random(4) + i * 4));	
}

void End(int* grade)
{
	printf("-----------------------------------------------------------------------------\n-----------------------------------------------------------------------------\nyou grade is %d\n",*grade);
	switch (*grade / 10)
	{
	case 10:
	case 9: printf("SMART\n"); break;
	case 8: printf("GOOD\n"); break;
	case 7: printf("OK\n"); break;
	case 6: printf("PASS\n"); break;
	default: printf("TRY AGAIN\n");
	}
	*grade = 0;
	printf("would you like try again(y/n)\n");
	if (getchar() == 'N' || getchar() == 'n')
	{
		exit(0);
	}
}
