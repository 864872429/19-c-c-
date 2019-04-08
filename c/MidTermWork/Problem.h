#pragma once
#ifndef Problem_H
#define Problem_H

#define random(x) (rand() % x)

void correct();
void wrong();
void getgrade(int Problem[10][4], int*);
void getProblem(int Problem[10][4]);
int end(int*);
int count(int);

#endif