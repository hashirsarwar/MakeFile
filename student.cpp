#include "student.h"
string student::getRollNo()
{
	return rollno;
}
int student::getMarks()
{
	return marks;
}
char student::getGrade()
{
	return grade;
}
void student::setRollNo(string r)
{
	rollno = r;
}	
void student::setMarks(int m)
{
	marks = m;
}	
void student::setGrade(char g)
{
	grade = g;
}
student::student(string r, int m, char g)
{
	rollno = r;
	marks = m;
	grade = g;
}
student::student() {}