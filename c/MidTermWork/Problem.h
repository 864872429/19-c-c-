#pragma once
#pragma warning(disable:4996)

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#ifndef Problem_H
#define Problem_H
#define random(x) (rand() % x)

void correct();
void wrong();
void getgrade(int Problem[10][4], int*);
void getProblem(int Problem[10][4]);
void end(int*);
int count(int);

#endif
