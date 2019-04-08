/***************************************************
author:manke
version:3.1
date:2019/03/09
latsUpdate:2019/04/08
****************************************************/

#include "Problem.h"

int main()
{
	int Problem[10][4], i = 1, grade = 0;
	srand(time(NULL));
	while (1)
	{
		system("cls");
		getProblem(Problem);
		getgrade(Problem, &grade);
		end(&grade);
	}
	system("PAUSE");
}
