//Creator: Andy Fleischer
//Date: 10/30/20
//Main class for project

#include "Node.h"
#include <iostream>
#include <iomanip>
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
    if (strcmp(input, "ADD") == 0) { //get data, add directly if empty list, otherwise call function
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
      } else if (head->getStudent()->getID() > id) {
	Node* temp = head;
	head = new Node(newStudent);
	head->setNext(temp);
      }
      else {
	addStudent(head, newStudent);
      }
    } else if (strcmp(input, "PRINT") == 0) { //call print function
      printStudents(head);
    } else if (strcmp(input, "DELETE") == 0) { //do not delete if empty, if head is the match, adjust here, otherwise call delete function
      if (head == NULL) {
	cout << "There are no students to delete!" << endl;
      } else {
	int id;
	cout << "ID: ";
	cin >> id;

	if (head->getStudent()->getID() == id) {
	  Node* temp = head;
	  head = head->getNext();
	  delete(temp);
	} else {
	  deleteStudent(head, id);
	}
      }
    } else if (strcmp(input, "AVERAGE") == 0) { //call average function
      float total = 0;
      int numStudents = 0;
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
  if (current->getNext() == NULL || current->getNext()->getStudent()->getID() > newStudent->getID()) { //once at the end, connect the last node to new node
    Node* newNode = new Node(newStudent);
    newNode->setNext(current->getNext());
    current->setNext(newNode);
    
  } else { //recursively search
    addStudent(head->getNext(), newStudent);
  }
}

//print out the student data of every node in the linked list
void printStudents(Node* next) {
  if (next != NULL) { //while not at the end, print all the data per node then call on next
    cout << next->getStudent()->getFirst();
    cout << " " << next->getStudent()->getLast();
    cout << ", ID: " << next->getStudent()->getID();
    cout << ", GPA: " << fixed << setprecision(2) << next->getStudent()->getGPA() << endl;
    printStudents(next->getNext());
  }
}

//delete the node of the student with the given id
void deleteStudent(Node* current, int id) {
  if (current->getNext() != NULL) { //search the next node's data (as long as it is not NULL)
    if (current->getNext()->getStudent()->getID() == id) {
      Node* temp = current->getNext();
      current->setNext(temp->getNext());
      delete(temp);
    } else { //recursively search only if no match
      deleteStudent(current->getNext(), id);
    }
  } else { //could not find match
    cout << "There is no student with that ID!" << endl;
  }
}

//average all the GPAs and print the value
void averageGPAs(Node* next, float total, int numStudents) {
  if (next != NULL) { //recursively get to the end and sum all the GPAs and tally the # of students
    total += next->getStudent()->getGPA();
    numStudents++;
    averageGPAs(next->getNext(), total, numStudents);
  } else { //once finished, either print there are no students or print the average GPA
    if (numStudents == 0) {
      cout << "There are no students to average!" << endl;
    } else {
      cout << fixed << setprecision(2) << (total / numStudents) << endl;
    }
  }
}
