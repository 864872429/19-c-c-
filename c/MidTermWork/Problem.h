#pragma once
#pragma warning(disable:4996)

#ifndef Problem_H
#define Problem_H
#define random(x) (rand() % x)
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void correct();
void wrong();
void getgrade(int Problem[10][4], int*);
void getProblem(int Problem[10][4]);
void end(int*);
int count(int);

#endif