/* Run ./main in terminal to execute the program. */
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstring>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "student.h"

student* readStudentFile(int &size)
{
	ifstream fin("student.txt");

	string str;
	getline(fin, str);
	int s = stoi(str);
	student* arr = new student[s];
	int count = 0;

	while (getline(fin, str))
	{
		if (str != "")
		{
			istringstream iss(str);
			int c = 0;
			for (string s; iss >> s; ++c)
			{
				switch(c)
				{
					case 0:
						arr[count].setRollNo(s);
						break;
					case 1:
						arr[count].setMarks(stoi(s));
						break;
					case 2:
						arr[count].setGrade(s[0]);
						break;
				}
			}
			++count;
		}
	}
	fin.close();
	size = s;
	return arr;
}

void assignGrades(student* arr, int size)
{
	for (int i = 0; i < size; ++i)
	{
		if (arr[i].getMarks() >= 80) arr[i].setGrade('A');
		else if (arr[i].getMarks() >= 70) arr[i].setGrade('B');
		else if (arr[i].getMarks() >= 60) arr[i].setGrade('C');
		else if (arr[i].getMarks() >= 50) arr[i].setGrade('D');
		else arr[i].setGrade('F');	
	}
}

void createResultPath()
{
	ifstream fin("ResultPath.txt");
	for (string str; getline(fin, str);)
	{
		if (str != "")
		{
			istringstream iss(str);
			int c = 0;
			char *arg1, *arg2;
			for (string s; iss >> s; ++c)
			{
				if (c==0)
				{
					arg1 = new char[s.length()+1];
					strcpy(arg1, s.c_str());
				}
				else
				{
					arg2 = new char[s.length()+1];
					strcpy(arg2, s.c_str());	
				}
			}

			pid_t pid = fork();
			if (pid == 0)
			{
				wait(NULL);
				usleep(100000);
			}

			else if (pid != -1)
			{
				execlp(arg1, arg1, arg2, NULL);
			}

			else cout << "Unable to fork process.";
		}
	}
}

void writeStudentFile(student *arr, int size)
{
	ofstream fout("./os/sectionA/LabResult.txt");
	string str;
	for (int i = 0; i < size; ++i)
	{
		string gradeStr(1, arr[i].getGrade());
		str = arr[i].getRollNo() + " " + to_string(arr[i].getMarks()) + " " + gradeStr + "\n";
		fout << str;
	}
	fout.close();
}

int main()
{
	int size;
	student* arr = readStudentFile(size);
	assignGrades(arr, size);
	createResultPath();
	writeStudentFile(arr, size);
	delete[] arr;
	return 0;
}