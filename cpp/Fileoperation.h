#include "tesk.h"

#ifndef FILEOPERATION_H
#define FILEOPERATION_H

struct User                   //因为Student被作为类名了，就叫User吧。
{
    QString student_num;      //学号
    QString name;             //姓名
    QString password;         //密码
    QString CLASS;            //班级，class是关键字，所以大写
    QString phone;            //电话
    QString topic;            //选题号 -1表示未选题 0表示待审核
    QString n;                //若被删除，该值为0
    QString score;
    //其他数据待补充
};

struct ADMIN                  //因为Teacher被作为类名了，就叫ADMIN吧。
{
    QString teacher_num;      //工号
    QString name;             //姓名
    QString password;         //密码
    QString phone;            //电话
    QString n;                //若被删除，该值为0
    //其他数据待补充
};

struct Report                //选题报告
{
    QString problem_mun;      //题号
    QString student_num;      //选题学生学号
    QString status;           //状态(-2-选题未通过 -1-待审核 0-未提交 1-已提交 2-结束 4-被老师删除 5-被删除或未提交)
    QString content;          //报告内容
    //其他数据待补充
};

struct Problem                     //题目
{
    QString problem_num;           //题号
    QString instruction;           //说明
    QString max_num;               //最大选题人数
    QString current_num;           //当前选题人数
    QString status;                //若被删除，该值为0或-1，-1表示有删除理由
    QString delete_reason;         //删除理由
    //其他数据待补充
};

class Fileoperation
{
public:

    static Fileoperation& getFile();

    QVector<User>& get_student_data();
    QVector<ADMIN>& get_teacher_data();
    QVector<Report>& get_report_data();
    QVector<Problem>& get_problem_data();
    User& get_student_data(const QString&);

    void set_student_data(const User&);
    void set_student_data(const QVector<User>&);
    void set_teacher_data(const QVector<ADMIN>&);
    void set_report_data(const QVector<Report>&);
    void set_problem_data(const QVector<Problem>&);

    void fileWrite(int);//输入0-15;1-学生，2-老师，4-报告，8-选题。
    void fileRead(int); //输入0-15;1-学生，2-老师，4-报告，8-选题。

private:

    Fileoperation(int = 15);

    QVector<User> student_data;
    QVector<ADMIN> teacher_data;
    QVector<Report> report_data;
    QVector<Problem> problem_data;
};

#endif // FILEOPERATION_H
