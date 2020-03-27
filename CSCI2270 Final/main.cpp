#include <iostream>
#include <vector>
#include <fstream>
#include "Class.hpp"

using namespace std;
//g++ -std=c++11 main.cpp Student.cpp Class.cpp GradeType.cpp -o run

void printMenu(){
  cout << endl << "----MAIN MENU----" << endl;
  cout << "1: Load a Class from File" << endl;
	cout << "2: Create a new Class" << endl;
	cout << "3: Print Current Classes" << endl;
  cout << "4: Open a Class" << endl;
	cout << "5: Remove a Class" << endl;
	cout << "6: Help" << endl;
	cout << "7: Quit" << endl;
}

bool isNumber(string input, int size){
  bool num = true;
  for (int i = 0; i < size; i++){
    if (input[i] < 48 || input[i] > 57){
      num = false;
    }
  }
  return num;
}

int findVectorIndex(vector <Class> cVector, string cName){
  for (int i = 0; i < cVector.size(); i++){
    if (cVector[i].getClassName() == cName){
      return i;
    }
  }
  return -1;
}

int main (int argc, char const *argv[]){
  //Class test ("test", 5);

  string sInput;
  int input = -1;
  int index;

  string className;
  int numStudents;
  vector <Class> classVector;

  while (input != 7){
    printMenu();
    getline(cin, sInput);
    if (sInput[0] < 49 || sInput[0] > 55){//if the first character of input string is not within 1-5 decimal bounds
      cout << sInput << " is an invalid input" << endl;//will run while loop again
    } else {
      input = stoi(sInput);
      switch(input){
        case 1:
        {
          cout << "Enter name of class file:" << endl;
          string fname;
          getline(cin, fname);
          ifstream readFile;
          readFile.open(fname);
          if (readFile.fail()){
            cout << fname << " could not be found" << endl;
            break;
          } 
          string cname;
          getline(readFile, cname);
          Class * newClass = new Class(cname, fname);
          classVector.push_back(*newClass);

        }
          break;
        case 2:
        {
          cout << "Enter a new class name:" << endl;
          getline(cin, className);
          Class * newClass = new Class(className);
          classVector.push_back(*newClass);
        }
          break;
        case 3:
          cout << "Classes currently open:" << endl;
          //cout << classVector.size() << endl;
          for (int i = 0; i < classVector.size(); i++){
            cout << classVector[i].getClassName() << endl;
          }
          break;
        case 4:
          cout << "Enter class name to be opened (must already have been created or loaded):" << endl;
          getline(cin, className);
          index = findVectorIndex(classVector, className);
          if (index == -1){
            cout << className << " is not open, here is a list of open classes" << endl;
            for (int i = 0; i < classVector.size(); i++){
              cout << classVector[i].getClassName() << endl;
            }
          } else {
            classVector[index].mainMenu();
          }

          break;
        case 5:
          cout << "Enter class name to be removed (if not saved class will be lost):" << endl;
          getline(cin, className);
          index = findVectorIndex(classVector, className);
          if (index == -1){
            cout << className << " is not open, here is a list of open classes" << endl;
            for (int i = 0; i < classVector.size(); i++){
              cout << classVector[i].getClassName() << endl;
            }
          } else {
            classVector.erase(classVector.begin() + index);
          }
          break;
        case 6:
          cout << "This program allows you to open and edit multiple classes!" << endl;
          cout << "You can either load a class from a file or you can create a new one" << endl;
          cout << "These classes will not be lost when you return to the main menu, and you can have as many open at once as you want" << endl;
          cout << "To see which classes you currently have open, go to the main menu and select 3" << endl;
          cout << "You can remove classes or add new ones and the other classes that are currently opened will not be affected." << endl;
          
          break;
      }
    }
  }

  return 0;
}
