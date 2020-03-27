#include "Class.hpp"
#include <fstream>
#include <cctype>
#include <stdio.h>
#include <ctype.h>

Class::Class(){

}

Class::Class(string cName){
    nameClass = cName;
    numStudents = 0;

    hashTable = new Student*[26];

    for (int i = 0; i < 26; i++)
    {
        hashTable[i] = NULL;
    }

    mainMenu();
}

Class::Class(string cName, string fname){//this constructor used when reading a class from a file
    // ifstream readFile;
    // readFile.open(fname);
    nameClass = cName;
    numStudents = 0;
    hashTable = new Student*[26];

    for (int i = 0; i < 26; i++)
    {
        hashTable[i] = NULL;
    }
    loadClass(fname);
    mainMenu();
    
    
}

void Class::miniMenu1(){
    cout << endl << "--------Class: " << nameClass << "--------" << endl;
    cout << "1: Add students from file" << endl;
    cout << "2: Add single student" << endl;
    cout << "3: Remove single student" << endl;
    cout << "4: Remove all students" << endl;
    cout << "5: Print current students" << endl;
    cout << "Enter a choice 1-5: " << endl;
}
void Class::miniMenu2(){
    cout << endl << "--------Class: " << nameClass << "--------" << endl;
    cout << "1: Add grade to all students" << endl;
    cout << "2: Add grade to one student" << endl;
    cout << "3: Remove specific grade from all students" << endl;
    cout << "4: Remove specific grade from single student" << endl;
    cout << "5: Edit specific grade of specific student" << endl;
    cout << "Enter a choice 1-5: " << endl;
}
void Class::miniMenu3(){
    cout << endl << "--------Class: " << nameClass << "--------" << endl;
    cout << "1: print single grade single student" << endl;
    cout << "2: print all grades single student" << endl;
    cout << "3: print single grade all students" << endl;
    cout << "4: print total class average" << endl;
    cout << "5: print single student average" << endl;
    cout << "6: print single assignment average" << endl;
    cout << "Enter a choice 1-6: " << endl;
}
void Class::miniMenu4(){
    cout << endl << "--------Class: " << nameClass << "--------" << endl;
    cout << "1: Save a report card for a student to a file" << endl;
    cout << "2: Print a report card for a single student" << endl;
    cout << "Enter a choice 1-2: " << endl;
}
void Class::printMainMenu(){
    cout << endl << "--------Class: " << nameClass << "--------" << endl;
    cout << "1: Add, Remove, or Load students" << endl;
    cout << "2: Add, Remove, or Edit a grade" << endl;
    cout << "3: Calculate grades" << endl;
    cout << "4: Create Report Cards" << endl;
    cout << "5: Save Class" << endl;
	cout << "6: Save and Quit" << endl;
	cout << "Enter a choice 1-6: " << endl;
}

bool isInBounds(string input, char low, char high){
    if (input[0] < low || input[0] > high){
        return false;
    }
    return true;
}



