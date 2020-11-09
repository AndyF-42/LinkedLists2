//Creator: Andy Fleischer
//Date: 10/30/20
//Body of Student class

#include "Student.h"
#include <cstring>

Student::Student(char* newFirst, char* newLast, int newID, float newGPA) {
  strcpy(first, newFirst);
  strcpy(last, newLast);
  id = newID;
  gpa = newGPA;
}
Student::~Student() {

}

char* Student::getFirst() {
  return first;
}

char* Student::getLast() {
  return last;
}

int Student::getID() {
  return id;
}

float Student::getGPA() {
  return gpa;
}
