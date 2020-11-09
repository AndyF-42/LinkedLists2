//Creator: Andy Fleischer
//Date: 10/30/20
//Main class for project

#include "Node.h"
#include <iostream>
#include <cstring>

using namespace std;

void addStudent(Node* head, Student* newStudent);
void printStudents(Node* next);
void deleteStudent(Node* head, int id);
void averageGPAs(Node* head, float total, int numStudents);

int main() {

  cout << "Welcome to Student List - Linked Lists version!" << endl;
  cout << "Valid commands are \"ADD\", \"PRINT\", \"DELETE\", AVERAGE\", and \"QUIT\"" << endl;
  
  Node* head = NULL;
  char input[20];
  
  while (strcmp(input, "QUIT") != 0) {
    cout << ">> ";
    cin >> input;
    if (strcmp(input, "ADD") == 0) {
      char first[20];
      char last[20];
      int id;
      float gpa;
      cout << "First Name: ";
      cin >> first;
      cout << "Last Name: ";
      cin >> last;
      cout << "ID: ";
      cin >> id;
      cout << "GPA: ";
      cin >> gpa;
      Student* newStudent = new Student(first, last, id, gpa);
      if (head == NULL) {
	head = new Node(newStudent);
      } else {
	addStudent(head, newStudent);
      }
    } else if (strcmp(input, "PRINT") == 0) {
      printStudents(head);
    } else if (strcmp(input, "DELETE") == 0) {
      if (head == NULL) {
	cout << "There are no students to delete!" << endl;
      } else {
	int id;
	cout << "ID: ";
	cin >> id;
	deleteStudent(head, id);
      }
    } else if (strcmp(input, "AVERAGE") == 0) {
      float total;
      int numStudents;
      averageGPAs(head, total, numStudents);
    } else if (strcmp(input, "QUIT") != 0) { //anything else (besides quit) will be invalid
      cout << "Invalid command." << endl;
    }
  }
  cout << "Goodbye!" << endl;

  return 0;
}

//add a new node (holding a new student) to the linked list
void addStudent(Node* head, Student* newStudent) {
  Node* current = head;
  if (current->getNext() == NULL) {
    current->setNext(new Node(newStudent));
  } else {
    addStudent(head->getNext(), newStudent);
  }
}

//print out the student data of every node in the linked list
void printStudents(Node* next) {
  if (next != NULL) {
    cout << next->getStudent()->getFirst();
    cout << " " << next->getStudent()->getLast();
    cout << ", ID: " << next->getStudent()->getID();
    cout << ", GPA: " << next->getStudent()->getGPA() << endl;
    printStudents(next->getNext());
  }
}

//delete the node of the student with the given id
void deleteStudent(Node* current, int id) {
  if (current != NULL) {
    if (current->getNext()->getStudent()->getID() == id) {
      Node* temp = current->getNext();
      current->setNext(temp->getNext());
      delete(temp);
    } else {
      deleteStudent(current->getNext(), id);
    }
  } else {
    cout << "There is no student with that ID!" << endl;
  }
}

//average all the GPAs and print the value
void averageGPAs(Node* next, float total, int numStudents) {
  if (next != NULL) {
    total += next->getStudent()->getGPA();
    numStudents++;
    averageGPAs(next->getNext(), total, numStudents);
  } else {
    cout << total << endl;
    cout << numStudents << endl;
    cout << (total / float(numStudents)) << endl;
  }
}
