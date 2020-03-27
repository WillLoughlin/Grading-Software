#ifndef GRADETYPE_HPP
#define GRADETYPE_HPP

#include <iostream>


using namespace std;

struct Grade//grade struct used in doubly linked list of grades
    {
        string gradeName;//teacher assigns name of assignment
        float pointsPossible;
        float pointsEarned;
        Grade * next;
    };

class GradeType
{
private:

    string nameType;
    int numGrades;

    


public:

    GradeType();

    GradeType(string nType);

    ~GradeType();

    void addGrade(string aName, float ptsP, float ptsE);

    void removeGrade(string aName);

    string getNameType();

    int getNumGrades();

    void printList();

    float calcAverage();
    
    void printSingleGradeSecond(string gName);//called printsinglegradesecond becasue printsingle grade is already a function in student.hpp
    
    float getSingleGrade(string aName);
    
    string getStringListGradeToSave();
    
    float totalPP();//returns total points possible
    
    float totalPE();//returns total points earned
    
    void printListGrades();
    

    Grade * findInList(string aName);
    Grade * head;



};

#endif
