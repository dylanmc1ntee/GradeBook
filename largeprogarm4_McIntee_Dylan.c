//Dylan McIntee
//Dr. Steinberg
//COP 3223 Section 1
//Large Program 4

#include<stdio.h>
#include<string.h>
#include<ctype.h>

typedef struct{

    char name [30];
    int id;
    double homeworkAvg;
    double quizAvg;
    double examAvg;
    double weightedAvg;

}student_t;

void addStudent();
void removeStudent();
void updateGrade();
void printGrade();
void missingGrade();
void searchStudent();
void displayAll();
int greeting();

int main()
{
    int choice = 0;

    printf("\nWelcome to the GradeBook!\n");

    printf("----------------------------------------------------------------------------\n");

    while(choice != 8)
    {
        choice = greeting();
    }
    
    return 0;
}

void addStudent()
{

}

void removeStudent()
{

}

void updateGrade()
{

}

void printGrade()
{

}

void missingGrade()
{

}

void searchStudent()
{
    
}

void displayAll()
{

}

int greeting()
{
    int choice;

    printf("Please choose an action...\n");
    printf("1 ~ Add a Student\n");
    printf("2 ~ Remove a Student\n");
    printf("3 ~ Print all Grades\n");
    printf("4 ~ Update Grades\n");
    printf("5 ~ Find Missing Grades\n");
    printf("6 ~ Student Search\n");
    printf("7 ~ View all Students\n");
    printf("8 ~ Exit\n");

    printf("----------------------------------------------------------------------------\n");

    printf("Choice: ");

    scanf(" %d", &choice);

    return choice;
}