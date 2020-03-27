
#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <iostream>
#include "GradeType.hpp"


using namespace std;

class Student
{
public:
    Student();
	Student(string nameS);
	float getGrade(int type, string aName);
	~Student();
	string getName();
	int getAge();
	void gradeAdd(string gradeName, float pointsPossible, float pointsEarned, int type);
	void gradeRemove(string nameG, int type);
	void gradeChange(string nameG, float pointsPossible, float pointsEarned, int type);
	void printSingleGrade(string gName, int type);
	void printAllGrades(); 
	float calcAverage();
	float calcAverageType(int type);
	string getGradeList(int type);
	int getNumGradesType(int type);
	string getTypeName(int type);
	float typePointsPossible(int type);
	float typePointsEarned(int type);
	Grade* getTypeHead(int i);

	Student * next;

private:
	string nameStudent;
	int age;
	float grade;
	int categories = 5;
	GradeType * gradeArray[5];


};

#endif
