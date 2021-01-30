#ifndef _STUDENT_H_
#define _STUDENT_H_

typedef struct _grade {
	char name[4];
	double value;
	struct _grade *next;
} Grade;

////////////////////////////////////////////////////////////////////////////////////////

typedef struct _student {
	char *lastName;
	char *firstName;
	Grade *headGradeList;
	struct _student *next;
} Student;

////////////////////////////////////////////////////////////////////////////////////////

Student* addStudent(Student *headStudentList, char last[], char first[]);
void addGrade(Student *headStudentList, char last[], char first[], char gradeName[], double value);
int count(Student *headStudentList);
void printStudent(Student *headStudentList, char last[], char first[]);
void print(Student *headStudentList);
Student *addStudentOrdered(Student *headStudentList, char last[], char first[]);
void addGradeOrdered(Student *headStudentList, char last[], char first[], char gradeName[], double value);
void removeGrade(Student *headStudentList, char last[], char first[], char gradeName[]);
Student *removeStudent(Student *headStudentList, char last[], char first[]);

////////////////////////////////////////////////////////////////////////////////////////

#endif
