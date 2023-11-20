//Dylan McIntee
//Dr. Steinberg
//COP 3223 Section 1
//Large Program 4

#include<stdio.h>
#include<string.h>
#include<ctype.h>

typedef struct{

    char name [30];
    double homeworkAvg;
    double quizAvg;
    double examAvg;

}student_t;

void clearBuffer();
void addStudent(student_t s[], int *ptr);
void removeStudent(student_t s[], int *ptr);
void updateGrade();
void printGrade();
void missingGrade();
void searchStudent();
void displayAll();
int greeting();

int main()
{
    student_t students[5];

    int numStudents = 0;

    int *ptrStudents = &numStudents;

    int choice = 0;

    printf("\nWelcome to the GradeBook!\n");

    printf("----------------------------------------------------------------------------\n");

    while(choice != 8)
    {
        choice = greeting();

        if(choice == 1)
        {
            addStudent(students, ptrStudents);

            printf("----------------------------------------------------------------------------\n");
        }
        else if(choice == 2)
        {
            removeStudent(students, ptrStudents);

            printf("----------------------------------------------------------------------------\n");
        }
        else if(choice == 3)
        {
            printf("----------------------------------------------------------------------------\n");
        }
        else if(choice == 4)
        {
            printf("----------------------------------------------------------------------------\n");
        }
        else if(choice == 5)
        {
            printf("----------------------------------------------------------------------------\n");
        }
        else if(choice == 6)
        {
            printf("----------------------------------------------------------------------------\n");
        }
        else if(choice == 7)
        {
            printf("----------------------------------------------------------------------------\n");
        }
        else if(choice == 8)
        {
            printf("----------------------------------------------------------------------------\n");
        }
        else
        {
            printf("\nInvalid Response!\n");
            printf("----------------------------------------------------------------------------\n");
        }
    }

    printf("Goodbye...\n\n");
    
    return 0;
}

void clearBuffer()
{
    while(getchar() != '\n');
}

void addStudent(student_t s[], int *ptr)
{
    char name[30];

    if(*ptr != 5)
    {
        printf("\nEnter the name of the student: ");

        clearBuffer();

        fgets(name, 30, stdin);

        strcpy(s[*ptr].name, name);

        *ptr = *ptr + 1;

        printf("\nStudent Added!\n");
    }
    else
    {
        printf("\nYour GradeBook is full!\n");
    }
}

void removeStudent(student_t s[], int *ptr)
{
    char name[30];

    int found = 0;

    printf("\nEnter the name of the student you want to remove: ");

    clearBuffer();

    fgets(name, 30, stdin);

    for(int i = 0; i < 5; i++)
    {
        if(strcmp(s[i].name, name) == 0)
        {
            for(int j = i; j < 5; j++)
            {
                s[j] = s[j + 1];
            }

            found = 1;

            *ptr = *ptr - 1;
        }
    }

    if(found == 1)
    {
        printf("\nStudent Removed!\n");
    }
    else
    {
        printf("\nStudent not Found!\n");
    }
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