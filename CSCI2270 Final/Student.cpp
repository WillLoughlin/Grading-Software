#include "Student.hpp"

Student::Student(){
    //gradeArray = new GradeType [categories];
    nameStudent = "";

    grade = 0.0;
    gradeArray[0] = new GradeType("Homework");
    gradeArray[1] = new GradeType("Quizzes");
    gradeArray[2] = new GradeType("Tests");
    gradeArray[3] = new GradeType("Projects");
    gradeArray[4] = new GradeType("Attendance");
    next = NULL;
}

Student::Student(string nameS){
    //gradeArray = new GradeType [categories];
    nameStudent = nameS;

    gradeArray[0] = new GradeType("Homework");
    gradeArray[1] = new GradeType("Quizzes");
    gradeArray[2] = new GradeType("Tests");
    gradeArray[3] = new GradeType("Projects");
    gradeArray[4] = new GradeType("Attendance");
    next = NULL;
}

Student::~Student(){
    //delete [] gradeArray;
}

float Student::getGrade(int type, string aName)
{
   return gradeArray[type]->getSingleGrade(aName);
}
void Student::gradeAdd(string gradeName, float pointsP, float pointsE, int type){
    gradeArray[type]->addGrade(gradeName, pointsP, pointsE);
}

string Student::getName(){
    return nameStudent;
}

void Student::gradeRemove(string nameG, int type){
    gradeArray[type]->removeGrade(nameG);
}

void Student::gradeChange(string nameG, float pointsPossible, float pointsEarned, int type){
    Grade * temp = gradeArray[type]->head;
    while(temp->gradeName!=nameG)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        cout << "Grade not found." << endl;
    }
    else
    {
        temp->pointsEarned = pointsEarned;
        temp->pointsPossible = pointsPossible;
    }

}

float Student::calcAverage(){
    cout << "Homework Average: " << gradeArray[0]->calcAverage()*100 << "%" << endl;
}


float Student::calcAverageType(int type){
    return gradeArray[type]->calcAverage();
}

Grade* Student::getTypeHead(int i)
{
    return gradeArray[i]->head;
}
void Student::printSingleGrade(string gName, int type){
    gradeArray[type]->printSingleGradeSecond(gName);
}

string Student::getGradeList(int type){
    return gradeArray[type]->getStringListGradeToSave();
}

int Student::getNumGradesType(int type){
    return gradeArray[type]->getNumGrades();
}

string Student::getTypeName(int type){
    return gradeArray[type]->getNameType();
}

float Student::typePointsPossible(int type){
    float pp = gradeArray[type]->totalPP();
    return pp;
}
float Student::typePointsEarned(int type){
    float pe = gradeArray[type]->totalPE();
    return pe;
}
void Student::printAllGrades(){
    for(int i=0; i<5 ; i++){
        gradeArray[i]->printListGrades();
    }
}
