/* Head blocks of Comment:
Yichen Huang CWID:11906882
This program use double link list to add the student names and their grade
In the student.c I use some helper function like createStudent, addStudent, findStudent, addGrade ,etc.
to help the main function and shorter the program length.

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "student.h" 


/////////////////////////////////////////////////////////////////////////////////////////////
// add a student to the list of students
//	   1. Make sure a student by that name does not exist (print an error message and do nothing if it exists)
//	   2. Add a new student with that name (add-at-front)
Student *createStudent (Student *head,char last[],char first[]) {
	Student *ptr = malloc(sizeof(Student));
	ptr->firstName = malloc (sizeof(char*));
	ptr->lastName = malloc (sizeof(char *)); 
	ptr->headGradeList = malloc(sizeof(Grade));
	strcpy(ptr->firstName,first);
	strcpy(ptr->lastName,last);
	ptr->headGradeList =NULL;
	ptr->next = head;
	return ptr;

}

Student* addStudent(Student *headStudentList, char last[], char first[])
{
	if (headStudentList==NULL) {
		Student *Nstudent= createStudent(headStudentList,last,first);
		return Nstudent;
	}
	else {
		for (Student *ptr=headStudentList;ptr!=NULL;ptr=ptr->next) {
			if ((strcmp(ptr->firstName,first)==0)&&(strcmp(ptr->lastName,last)==0)) {
				printf("\nError: Name: %s, %s exists!",last,first);
				return headStudentList;
			}
			
			
		}
		
		Student *Nstudent = createStudent(headStudentList,last,first);
		return  Nstudent;
		
	}
	return NULL;
}


/////////////////////////////////////////////////////////////////////////////////////////////
// add a grade to the specified student
//   1. Make sure a student by that name exists (so you can add grade to it)
//   2. If the specifed grade already exists, update the grade's value to the new value
//   3. Otherwise, add the grade to the end of the student's grade list (add-at-end)
Student *findStudent(Student *head,char Last[],char First[]) {
	for(Student *ptr=head;ptr!=NULL;ptr=ptr->next) {
		if ((strcmp(ptr->firstName,First)==0)&&(strcmp(ptr->lastName,Last)==0)) {
			//printf("Find it\n");
			return ptr;
		}
		
	}
	return NULL;
}
Grade *createGrade(Grade *head, char gradeName[],double value) {
	Grade *ptr = malloc(sizeof(Grade));
	strcpy(ptr->name,gradeName);
	ptr->value = value;
	ptr->next = head;
	return ptr;
}
Grade *findLastgrade (Grade *head) {
	for (Grade *ptr=head; ptr!=NULL; ptr=ptr->next) {
		if (ptr->next==NULL) {
			//printf("Find Last : %s.\n",ptr->name);
			return ptr;
		}
	}
	return NULL;
}
Grade *findGrade (Grade *head, char name[]) {
	for(Grade *ptr=head; ptr != NULL;ptr = ptr->next) {
		//printf("%s\n",ptr->name);
		if (strcmp(ptr->name,name)==0) {
			//printf("Grade exist.\n");
			return ptr;
		}
		else {
			//printf("Grade not exist.\n");
			//return NULL;
			
			
		}
	}
	//printf("Head is NULL.\n");
	return NULL;
}
void addGrade(Student *headStudentList, char last[], char first[], char gradeName[], double value) {
	Student *ptr = findStudent(headStudentList,last,first);
	if (ptr==NULL) { 
		printf("\nError, the student: %s, %s not exist!\n",last,first);
	}
	else {
		
		Grade *exist = findGrade(ptr->headGradeList,gradeName);
		if(exist != NULL) {
			exist->value = value;
		}
		else {
			Grade *Ngrade = createGrade(NULL,gradeName,value);
			Grade *Glast = findLastgrade(ptr->headGradeList);
			if (Glast ==NULL) {
				ptr->headGradeList = Ngrade;
			}
			else {
				Glast->next = Ngrade;
			}
		}
	}
	
}


/////////////////////////////////////////////////////////////////////////////////////////////
// return the number of students in the list
// Iterate through the student list to count the number of students, return that count

int count(Student *headStudentList) {
	int count=0;
	for (Student *ptr=headStudentList;ptr!=NULL;ptr=ptr->next) {
		count++;
	}
	return count;
	return 0;
}


/////////////////////////////////////////////////////////////////////////////////////////////
// print all the grades for a given student
//	1. Make sure a student with that name exists
//	2. Print the name of that student
//	3. Print all the "grade name: grade value" pairs for that student

void printStudent(Student *headStudentList, char last[], char first[])
{
	//printf("%s, %s\n",last,first);
	Student *sptr = findStudent(headStudentList,last,first);
	if(sptr == NULL) {
		printf("\nStudent Name: %s, %s not exist.\n",last,first);
	}
	else {
		printf("\nStudent Name: %s, %s\n",last,first);
		for(Grade *gptr = sptr->headGradeList;gptr != NULL;gptr = gptr->next) {
			
			printf("%3s : %4g\n",gptr->name,gptr->value);
		}
	}
	return;
}


/////////////////////////////////////////////////////////////////////////////////////////////
// print all the students
// For each student
//	   a. Print the name of that student
//	   b. Print all the "grade name: grade value" pairs for that student

void print(Student *headStudentList)
{
	if (headStudentList==NULL) {
		printf("\nThe list is Empty\n");
	}
	for(Student *ptr=headStudentList;ptr!=NULL;ptr=ptr->next) {
		printf("\nStudent Name: %s, %s\n",ptr->lastName,ptr->firstName);
		for(Grade *gptr = ptr->headGradeList;gptr != NULL;gptr = gptr->next) {
			printf("%3s : %4g\n",gptr->name,gptr->value);
		}
	}
	return;
}


/////////////////////////////////////////////////////////////////////////////////////////////
// add a student (in alphabetical order)
//	1. Make sure a student by that name does not exist 
//	2. Add a student with that name (add-in-order)
int compareStudent(Student *ptr1,Student *ptr2) {
	if (strcmp(ptr1->lastName,ptr2->lastName)<0) {
		return -1;
	}
	else if(strcmp(ptr1->lastName,ptr2->lastName)>0) {
		return 1;
	}
	else {
		if (strcmp(ptr1->firstName,ptr2->firstName)<0) {
			return -1;
		}
		else if (strcmp(ptr1->firstName,ptr2->firstName)>0) {
			return 1;
		}
		else {
			return 0;
		}
	}
	
}
Student *addStudentOrdered(Student *headStudentList, char last[], char first[])
{
	Student *sNew = createStudent(NULL,last,first);
	//case 1. Empty node
	if (headStudentList==NULL) {
		return sNew;
	}
	
	//case 2. name is at front
	if (compareStudent(sNew,headStudentList)<0) {
		sNew->next = headStudentList;
		return sNew;
	}
	else if (compareStudent(sNew,headStudentList)==0) {
		printf("\nError: The name %s, %s is existed!",last,first);
		return headStudentList;
	}
	for(Student *ptr=headStudentList;ptr!=NULL;ptr=ptr->next) {
		if (compareStudent(sNew,ptr)==0) {
			printf("\nError: The name %s, %s is existed!",last,first);
			return headStudentList;
		}
	}


	//search
	for(Student *ptr=headStudentList;ptr!=NULL;ptr=ptr->next) {
		//case 3. At last
		if (ptr->next == NULL) {
			ptr->next = sNew;
			return headStudentList;
		}
		//case 4. middle
		if (compareStudent(sNew,ptr->next)<0) {
			sNew->next = ptr->next;
			ptr->next = sNew;
			return headStudentList;
		}
	 
	}


	


	return NULL;
}


/////////////////////////////////////////////////////////////////////////////////////////////
// adds a grade to the specified student in order
//	1. Make sure a student by that name exists (so you can add a grade to the student)
//	2. If the grade already exists, update the value
//	3. Otherwise, add the grade to the student (add-in-order)
int compareGrade (Grade *ptr1,Grade *ptr2) {
	if (ptr1->name[0] < ptr2->name[0]) {
		//printf("Letter\n");
		return -1;
	}
	else if (ptr1->name[0] > ptr2->name[0]) {
		return 1;
	}
	else {
		if (atoi(ptr1->name+1) < atoi(ptr2->name+1)) {
			//printf("Number;");
			return -1;
		}
		else if (atoi(ptr1->name+1) > atoi(ptr2->name+1)) {
			return 1;
		}
		else {
			//printf("Equal\n");
			return 0;
		}
	}
	return 0;

}

void addGradeOrdered(Student *headStudentList, char last[], char first[], char gradeName[], double value)
{
	Student *ptr = findStudent(headStudentList,last,first);
	if (ptr==NULL) { 
		printf("\nError, the student: %s, %s not exist!\n",last,first);
	}
	else {
		
		Grade *gNew = createGrade(NULL,gradeName,value);
		//1. Empty node
		if (ptr->headGradeList == NULL) {
			//printf("Empty\n");
			ptr->headGradeList= gNew;
				return;
		}
		//2. grade is at front
		if (compareGrade(gNew, ptr->headGradeList)<0) {
			//printf("Front\n");
			gNew->next = ptr->headGradeList;
			ptr->headGradeList = gNew;
			return;
		}
		else if (compareGrade(gNew,ptr->headGradeList)==0) {
			//printf("The grade has exist\n");
			ptr->headGradeList->value = value;
			return;
		}
		for(Grade *gptr= ptr->headGradeList;gptr!=NULL;gptr=gptr->next) {
			if (compareGrade(gNew,gptr)==0) {
				//printf("The grade has exist\n");
				gptr->value = value;
				return;
			}
		}

			//search
		for(Grade *gptr = ptr->headGradeList;gptr!=NULL;gptr=gptr->next) {
			//case 3. At Last
			if (gptr->next == NULL) {
				//printf("At Last\n");
				gptr->next = gNew;
				return;
			}
			//case 4.middle
			if (compareGrade(gNew,gptr->next)<0) {
				//printf("Middle\n");
				gNew->next = gptr->next;
				gptr->next = gNew;
				return;
			}
		}


		
	}

	return;
}


/////////////////////////////////////////////////////////////////////////////////////////////
// remove a grade from a student
//	1. Make sure a student with that name exists
//	2. Make sure the grade exists in that student
//	3. Remove the grade from that student
Grade *deleteGrade (Grade *head, char gradeName[]) {
	Grade *gptr = findGrade(head,gradeName);
	if (gptr==NULL) {
		printf("\nError, the grade %s not exist\n",gradeName);
		return head;
	}
	
		// 1st Node
	if (strcmp(head->name,gradeName)==0) {
		Grade *gdelete = head;
		head = head->next;
		free(gdelete);
		return head;
	}
	else {
		//search
		for (Grade *ptr = head;ptr!=NULL;ptr=ptr->next) {
			if (strcmp(gradeName,ptr->next->name)==0) {
				Grade *gdelete = ptr->next;
				ptr->next = ptr->next->next;
				free(gdelete);
				return head;
			}
		}
	}


	return NULL;
}
void removeGrade(Student *headStudentList, char last[], char first[], char gradeName[])
{
	Student *sptr = findStudent(headStudentList,last,first);
	if (sptr == NULL) {
		printf("\nError, the student %s, %s not exist\n",last,first);
		return;
	}
	else {
	sptr->headGradeList = deleteGrade(sptr->headGradeList,gradeName);
	return;
	
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////
// remove a student
//	1. Make sure a student with that name exists
//	2. Remove that student and all the grades of that student 

Student *removeStudent(Student *headStudentList, char last[], char first[])
{
	Student *sptr = findStudent (headStudentList,last,first);
	if (sptr==NULL) {
		printf("\nError, The student %s, %s not exist\n",last,first);
		return headStudentList;
	}
	for (Grade *ptr= sptr->headGradeList;ptr!=NULL;ptr=ptr->next) {
		Grade *gdelete = ptr;
		free(gdelete);
	}

	// 1st Node
	if (strcmp(headStudentList->firstName,first)==0 && strcmp(headStudentList->lastName,last)==0) {
		Student *sdelete = headStudentList;
		headStudentList = headStudentList->next;
		free(sdelete);
		return headStudentList;
	}
	else {
		//search
		for(Student *ptr = headStudentList;ptr!=NULL;ptr=ptr->next) {
			if (strcmp(ptr->next->firstName,first)==0 && strcmp(ptr->next->lastName,last)==0) {
				Student *sdelete = ptr->next;
				ptr->next = ptr->next->next;
				//free(sdelete->headGradeList);
				
				free(sdelete);
				return headStudentList;
			}
		}
	}

	return NULL;
}
