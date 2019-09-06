#include <string>
using namespace std;
class student
{
private:
	string rollno;
	int marks;
	char grade;
public:
	string getRollNo();
	int getMarks();
	char getGrade();
	void setRollNo(string r);
	void setMarks(int m);
	void setGrade(char g);
	student(string r, int m, char g);
	student();
};