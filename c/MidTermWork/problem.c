#include "Problem.h"

void GetProblem(int Problem[10][4])
{
	int i = 0;
	while (i < 10)
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
		printf("\n-----------------------------------------------------------------------------\nProblem %d :   \n", i + 1);
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
	printf("-----------------------------------------------------------------------------\n-----------------------------------------------------------------------------\nyou grade is %d\n", *grade);
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