void Class::mainMenu(){
    /*
    	1: Add, Remove, or Load students C
    	    1: Add students from file C
    	    2: Add single student C
    	    3: Remove single student C
    	    4: Remove all students C
            5: Print current students C
		2: Add, Remove, or Edit a grade C
		    1: Add grade to all students C
		    2: Add grade to one student C
		    3: Remove specific grade from all students C
		    4: Remove specific grade from single student C
		    5: Edit specific grade of specific student C
		3: Calculate grades *N*
		    1: print single grade single student C
		    2: print all grades single student C
		    3: print single grade all students *N*
		    4: print total class average *N*
		    5: print single student average C
		    6: print single assignment average *N*
		4: Create Report Cards C
		    1: saveReportCardSingleStudent C
		    2: printReportCardSingleStudent C
		5: Save Class C
		6: Save and Quit C
    */

    string sInput;
    int input = -1;
    while (input != 6){
        printMainMenu();
        getline(cin, sInput);
        if (sInput[0] < 49 || sInput[0] > 54){//if the first character of input string is not within 1-7 decimal bounds
            cout << sInput << " is an invalid input" << endl;//will run while loop again
        } else {
        input = stoi(sInput);
        switch(input){
            case 1://1: Add, Remove, or Load students
                miniMenu1();
                getline(cin, sInput);
                if (isInBounds(sInput, '1', '5')){
                    sInput = sInput.substr(0,1);//used to make sure input is only one number
                    input = stoi(sInput);
                    switch (input) {
                        case 1://load students from file

                          cout << "Enter file name: " << endl;
                          getline(cin, sInput);
                          loadStudentsFromFile(sInput);
                          break;
                        case 2://add a student
                          cout << "Enter name of student to be added: " << endl;
                          getline(cin, sInput);
                          addStudent(sInput);
                          break;
                        case 3://Remove single student
                            cout << "Enter name of student to be removed: " << endl;
                            getline(cin, sInput);
                            removeStudent(sInput);

                          break;
                        case 4://Remove all students
                            cout << "Are you sure you want to remove all students from class? (cannot be undone) (y/n)" << endl;
                            getline(cin, sInput);
                            if (sInput == "y"){
                                removeAllStudents();
                            } else {
                                cout << sInput << " is an invalid input" << endl;
                            }
                            break;
                        case 5://print current students
                          printAllStudents();
                          break;
                    }
                } else {
                    cout << "Error: please enter a valid input" << endl;
                }
                break;
            case 2://	2: Add, Remove, or Edit a grade
                miniMenu2();
                getline(cin, sInput);
                if (isInBounds(sInput, '1', '5')){
                  sInput = sInput.substr(0,1);//used to make sure input is only one number
                    input = stoi(sInput);
                    switch (input) {
                        case 1://1: Add grade to all students
                             addGradeToAllStudents();
                             break;
                        case 2:// 2: Add grade to one student
                            addGradeSingleStudent();
                             break;
                        case 3://3: Remove specific grade from all students
		    
                            removeGradeAllStudents();

                             break;
                        case 4://4: Remove specific grade from single student

                            removeGradeSingleStudent();
                            break;
                        case 5://5: Edit specific grade of specific student
                            editGradeSingleStudent();
                            break;
                    }
                } else {
                    cout << "Error: please enter a valid input" << endl;
                }
                break;
            case 3://3: Calculate grades
                miniMenu3();
                getline(cin, sInput);
                if (isInBounds(sInput, '1', '6')){
                  sInput = sInput.substr(0,1);//used to make sure input is only one number
                    input = stoi(sInput);
                    switch (input) {
                        case 1://print single grade single student
                            printSingleGradeSingleStudent();
                             break;
                        case 2://2: print all grades single student
                            
                            printAllGradesSingleStudent();

                             break;
                        case 3://print single grade all students
                            printSingleGradeAllStudents();
                             break;
                        case 4:// 4: print total class average
                            cout << endl << "--Class Average--: " << getClassAverage() << "%" << endl;
                            break;
                        case 5://5: print single student average
                        {
                        string name;
                        cout << "Enter the name of the student whose grade you'd like to view" << endl;
                        getline(cin, name);
                        Student* temp = findStudent(name);
                        while (temp == NULL)
                         {
                            cout << "Name not found" << endl;
                            cout << "Enter the name of the student whose grade you'd like to view" << endl;
                             getline(cin, name);
                             temp = findStudent(name);
                         }
                            getOverallSingleStudent(temp);
                        }
                            break;
                        case 6://6: print single assignment average
                            printAssignmentAverage();
                            input = 0;
                            break;
                    }
                } else {
                    cout << "Error: please enter a valid input" << endl;
                }
                break;
            case 4://4: Create Report Cards
                miniMenu4();
                getline(cin, sInput);
                if (isInBounds(sInput, '1', '2')){
                  sInput = sInput.substr(0,1);//used to make sure input is only one number
                    input = stoi(sInput);
                    switch (input) {
                        case 1://2: saveReportCardSingleStudent
                            saveReportCardSingleStudent();
                             break;
                        case 2://3: printReportCardSingleStudent
                            printReportCardSingleStudent();
                             break;
                    }
                } else {
                    cout << "Error: please enter a valid input" << endl;
                }
                break;
            // case 5://Attendance
            //     miniMenu5();
            //     getline(cin, sInput);
            //     if (isInBounds(sInput, '1', '2')){
            //       sInput = sInput.substr(0,1);//used to make sure input is only one number
            //         input = stoi(sInput);
            //         switch (input) {
            //             case 1://1: Take attendance for today *N*
            //                 takeAttendanceForToday();
            //                  break;
            //             case 2://view single student's attendance
            //                 viewStudentAttendance();
            //                 break;

            //         }
            //     } else {
            //         cout << "Error: please enter a valid input" << endl;
            //     }
            //     break;
            case 5://5: Save Class
                //cout << nameClass << " being saved" << endl;
                saveClass();
                break;
        }
    }
    


    }
    saveClass();
}

