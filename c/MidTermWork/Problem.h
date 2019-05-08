#pragma once
#pragma warning(disable : 4996)

#ifndef Problem_H
#define Problem_H
#define random(x) (rand() % x)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define RANDOM(x) (rand() % x)

struct Problem
{
    int problem[10][2];
    int grade;
    FILE *fp;
};


struct Problem *GetProblem(struct Problem *p);
void GetGrade(struct Problem *p);
void End(struct Problem *p);
void WrongOrCorrect(int i);
void File(struct Problem *p, int x);
void NotebookOfWrong(int a, int b, struct Problem *p);
#endif
