#pragma once
#pragma warning(disable:4996)

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#ifndef Problem_H
#define Problem_H
#define random(x) (rand() % x)

void GetProblem(int [][4],);
void WrongOrCorrect(int);
void GetGrade(int [][4],  int* grade);
void End(int*);
#endif