int Class::hashNum(string input){
    int ascii = int(tolower(input[0]));
    int hNum = ascii - 97;
    //cout << input << " hash num is " << hNum << endl;
    return hNum;
    
}

Student* Class::findStudent(string sName){
    int num = hashNum(sName);
    Student * temp = hashTable[num];
    if (temp == NULL){
        return NULL;
    }
    if (temp->getName() == sName)
    {
      return temp;
    }
    //cout << "here" << endl;
      if (temp == NULL)
      {
        cout << "Student not found" << endl;
        return NULL;
      }
      while(temp != NULL)
      {
          if (temp->getName() == sName){
              return temp;
          }
        temp = temp->next;
      }
      //cout <<  "here 2" << endl;
      return NULL;
      
    
}



  /////Part 1/////: Add, Remove, or Load students

  void Class::loadStudentsFromFile(string fileName){
      ifstream readFile (fileName, std::ifstream::in);
      if (readFile.fail()){
        cout << "Could not open " << fileName << endl;
      }
      string fromFile;
      while (getline(readFile, fromFile)){
        cout <<"Adding " << fromFile << endl;
        addStudent(fromFile);
      }

  }//loads students into class from a file


  void Class::addStudent(string sName){
      int hash = hashNum(sName);
      Student* newStudent = new Student(sName);
      if (hashTable[hash] == NULL)
      {
          hashTable[hash] = newStudent;
          numStudents++;
      }
      else
      {
          Student *temp = hashTable[hash];
          while(temp->next != NULL)
          {
              temp = temp->next;
          }
          temp->next = newStudent;
          numStudents++;
      }
  }//adds a single student into the hash table of students


  void Class::removeStudent(string sName){
    int hash = hashNum(sName);
    if(hashTable[hash] == NULL){
        cout << sName << " does not exist in this Class." << endl;
    } else{
        Student *temp = hashTable[hash];
        if (temp->getName() == sName){//if head is being removed
            //cout << "got here 3" << endl;
            hashTable[hash] = temp->next;
            cout << sName << " removed from class" << endl;
            delete temp;
            numStudents--;
            return;
        } else {//student is somewhere in list
            Student *nTemp = temp->next;
            while (nTemp != NULL){
                if (nTemp->getName() == sName){
                    temp->next = nTemp->next;
                    delete nTemp;
                    numStudents--;
                    cout << sName << " removed from class" << endl;
                    return;
                }
                nTemp = nTemp->next;
                temp = temp->next;
            }
            cout << sName << " could not be found" << endl;
            
        }
    }
  }//removes a student from the hash table


  void Class::removeAllStudents(){
   while(numStudents != 0){
       for (int i = 0; i < 26; i++){
           if (hashTable[i] != NULL){
               removeStudent(hashTable[i]->getName());
           }
       }
   }
  }//removes all students from class

  void Class::printList(Student * stud){
    while (stud != NULL){
      cout << stud->getName() << endl;
      stud = stud->next;
    }
  }

  void Class::printAllStudents(){
    //cout << "Got here" << endl;
    cout << numStudents << " Students in " << nameClass << endl;
    for (int i = 0; i < 26; i++){
      if (hashTable[i] != NULL){
        //printList(hashTable[i]);
        printList(hashTable[i]);
      }
    }

  }//prints all students in database;



  /////Part 2//////: Add, Remove, or Edit a grade
  
  bool isNumberClass(string input, int size){
  bool num = true;
  for (int i = 0; i < size; i++){
    if (input[i] < 48 || input[i] > 57){
      num = false;
    }
  }
  return num;
}

  void Class::addGradeToAllStudents(){
    string gName;
      string pp;
      string pe;
      string type;
      cout << endl << "Enter 0 to add a Homework grade." << endl << "Enter 1 to add a Quiz grade." << endl << "Enter 2 to add a Test grade." << endl << "Enter 3 to  add a Project grade." << endl << "Enter 4 to add an Attendance grade." << endl;
      getline(cin, type);
      while (!isInBounds(type, '0', '4'))
      {
        cout << "invalid input." << endl;
        cout << endl <<"Enter 0 to add a Homework grade." << endl << "Enter 1 to add a Quiz grade." << endl << "Enter 2 to add a Test grade." << endl << "Enter 3 to  add a Project grade." << endl << "Enter 4 to add an Attendance grade." << endl;
        getline(cin, type);
      }
      cout << "Enter grade name:" << endl;
      getline(cin, gName);
      cout << "Enter Points Possible for this grade." << endl;
      getline(cin, pp);
      while (!isNumberClass(pp, pp.length())){
          cout << "Error: Please enter a number" << endl;
          cout << "Enter Points Possible for this grade." << endl;
            getline(cin, pp);
      }
        for (int i = 0; i < 26; i++)
        {
            if (hashTable[i] != NULL)
            {
                Student * temp = hashTable[i];
                while(temp != NULL)
                {
                    cout <<"Enter points earned for " << temp->getName() << " on "<< gName << endl;
                    getline(cin, pe);
                    temp->gradeAdd(gName, stoi(pp), stoi(pe), stoi(type));
                    temp = temp->next;
                }
            }
        }
      
  }//fucntion will ask for name, points possible, points earned, and classification (is it a quiz, test, assignment, project or attendance grade)

  void Class::addGradeSingleStudent(){
      string gName;
      string sName;
      string pp;
      string pe;
      string type;
      cout << "Enter student name:" << endl;
      getline(cin, sName);
      Student* temp = findStudent(sName);
        while (temp == NULL)
         {
            cout << "Name not found" << endl;
            cout << "Enter student name" << endl;
            getline(cin, sName);
            temp = findStudent(sName);
        }
                         
      cout << "Enter grade name:" << endl;
      getline(cin, gName);
      cout << "Enter 0 to add a Homework grade." << endl << "Enter 1 to add a Quiz grade." << endl << "Enter 2 to add a Test grade." << endl << "Enter 3 to  add a Project grade." << endl << "Enter 4 to add an Attendance grade." << endl;
      getline(cin, type);
      while (!isInBounds(type, '0', '4'))
      {
        cout << "invalid input." << endl;
        cout << "Enter 0 to add a Homework grade." << endl << "Enter 1 to add a Quiz grade." << endl << "Enter 2 to add a Test grade." << endl << "Enter 3 to  add a Project grade." << endl << "Enter 4 to add an Attendance grade." << endl;
        getline(cin, type);
      }
      cout << "Enter Points Possible for this grade." << endl;
      getline(cin, pe);
      while (!isNumberClass(pe, pe.length())){
          cout << "Error: Please enter a number" << endl;
          cout << "Enter Points Possible for this grade." << endl;
            getline(cin, pe);
      }
      cout << "Enter Points Earned for this grade." << endl;
      getline(cin, pp);
      while (!isNumberClass(pp, pp.length())){
          cout << "Error: Please enter a number" << endl;
          cout << "Enter Points Possible for this grade." << endl;
            getline(cin, pp);
      }
      temp = findStudent(sName);
      if (temp == NULL)
      {
          return;
      }
      temp->gradeAdd(gName,stoi(pe), stoi(pp), stoi(type));

  }//adds a grade to a specific student

  void Class::removeGradeAllStudents(){
      string type;
    cout << endl << "Enter 0 to remove a Homework grade." << endl << "Enter 1 to remove a Quiz grade." << endl << "Enter 2 to remove a Test grade." << endl << "Enter 3 to  remove a Project grade." << endl << "Enter 4 to remove an Attendance grade." << endl;
      getline(cin, type);
    while (!isInBounds(type, '0', '4'))
    {
        cout << "invalid input." << endl;
        cout << endl << "Enter 0 to remove a Homework grade." << endl << "Enter 1 to remove a Quiz grade." << endl << "Enter 2 to remove a Test grade." << endl << "Enter 3 to  remove a Project grade." << endl << "Enter 4 to remove an Attendance grade." << endl;
        getline(cin, type);
     }
     cout << "Enter grade name: " << endl;
     string gName;
    getline(cin, gName);
    Student * temp;
    for (int i = 0; i < 26; i++){
        if (hashTable[i] != NULL){
            temp = hashTable[i];
            while (temp != NULL){
                temp->gradeRemove(gName, stoi(type));
                temp = temp->next;
            }
            
        }
    }
    
  }//fucntions the same as addgradeallstudetns but removes the grade instead


  void Class::removeGradeSingleStudent(){
      string gName;
      string sName;
      cout << "Enter student name: " << endl;
      getline(cin, sName);
      Student* temp = findStudent(sName);
        while (temp == NULL)
         {
            cout << "Name not found" << endl;
            cout << "Enter student name" << endl;
            getline(cin, sName);
            temp = findStudent(sName);
        }
        
      cout << "Enter grade name: " << endl;
      getline(cin, gName);
      string type;
        cout << endl << "Enter 0 to remove a Homework grade." << endl << "Enter 1 to remove a Quiz grade." << endl << "Enter 2 to remove a Test grade." << endl << "Enter 3 to  remove a Project grade." << endl << "Enter 4 to remove an Attendance grade." << endl;
      getline(cin, type);
      while (!isInBounds(type, '0', '4'))
      {
        cout << "invalid input." << endl;
        cout << endl << "Enter 0 to remove a Homework grade." << endl << "Enter 1 to remove a Quiz grade." << endl << "Enter 2 to remove a Test grade." << endl << "Enter 3 to  remove a Project grade." << endl << "Enter 4 to remove an Attendance grade." << endl;
        getline(cin, type);
      }
      temp->gradeRemove(gName, stoi(type));

  }//removes single grade from specific student


  void Class::editGradeSingleStudent(){
      string pp;
      string pe;
      string type;
      string sName;
      string aName;
      cout << "Enter student name:" << endl;
      getline(cin, sName);
      cout << "Enter 0 to change a Homework grade." << endl << "Enter 1 to change a Quiz grade." << endl << "Enter 2 to change a Test grade." << endl << "Enter 3 to  change a Project grade." << endl << "Enter 4 to change an Attendance grade." << endl;
      getline(cin, type);
      while (!isInBounds(type, '0', '4'))
      {
        cout << "invalid input." << endl;
        cout << "Enter 0 to change a Homework grade." << endl << "Enter 1 to change a Quiz grade." << endl << "Enter 2 to change a Test grade." << endl << "Enter 3 to  change a Project grade." << endl << "Enter 4 to change an Attendance grade." << endl;
        getline(cin, type);
      }
      cout << "Enter assignment name: " << endl;
      getline(cin, aName);
      cout << "Enter a new Points Possible for this grade" << endl;
      getline(cin, pp);
      cout << "Enter a new Points Earned for this grade" << endl;
      getline(cin, pe);
      int num = hashNum(sName);
      Student* temp = hashTable[num];
      while (temp->getName() != sName)
      {
          temp = temp->next;
      }
      if (temp == NULL)
      {
          cout << "Student not found." << endl;
      }
      else
      {
          temp->gradeChange(aName, stoi(pp), stoi(pe), stoi(type));
      }
      

  }//changes single grade single student




  /////Part 3//////: Calculate grades

  void Class::printSingleGradeSingleStudent(){//need type, student name and grade name
  string sName;
    cout << "Enter name of student: " << endl;
    getline(cin, sName);
    Student* temp = findStudent(sName);
        while (temp == NULL)
         {
            cout << "Name not found" << endl;
            cout << "Enter student name" << endl;
            getline(cin, sName);
            temp = findStudent(sName);
        }
    cout << "Enter name of assignment: " << endl;
    string gName;
    getline(cin, gName);
    cout << endl << "What kind of grade is it?" << endl;
    cout << "0: Homework" << endl;
    cout << "1: Quiz" << endl;
    cout << "2: Test" << endl;
    cout << "3: Project" << endl;
    cout << "4: Attendance" << endl;
    cout << "Enter a number 0-4:" << endl;
    string sType;
    int type;
    getline(cin, sType);
    while (!isInBounds(sType, '0', '4')){
        cout << "Error: Enter a number between 0 and 4" << endl;
        cout << "Enter a number between 0 and 4:" << endl;
        getline(cin, sType);
    }
    type = stoi(sType);
    
    temp = findStudent(sName);
    cout << sName << ": ";
    temp->printSingleGrade(gName, type);
    
    
  }//prints single assignment grade for specific student

  float Class::getOverallSingleStudent(Student * temp)
  {
      float pp = 0.0;
      float pe = 0.0;
      for (int i = 0; i < 5; i++)
      {
          if (temp->getTypeHead(i) != NULL)
          {
              Grade * tempgrade = temp->getTypeHead(i);
              while (tempgrade != NULL)
              {
                  pp+=tempgrade->pointsPossible;
                  pe+=tempgrade->pointsEarned;
                  tempgrade = tempgrade->next;
              }
          }
      }
      cout << temp->getName() << "'s Average: " << to_string((pe/pp) * 100) << "%" << endl;
      return ((pe/pp) * 100);
  }
  void Class::printAllGradesSingleStudent(){
        string sName;
        cout << "Enter Student Name: " << endl;
        getline(cin, sName);
        Student *temp = findStudent(sName);
        if (temp == NULL){
            cout << sName << " could not be found" << endl;
        } else {
            temp->printAllGrades();
        }
        
  }//prints all grades for a single student


  void Class::printSingleGradeAllStudents(){
    cout << "Enter name of assignment: " << endl;
    string gName;
    getline(cin, gName);
    cout << endl << "What kind of grade is it?" << endl;
    cout << "0: Homework" << endl;
    cout << "1: Quiz" << endl;
    cout << "2: Test" << endl;
    cout << "3: Project" << endl;
    cout << "4: Attendance" << endl;
    cout << "Enter a number 0-4:" << endl;
    string sType;
    int type;
    getline(cin, sType);
    while (!isInBounds(sType, '0', '4')){
        cout << "Error: Enter a number between 0 and 4" << endl;
        cout << "Enter a number between 0 and 4:" << endl;
        getline(cin, sType);
    }
    type = stoi(sType);
    Student *temp;
    
    for (int i = 0; i < 26; i++){
        if (hashTable[i] != NULL){
            temp = hashTable[i];
            while (temp != NULL){
                cout << temp->getName() << ": ";
                temp->printSingleGrade(gName, type);
                temp = temp->next;
            }
        }
    }
  }//prints what each student got on a specific assignment

  float Class::getClassAverage(){
      int sumGrades = 0.0;
      int counter = 0.0;
      for (int i = 0; i < 26; i++)
      {
          if (hashTable[i] != NULL)
          {
              Student * temp = hashTable[i];
              while(temp != NULL)
              {
                  sumGrades+=getOverallSingleStudent(temp);
                  counter++;
                  temp = temp->next;
              }
          }
      }
      return (sumGrades/counter);
  }//returns total class average


  void Class::printAssignmentAverage(){
      string aName;
      cout << endl << "Enter 0 to print a Homework grade." << endl << "Enter 1 to print a Quiz grade." << endl << "Enter 2 to print a Test grade." << endl << "Enter 3 to  print a Project grade." << endl << "Enter 4 to print an Attendance grade." << endl;
      cout << "Enter a number 0-4:" << endl;
        string sType;
        int type;
        getline(cin, sType);
        while (!isInBounds(sType, '0', '4')){
            cout << "Error: Enter a number between 0 and 4" << endl;
            cout << "Enter a number between 0 and 4:" << endl;
            getline(cin, sType);
        }
    type = stoi(sType);
      cout << "Enter Assignment Name:" << endl;
      float total = 0;
      float counter = 0;
      getline(cin, aName);
      Student *temp;
      for (int i = 0; i < 26; i++)
      {
          if (hashTable[i] != NULL)
          {
              temp = hashTable[i];
              while (temp != NULL){
                  total = total + temp->getGrade(type, aName);
                  counter++;
                  temp = temp->next;
              }
              
          }
      }
      cout << "Average for " << aName << " = " << (total/counter) * 100 << "%" << endl;

  }//prints class average on one assignment, type is 0-4 from homework to test




  /////Part 4//////: Create Report Cards

  void Class::saveCardStudent(Student * stu){
      ofstream writeFile;
      writeFile.open(stu->getName() + "RC" + nameClass);
      writeFile << stu->getName() << endl;
      writeFile << "Class: " << nameClass << endl << endl;
      float totalPP = 0;
      float totalPE = 0;
      float currPP = 0;
      float currPE = 0;
      
      for (int i = 0; i < 5; i++){
          writeFile << "---" << stu->getTypeName(i) << "---" << endl;
          currPP = stu->typePointsPossible(i);
          currPE = stu->typePointsEarned(i);
          totalPP = totalPP + currPP;
          totalPE = totalPE + currPE;
          
          writeFile << "Points Possible: " << currPP << endl;
          writeFile << "Points Earned: " << currPE << endl;
          if (currPP != 0){
          writeFile << "Average: " << (currPE / currPP) * 100 << "%" << endl << endl;
          } else {
              writeFile << "Average: 0%" << endl << endl; 
          }
       }
       
       writeFile << "---TOTAL GRADE---" << endl;
       writeFile << "Points Possible: " << totalPP << endl;
       writeFile << "Points Earned: " << totalPE << endl;
       writeFile << "Grade: " << (totalPE / totalPP)*100 << "%" << endl;
      
  }
  
  void Class::printCardStudent(Student * stu){
      
      cout << stu->getName() << endl;
      cout << "Class: " << nameClass << endl << endl;
      float totalPP = 0;
      float totalPE = 0;
      float currPP = 0;
      float currPE = 0;
      
      for (int i = 0; i < 5; i++){
          cout << "---" << stu->getTypeName(i) << "---" << endl;
          currPP = stu->typePointsPossible(i);
          currPE = stu->typePointsEarned(i);
          totalPP = totalPP + currPP;
          totalPE = totalPE + currPE;
          
          cout << "Points Possible: " << currPP << endl;
          cout << "Points Earned: " << currPE << endl;
          if (currPP != 0){
          cout << "Average: " << (currPE / currPP) * 100 << "%" << endl << endl;
          } else {
              cout << "Average: 0%" << endl << endl; 
          }
      }
       
      cout << "---TOTAL GRADE---" << endl;
      cout << "Points Possible: " << totalPP << endl;
      cout << "Points Earned: " << totalPE << endl;
      cout << "Grade: " << (totalPE / totalPP)*100 << "%" << endl;
      
  }


  void Class::saveReportCardSingleStudent(){
      cout << "Enter name of student:" << endl;
      string sName;
      getline(cin, sName);
      Student * temp = findStudent(sName);
      if (temp == NULL){
          cout << sName << " could not be found" << endl;
      } else {
        cout << "Saving report card for " <<sName << " in file <student name>RC<Class Name>.txt" << endl;
        saveCardStudent(temp);
      }
      

  }//saves a report card for a single student in a file


  void Class::printReportCardSingleStudent(){
    cout << "Enter name of student:" << endl;
      string sName;
      getline(cin, sName);
      Student * temp = findStudent(sName);
      if (temp == NULL){
          cout << sName << " could not be found" << endl;
      } else {
        cout << "Printing report card for " <<sName << endl;
        printCardStudent(temp);
      }
  }//prints report card for a single student, does not save to a file



  /////Part 5/////: Save Class
  
