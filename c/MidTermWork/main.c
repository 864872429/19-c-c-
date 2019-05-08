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

#include "Problem.h"

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

