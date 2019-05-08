/****************************************************

Copyright (c) <2019> <copyright holders:lumanke>

"Anti 996" License Version 1.0
https://github.com/996icu/996.ICU/blob/master/LICENSE"

@Version:4.0(c)
@Author:lumanke
@LastEditors: lumanke
@Description:Midterm work
@Date: 2019-03-01 20:44:11
@LastEditTime: 2019-05-08 19:08:11
4
****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RANDOM(x) (rand() % x)

struct Problem *GetProblem(struct Problem *);
void GetGrade(struct Problem *);
void File(struct Problem *, int);
void End(struct Problem *);

struct Problem
{
    int problem[10][2];
    int grade;
    FILE *fp;
};

int main()
{
    struct Problem student;
    srand((int)time(NULL));
    while (1)
    {
        student.grade = 0;
        system("cls");
        File(&student, 1);
        GetGrade(GetProblem(&student));
        End(&student);
    }
}

struct Problem *GetProblem(struct Problem *p)
{
    int i = 0;
    while (i < 10)
    {
        p->problem[i][0] = rand() % 50 + 1;
        p->problem[i][1] = rand() % 101 - 50;
        if ((p->problem[i][0] + p->problem[i][1] > 50) || (p->problem[i][0] + p->problem[i][1] < 0))
            continue;
        i++;
    }
    return p;
}

void GetGrade(struct Problem *p)
{
    int i, j, answer;
    void WrongOrCorrect(int);
    void NotebookOfWrong(int a, int b, struct Problem *p);
    for (i = 0; i < 10; i++)
    {
        printf("\n-----------------------------------------------------------------------------\nYou grade is %d now\nproblem %d :   \n", p->grade, i + 1);
        for (j = 0; j < 3; j++)
        {
            fflush(stdin);
            printf("%d%+d=", p->problem[i][0], p->problem[i][1]);
            scanf("%d", &answer);
            if (answer == p->problem[i][0] + p->problem[i][1])
            {
                WrongOrCorrect(0);
                p->grade += (20 + j * j - 7 * j) / 2;
                break;
            }
            else if (j == 2)
            {
                if (p->fp)
                    NotebookOfWrong(p->problem[i][0], p->problem[i][1], p);
                printf("?????:\n%d%+d=%d\n", p->problem[i][0], p->problem[i][1], p->problem[i][0] + p->problem[i][1]);
            }
            WrongOrCorrect(1);
        }
    }
}

void End(struct Problem *p)
{
    char i;
    printf("-----------------------------------------------------------------------------\n-----------------------------------------------------------------------------\nyou grade is %d\n", p->grade);
    switch (p->grade / 10)
    {
    case 10:
    case 9:
        printf("SMART\n");
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
    printf("would you like try again(y/n)\n");
    fflush(stdin);
    i = getchar();
    if (i == 'N' | 'n')
    {
        File(p, 0);
        exit(0);
    }
}

void WrongOrCorrect(int i)
{
    char *put[8] = {"Very good!", "xcellent!", "Nice work!", "Keep up the good work!", "Wrong.Try once more.",
                    "No.Don't give up!", "Not correct.Keep trying.", "No.Please try again."};
    puts(*(put + RANDOM(4) + i * 4));
}

void File(struct Problem *p, int x)
{
    if (x)
    {
        p->fp = fopen("???.txt", "a");
        if (p->fp)
        {
            printf("????????(???????\"???.txt\"\n");
            fprintf(p->fp, "???????\n");
        }
        else
        {
            printf("???????\n,???????\n");
        }
    }
    else
    {
        fclose(p->fp);
    }
}

void NotebookOfWrong(int a, int b, struct Problem *p)
{
    printf("????????\n");
    fprintf(p->fp, "%d%+d=%d\n", a, b, a + b);
}
