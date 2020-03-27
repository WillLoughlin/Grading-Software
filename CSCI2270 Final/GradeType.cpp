#include "GradeType.hpp"
#include <string>
using namespace std;

GradeType::GradeType(){
    nameType = "";
    numGrades = 0;
    head = NULL;
}

GradeType::GradeType(string nType){
    nameType = nType;
    numGrades = 0;
    head = NULL;
}

GradeType::~GradeType(){
    if (head = NULL){
        return;
    }
    Grade * past;
    Grade * temp = head;
    bool running = true;
    while (running){
        past = temp;
        temp = temp->next;
        delete past;
        if (temp == NULL){
            running = false;
        }
    }
}

void GradeType::addGrade(string aName, float ptsP, float ptsE){
    Grade * newGrade = new Grade;//creating new grade object to add to linked list
    newGrade->gradeName = aName;
    newGrade->pointsPossible = ptsP;
    newGrade->pointsEarned = ptsE;
    newGrade->next = NULL;

    if (head == NULL){
        head = newGrade;
        numGrades = 1;
    } else {
        Grade * temp = head;
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newGrade;
    }
    cout << aName << " added successfully to " << nameType << endl;
    numGrades++;
}
float GradeType::getSingleGrade(string aName)
{
    Grade * temp = head;
    if (temp == NULL)
    {
        cout << "Assignment not found." << endl;
        return 0;
    }
    while(temp != NULL){
        if (temp->gradeName == aName){
            return temp->pointsEarned/temp->pointsPossible;
        }
        temp = temp->next;
    } 
    cout << "Assignment not found." << endl;
    return 0;
    
}

void GradeType::removeGrade(string aName){
    Grade * toRem = findInList(aName);
    if (toRem == NULL){
        cout << aName << " could not be found in list." << endl;
        return;
    }
    if (head == toRem){
        head = head->next;
        delete toRem;
        cout << aName << " deleted successfully" << endl;
        numGrades--;
        return;
    }
    Grade * temp = head;
    while (temp->next != toRem){
        temp = temp->next;
    }
    temp->next = toRem->next;
    delete toRem;
    cout << aName << " deleted successfully" << endl;
    numGrades--;
    return;

}

string GradeType::getNameType(){
    return nameType;
}

int GradeType::getNumGrades(){
    return numGrades;
}

void GradeType::printList(){
    cout << nameType << endl;
    for (Grade * i = head; i != NULL; i = i->next){
        cout << i->gradeName << "--> Points Possible: " << i->pointsPossible << " Points Earned: " << i->pointsEarned << endl;
    }
}

Grade * GradeType::findInList(string aName){
    for (Grade * temp = head; temp != NULL; temp=temp->next){//searching through list
        if (temp->gradeName == aName){//if temp name equals input name
            return temp;//return temp pointer
        }
    }
    return NULL;
}

float GradeType::calcAverage(){
    float possible = 0;
    float earned = 0;
    for (Grade * i = head; i != NULL; i = i->next){
        possible = possible + i->pointsPossible;
        earned = earned + i->pointsEarned;
    }

    float average = earned / possible;
    return average;
}

void GradeType::printSingleGradeSecond(string gName){
    bool printed = false; 
    Grade * temp = head;
    while (temp != NULL){
        if (temp->gradeName == gName){
            cout << "--" << gName << "--" << endl;
            cout << "Points Possible: " << temp->pointsPossible << endl;
            cout << "Points Earned: " << temp->pointsEarned << endl;
            cout << "Percent: " << (temp->pointsEarned / temp->pointsPossible) * 100 << "%" << endl << endl;
            printed = true;
         }
         temp = temp->next;
    }
    if (!printed){
        cout << gName << " could not be found" << endl;
    }
}

string GradeType::getStringListGradeToSave(){
    Grade * temp = head;
    string gList = "";
    while (temp != NULL){
        gList = gList + ";" + temp->gradeName + "," + to_string(temp->pointsPossible) + "," + to_string(temp->pointsEarned);
        temp = temp->next;
    }
    return gList;
}


float GradeType::totalPP(){
    Grade * temp = head;
    float tPP = 0;
    while (temp != NULL){
        tPP = tPP + temp->pointsPossible;
        temp = temp->next;
    }
    return tPP;
}//returns total points possible
    
float GradeType::totalPE(){
    Grade * temp = head;
    float tPE = 0;
    while (temp != NULL){
        tPE = tPE + temp->pointsEarned;
        temp = temp->next;
    }
    return tPE;
}//returns total points earned

void GradeType::printListGrades(){
    Grade * temp = head;
    while(temp != NULL){
        cout<< "--" << temp->gradeName << "--" << endl;
        cout << "Points Possible: " << temp->pointsPossible << endl;
        cout << "Points Earned: " << temp->pointsEarned << endl;
        cout << "Grade: " << (temp->pointsEarned/temp->pointsPossible)*100 << "%" << endl << endl;
        temp = temp->next;
    }
    /*
    --Homework 1--
    Points Possible:10
    Points Earned: 9
    Grade:90%
    */
}