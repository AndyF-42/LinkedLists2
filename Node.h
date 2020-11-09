//Created by Vatsal Parikh
//Date: 10/27/20
//.h file for the node class

//imports
#include <iostream>
#include <cstring>
#include "Student.h"

//start of header guard
#ifndef NODE_H
#define NODE_H

using namespace std;

class Node {
public: //public methods/variables
  Node(); //default constructor
  Node(Student* std); //constructor with student
  ~Node(); //destructor
  Node* getNext(); //returns node pointer to next node
  Student* getStudent(); //returns student pointer to student in the node
  void setNext(Node* n); //sets the next node pointer to whatever is passed
private: //private methods/variables
  Student* student; //student pointer
  Node* next; //node pointer to next node
};

//end of header guard
#endif
