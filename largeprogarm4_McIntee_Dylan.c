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
void updateGrade(student_t s[]);
void missingGrade(student_t s[], int *ptr);
void printGrade(student_t s[], int *ptr);
int greeting();
void outputText(student_t s[], int *ptr);

int main()
{
    student_t students[5];

    int numStudents = 0;

    int *ptrStudents = &numStudents;

    int choice = 0;

    printf("\nWelcome to the GradeBook!\n");

    printf("----------------------------------------------------------------------------\n");

    while(choice != 6)
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
            updateGrade(students);

            printf("----------------------------------------------------------------------------\n");
        }
        else if(choice == 4)
        {
            missingGrade(students, ptrStudents);

            printf("----------------------------------------------------------------------------\n");
        }
        else if(choice == 5)
        {
            printGrade(students, ptrStudents);

            printf("----------------------------------------------------------------------------\n");
        }
        else if(choice == 6)
        {
            printf("----------------------------------------------------------------------------\n");
        }
        else
        {
            printf("\nInvalid Response!\n");
            printf("----------------------------------------------------------------------------\n");
        }
    }

    outputText(students, ptrStudents);

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

        s[*ptr].homeworkAvg = 0.00;

        s[*ptr].quizAvg = 0.00;

        s[*ptr].examAvg = 0.00;

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

void updateGrade(student_t s[])
{
    char name[30];

    int found = 6;

    printf("\nEnter the name of the student who's grade you want to update: ");

    clearBuffer();

    fgets(name, 30, stdin);

    for(int i = 0; i < 5; i++)
    {
        if(strcmp(s[i].name, name) == 0)
        {
            found = i;
        }
    }

    if(found == 6)
    {
        printf("\nStudent not found!\n");
    }
    else
    {
        printf("\nStudent found!\n");

        printf("\nEnter updated homework grade: ");

        scanf(" %lf", &s[found].homeworkAvg);

        printf("Enter updated quiz grade: ");

        scanf(" %lf", &s[found].quizAvg);

        printf("Enter updated exam grade: ");

        scanf(" %lf", &s[found].examAvg);
    }
}

void missingGrade(student_t s[], int *ptr)
{
    printf("\nThe following students are missing grades: \n");

    for(int i = 0; i < *ptr; i++)
    {
        if(s[i].homeworkAvg == 0.00 || s[i].quizAvg == 0.00 || s[i].examAvg == 0.00)
        {
            printf("\n");

            fputs(s[i].name, stdout);
        }
    }
}

void printGrade(student_t s[], int *ptr)
{
    printf("----------------------------------------------------------------------------\n");

    for(int i = 0; i < *ptr; i++)
    {
        double weighted = (.5 * s[i].homeworkAvg);

        weighted += (.2 * s[i].quizAvg);

        weighted += (.3 * s[i].examAvg);

        printf("Name: ");

        fputs(s[i].name, stdout);

        printf("\nHomework Average: %.2lf\n", s[i].homeworkAvg);

        printf("\nQuiz Average: %.2lf\n", s[i].quizAvg);

        printf("\nExam Average: %.2lf\n", s[i].examAvg);

        printf("\nWeighted Average: %.2lf\n", weighted);

        if(i != (*ptr - 1))
        {
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        }
    }
}

int greeting()
{
    int choice;

    printf("Please choose an action...\n");
    printf("1 ~ Add a Student\n");
    printf("2 ~ Remove a Student\n");
    printf("3 ~ Update Grades\n");
    printf("4 ~ Find Missing Grades\n");
    printf("5 ~ Print All Grades\n");
    printf("6 ~ Exit\n");

    printf("----------------------------------------------------------------------------\n");

    printf("Choice: ");

    scanf(" %d", &choice);

    return choice;
}

void outputText(student_t s[], int *ptr)
{
    FILE *outp = fopen("gradebook.txt", "w");

    for(int i = 0; i < *ptr; i++)
    {
        double weighted = (.5 * s[i].homeworkAvg);

        weighted += (.2 * s[i].quizAvg);

        weighted += (.3 * s[i].examAvg);

        fprintf(outp, "Name: ");

        fputs(s[i].name, outp);

        fprintf(outp, "\nHomework Average: %.2lf\n", s[i].homeworkAvg);

        fprintf(outp, "\nQuiz Average: %.2lf\n", s[i].quizAvg);

        fprintf(outp, "\nExam Average: %.2lf\n", s[i].examAvg);

        fprintf(outp, "\nWeighted Average: %.2lf\n", weighted);

        fprintf(outp, "----------------------------------------------------------------------------\n");
    }

    fclose(outp);
}