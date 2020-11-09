//Creator: Andy Fleischer
//Date: 10/30/20
//Header for Student class

class Student {
 public:
  char* getFirst();
  char* getLast();
  int getID();
  float getGPA();

  Student(char* newFirst, char* newLast, int newID, float newGPA);
  ~Student();
  
 private:
  char first[20];
  char last[20];
  int id;
  float gpa;
};
