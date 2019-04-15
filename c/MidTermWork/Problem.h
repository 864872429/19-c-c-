#pragma once
#pragma warning(disable:4996)

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#ifndef Problem_H
#define Problem_H
#define random(x) (rand() % x)

void getProblem(int [][4],);
void WrongOrCorrect(int);
void getgrade(int [][4],  int* grade);
void End(int*);
#endif
