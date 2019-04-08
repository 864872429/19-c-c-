#include "Problem.h"

void getProblem(int Problem[10][4])
{
	int add, minus, a, i;
	for (a = 0; a < 10; a++)
	{
		i = 1;
		while (i)
		{
			Problem[a][0] = random(50);
			Problem[a][1] = random(2);
			Problem[a][2] = random(50);
			add = Problem[a][0] + Problem[a][2];
			minus = Problem[a][0] - Problem[a][2];
			switch (Problem[a][1])
			{
			case 0:
				Problem[a][1] = '+';
				if (add < 50)
				{
					Problem[a][3] = add;
					i = 0;  
				}
				break;
			case 1:
				Problem[a][1] = '-';
				if (minus > 0)
				{
					Problem[a][3] = minus;
					i = 0; 
				}
				break;
			default:
				break;
			}
		}
	}
}

void getgrade(int Problem[10][4], int* grade)
{
	int i, j, answer;
	for (j = 0; j < 10; j++)
	{
		for (i = 0; i < 3; i++)
		{
			printf("%d%c%d=", Problem[j][0], Problem[j][1], Problem[j][2]);
			scanf("%d", &answer);
			if (answer == Problem[j][3])
			{
				WrongOrCorrect(0);
				break;
			}
			else
			{				
				WrongOrCorrect(1);
			}
		}
		switch (i)
		{
		case 0:*grade += 3;
		case 1:*grade += 2;
		case 2:*grade += 5;
		}	
	}
}


void WrongOrCorrect(int i)/*此处有魔法,不要瞎动*/
{
	char put[8][40] = { "Very good!","xcellent!","Nice work!","Keep up the good work!","Wrong.Try once more.","No.Don\'t give up!","Not correct.Keep trying.","No.Please try again." };
	puts(*(put + random(4) + i * 4));
}

void End(int* grade)
{
	printf("you grade is %d\n", *grade);
	*grade = *grade / 10;
	switch (*grade)
	{
	case 10:
	case 9:printf("SMART\n");
		break;
	case 8:
		printf("GOOD\n");
		break;
	case 7:
		printf("OK\n");
		break;
	case 6:
		printf("PASS\n");
		break;
	default:
		printf("TRY AGAIN\n");
	}
	*grade = 0;
	printf("would you like try again(y/n)\n");
	fflush(stdin); 
	if (getchar() == 'N' || getchar() == 'n')
	{
		exit(0);
	}
	
}

/////////////////////////////////////////////////////////////////
//致终于来到这里的勇敢的人:你是被上帝选中的人                  //
//英勇的,不辞劳苦的,不眠不休的来修改我们这最棘手代码的编程骑士 //
//你,我们的救世主,人中之龙,我要对你说                          //
//永远不要放弃,永远不要对自己失望,永远不要逃走                 //
//永远不要哭啼,永远不要说再见,永远不要用谎言来伤害自己         //
/////////////////////////////////////////////////////////////////