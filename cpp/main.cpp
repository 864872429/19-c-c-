#include "Fileoperation.h"

void display(vector< Student > , vector< Teacher > );//����һ�����Ժ��������������Ƿ���ȷ��ȡ

int main()
{
	Fileoperation test;   //�ڹ��캯��ʱ����ļ��ж�ȡ���ݴ���ṹ������
	vector<Student> student_data= test.getstudent_data();//ʹ��getstudent_data��getteacher_data������ȡ�����ļ����ݵĽṹ������
	vector<Teacher> teacher_data= test.getteacher_data();
	display( student_data,teacher_data );
	//test.setstudent_data(student_data);//����setstudent_data���������ĵ�����д���ļ�����ʱ��ûд��
	//test.setteacher_data(teacher_data);
	return 0;
}

void display(vector< Student> student_data, vector< Teacher > teacher_data)//����һ�����Ժ��������������Ƿ���ȷ��ȡ
{
	system("cls");

	cout << "�����ǽ�ʦ��Ϣ:\n";
	cout << "����	" << "����	" << "�绰\n";
	for (int i = 0; i < teacher_data.size(); i++)
		if (teacher_data[i].n)//n=0��ζ�Ÿ��ɾ��
			cout << teacher_data[i].tea_num << "	" << teacher_data[i].name << "	" << teacher_data[i].phone << endl;

	cout << "������ѧ����Ϣ:\n";
	cout << "����	" << "����	" << "�绰	" << "	ѡ��\n";
	for (int i = 0; i < student_data.size(); i++)
		if (student_data[i].n)//n=0��ζ�Ÿ��ɾ��
		{
			cout << student_data[i].stu_num << "	" << student_data[i].name << "	" << student_data[i].phone;
			for (int j = 0; j < student_data[i].topic_size; j++)
				cout << "	" << student_data[i].topic[j];
			cout << endl;
		}

}