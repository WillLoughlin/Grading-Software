#ifndef CLASS_HPP
#define CLASS_HPP

#include <iostream>
#include "Student.hpp"
using namespace std;


class Class
{
public:
  Class();

  Class(string cName);
  
  Class(string cName, string fname);
  
  Student* findStudent(string sName);

  int hashNum(string input);

  void miniMenu1();

  void miniMenu2();

  void miniMenu3();

  void miniMenu4();

  void miniMenu5();

  void printMainMenu();

  void mainMenu();//main menu that handles most of the processes for the program



  /////Part 1/////: Add, Remove, or Load students

  void loadStudentsFromFile(string fileName);//loads students into class from a file

  void addStudent(string sName);//adds a single student into the hash table of students

  void removeStudent(string sName);//removes a student from the hash table

  void removeAllStudents();//removes all students from class

  void printList(Student * stud);//prints a linked list of students

  void printAllStudents();//prints all students in database;



  /////Part 2//////: Add, Remove, or Edit a grade

  void addGradeToAllStudents();//fucntion will ask for name, points possible, points earned, and classification (is it a quiz, test, assignment, project or attendance grade)

  void addGradeSingleStudent();//adds a grade to a specific student

  void removeGradeAllStudents();//fucntions the same as addgradeallstudetns but removes the grade instead

  void removeGradeSingleStudent();//removes single grade from specific student

  void editGradeSingleStudent();//changes single grade single student



  /////Part 3//////: Calculate grades
  float getOverallSingleStudent(Student * temp);

  void printSingleGradeSingleStudent();//prints single assignment grade for specific student

  void printAllGradesSingleStudent();//prints all grades for a single student

  void printSingleGradeAllStudents();//prints what each student got on a specific assignment

  void printClassAverage();//gets class average and prints it

  float getClassAverage();//returns total class average

  float getStudentAverage();//returns student average

  void printAssignmentAverage();//prints class average on one assignment, type is 0-4 from homework to test


  /////Part 4//////: Create Report Cards
  
  void printCardStudent(Student * stu);
  
  void saveCardStudent(Student * stu);//helper function to create file

  void saveReportCardSingleStudent();//saves a report card for a single student in a file

  void printReportCardSingleStudent();//prints report card for a single student, does not save to a file



  /////Part 5//////: Attendance

  void takeAttendanceForToday();//asks for a date and then asks if each student is here today with a simple 1 or 2 answer, then displays who is here and who is absent\

  void viewStudentAttendance();//asks for student name then prints which days they were in class and which they were not




  /////Part 6/////: Save Class
  
  string getListGrades(int type, Student * stu);//saves the list of each grade to a file

  void saveClass();//saves class to a file in a way that it can be loaded again into the program at a different time
  
  void loadClass(string fname);//loads a class save from a file
  
 

  /////Part 7/////: Save and Quit

  bool saveAndQuit();//asks to make sure that user wants to save and quit, calls save function, then returns true if user wants to quit, then mainMenu will return and the user will be brought back to the main.cpp

  string getClassName();//returns class name

private:
  string nameClass;
  int numStudents;
  float classAverage;
  Student ** hashTable;


};

#endif
