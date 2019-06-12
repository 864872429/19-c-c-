#include "Fileoperation.h"
using namespace std;

#ifndef _LOGIN_H
#define _LOGIN_H

class Login
{
public:
	Login();
	
private:
	
	Fileoperation file;
	vector<User> student_data;
	vector<Admin> teacher_data;
};





#endif
#endif