/**
 *  Saving Class
 * 
 * Class Name
 * numstudents
 * 
 * hash table of students
 * 
 * grades for each student
 * 


**/
    string Class::getListGrades(int type, Student * stu){
        return stu->getGradeList(type);
    }

  void Class::saveClass(){
      cout << nameClass << " being saved to file " << nameClass << "(Class).txt" << endl;
      ofstream myFile;
      myFile.open(nameClass+"(Class).txt");
      myFile << nameClass << endl;
      myFile << numStudents << endl;
      Student *temp;
      for (int i = 0; i < 26; i++){
          if (hashTable[i] != NULL){
              temp = hashTable[i];
              
              while(temp != NULL){
                  myFile << temp->getName() << endl;
                  temp = temp->next;
              }
          }
      }
      myFile << "---" << endl;
      //Student * temp;
      for (int i = 0; i < 26; i++){
          if (hashTable[i] != NULL){
              temp = hashTable[i];
              while (temp != NULL){
                  cout << "Saving grades for " << temp->getName() << endl;
                  myFile << temp->getName() << endl;
                  myFile << "0" << getListGrades(0, temp) << endl;
                  myFile << "1" << getListGrades(1, temp) << endl;
                  myFile << "2" << getListGrades(2, temp) << endl;
                  myFile << "3" << getListGrades(3, temp) << endl;
                  myFile << "4" << getListGrades(4, temp) << endl;
                  
                  temp = temp->next;
              }
              
          }
      }
  }//saves class to a file in a way that it can be loaded again into the program at a different time
  
  int split (string str, char c, string array[], int size)//helper function to split string inputs
 {
    if (str.length() == 0) {
         return 0;
     }
    string word = "";
    int count = 0;
    str = str + c;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == c)
        {
            if (word.length() == 0)
                continue;
            array[count++] = word;
            word = "";
        } else {
            word = word + str[i];
        }
    }
    return count ;
 }
 
 int howManyGrades(string line){
     int wordCount = 0;
     for (int i = 0; i < line.length(); i++){
         if (line[i] == ';'){
             wordCount++;
         }
     }
     return wordCount;
 }
 
 void Class::loadClass(string fname){
    ifstream readFile;
    readFile.open(fname);
    string test;
    getline(readFile, test);
    cout << "Loading Class: " << test << endl;
    
    string nameIn;
    getline(readFile, nameIn);
    int nStu = stoi(nameIn);
    
    getline(readFile, nameIn);
    
    while (nameIn != "---"){
        addStudent(nameIn);
        cout << nameIn << endl;
        getline(readFile, nameIn);
    }
    string gLine;
    Student * aStu;
    int numGrade;
    string * splitArray;
    string gArray[3];
    for (int i = 0; i < nStu; i++){
        getline(readFile, nameIn);
        aStu = findStudent(nameIn);
        for (int j = 0; j < 5; j++){
            getline(readFile, gLine);
            //cout << nameIn << ": " << gLine << endl;
            numGrade = howManyGrades(gLine);
            splitArray = new string [numGrade + 1];
            //cout << gLine  << "---split, numGrade: " << numGrade << endl;
            split(gLine, ';', splitArray, numGrade+1);
            for (int z = 1; z < numGrade + 1; z++){
                split(splitArray[z], ',', gArray, 3);
                aStu->gradeAdd(gArray[0], stof(gArray[1]), stof(gArray[2]), j);
            }
            delete [] splitArray;
        }
    }
 }




  /////Part 6/////: Save and Quit

  bool Class::saveAndQuit(){
      saveClass();
  }//calls saveClass and ends mainMenu function

  string Class::getClassName(){
    return nameClass;
  }