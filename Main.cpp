//Creator: Andy Fleischer
//Date: 10/30/20
//Main class for project

#include "Node.h"
#include <iostream>
#include <cstring>

using namespace std;

void addStudent(Node* &head, Student* newStudent);
void printStudents(Node* next);
void deleteStudent(Node* head);

int main() {

  cout << "Welcome to Student List - Linked Lists version!" << endl;
  cout << "Valid commands are \"ADD\", \"PRINT\", \"DELETE\", AVERAGE\", and \"QUIT\"" << endl;
  
  Node* head = NULL;
  
  while (strcmp(input, "QUIT") != 0) {
    cout << ">> ";
    cin >> input;
    if (strcmp(input, "ADD") == 0) {
      addStudent(vPtr);
    } else if (strcmp(input, "PRINT") == 0) {
      printStudents(vPtr);
    } else if (strcmp(input, "DELETE") == 0) {
      deleteStudent(head);
    } else if (strcmp(input, "AVERAGE") == 0) {
      //average GPAs
    } else if (strcmp(input, "QUIT") != 0) { //anything else (besides quit) will be invalid
      cout << "Invalid command." << endl;
    }
  }
  cout << "Goodbye!" << endl;

  return 0;
}

//add a new node (holding a new student) to the linked list
void add(Node* &head, Student* newStudent) {
  Node* current = head;
  if (current == NULL) { //head is NULL, meaning no data in linked list yet
    head = new Node(newStudent);
  }
  else {
    while (current->getNext() != NULL) { //get to last node in list
      current = current->getNext();
    }
    current->setNext(new Node(newStudent));
  }
}

//print out the student data of every node in the linked list
void print(Node* next) {
  if (next != NULL) {
    cout << next->getStudent()->getFirst();
    cout << " " << next->getStudent()->getLast();
    cout << ", ID: " << next->getStudent()->getID();
    cout << ", GPA: " << next->getStudent()->getGPA() << endl;
    print(next->getNext());
  }
}
