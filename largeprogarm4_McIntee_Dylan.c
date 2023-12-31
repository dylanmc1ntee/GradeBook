//Dylan McIntee
//Dr. Steinberg
//COP 3223 Section 1
//Large Program 4

#include<stdio.h>
#include<string.h>
#include<ctype.h>

/* 
Creates a structure named student_t  
Inside the structure are 4 components
~The name of the student
~Their homework average
~Their quiz average
~Their exam average
*/
typedef struct{

    char name [30];
    double homeworkAvg;
    double quizAvg;
    double examAvg;

}student_t;

/*
These are the prototypes for all of the functions
*/
void clearBuffer();
void addStudent(student_t s[], int *ptr);
void removeStudent(student_t s[], int *ptr);
void updateGrade(student_t s[]);
void missingGrade(student_t s[], int *ptr);
void printGrade(student_t s[], int *ptr);
int greeting();
void outputText(student_t s[], int *ptr);

int main() //start of main function
{
    student_t students[5]; //initializes structure

    int numStudents = 0;

    int *ptrStudents = &numStudents; //points to numStudents

    int choice = 0;

    printf("\nWelcome to the GradeBook!\n");

    printf("----------------------------------------------------------------------------\n");

    /*
    This part of the function repeats while the user has not chosen 6
    */
    while(choice != 6) 
    {
        choice = greeting();

        /*
        Each of the if statements correspond to a button the user presses
        */
        if(choice == 1) //1
        {
            addStudent(students, ptrStudents);

            printf("----------------------------------------------------------------------------\n");
        }
        else if(choice == 2) //2
        {
            removeStudent(students, ptrStudents);

            printf("----------------------------------------------------------------------------\n");
        }
        else if(choice == 3) //3
        {
            updateGrade(students);

            printf("----------------------------------------------------------------------------\n");
        }
        else if(choice == 4) //4
        {
            missingGrade(students, ptrStudents);

            printf("----------------------------------------------------------------------------\n");
        }
        else if(choice == 5) //5
        {
            printGrade(students, ptrStudents);

            printf("----------------------------------------------------------------------------\n");
        }
        else if(choice == 6) //6
        {
            printf("----------------------------------------------------------------------------\n");
        }
        else //invalid input
        {
            printf("\nInvalid Response!\n");
            printf("----------------------------------------------------------------------------\n");
        }
    }

    outputText(students, ptrStudents);

    printf("Goodbye...\n\n");
    
    return 0; //end of main
}

/*
This clears the char buffer
*/
void clearBuffer()
{
    while(getchar() != '\n');
}

/*
This function adds 1 student to the gradebook
*/
void addStudent(student_t s[], int *ptr)
{
    char name[30];

    if(*ptr != 5) //if gradebook is not full
    {
        printf("\nEnter the name of the student: ");

        clearBuffer();

        fgets(name, 30, stdin);

        strcpy(s[*ptr].name, name); //copys name

        s[*ptr].homeworkAvg = 0.00; //sets to 0.00

        s[*ptr].quizAvg = 0.00; //sets to 0.00

        s[*ptr].examAvg = 0.00; //sets to 0.00

        *ptr = *ptr + 1; //adds 1 to student counter

        printf("\nStudent Added!\n");
    }
    else //if gradebook full
    {
        printf("\nYour GradeBook is full!\n");
    }
}

/*
This function removes 1 student from the gradebook
*/
void removeStudent(student_t s[], int *ptr)
{
    char name[30];

    int found = 0;

    printf("\nEnter the name of the student you want to remove: ");

    clearBuffer();

    fgets(name, 30, stdin);

    for(int i = 0; i < 5; i++) //repeat 5 times
    {
        if(strcmp(s[i].name, name) == 0) //if names match
        {
            for(int j = i; j < 5; j++) //removes
            {
                s[j] = s[j + 1];
            }

            found = 1; 

            *ptr = *ptr - 1; //student counter -1
        }
    }

    if(found == 1) //student removed
    {
        printf("\nStudent Removed!\n");
    }
    else //student not removed
    {
        printf("\nStudent not Found!\n");
    }
}

/*
This function updates the grades of 1 student
*/
void updateGrade(student_t s[])
{
    char name[30];

    int found = 6;

    printf("\nEnter the name of the student who's grade you want to update: ");

    clearBuffer();

    fgets(name, 30, stdin);

    for(int i = 0; i < 5; i++) //repeats 5 times
    {
        if(strcmp(s[i].name, name) == 0) //if names match
        {
            found = i;
        }
    }

    if(found == 6) //if student not found
    {
        printf("\nStudent not found!\n");
    }
    else //if found
    {
        /*
        This else statement asks the user to input the new grades of the student
        */
        printf("\nStudent found!\n");

        printf("\nEnter updated homework grade: ");

        scanf(" %lf", &s[found].homeworkAvg);

        printf("Enter updated quiz grade: ");

        scanf(" %lf", &s[found].quizAvg);

        printf("Enter updated exam grade: ");

        scanf(" %lf", &s[found].examAvg);
    }
}

/*
This function prints the names of all the students who are missing grades
*/
void missingGrade(student_t s[], int *ptr)
{
    printf("\nThe following students are missing grades: \n");

    for(int i = 0; i < *ptr; i++) //for number of students
    {
        if(s[i].homeworkAvg == 0.00 || s[i].quizAvg == 0.00 || s[i].examAvg == 0.00) //if something is missing
        {
            printf("\n");

            fputs(s[i].name, stdout);
        }
    }
}

/*
This function prints all the grades of every student in the gradebook
*/
void printGrade(student_t s[], int *ptr)
{
    printf("----------------------------------------------------------------------------\n");

    for(int i = 0; i < *ptr; i++) //for number of students
    {
        double weighted = (.5 * s[i].homeworkAvg); //calculate weighted avg

        weighted += (.2 * s[i].quizAvg);

        weighted += (.3 * s[i].examAvg);

        printf("Name: ");

        fputs(s[i].name, stdout);

        printf("\nHomework Average: %.2lf\n", s[i].homeworkAvg);

        printf("\nQuiz Average: %.2lf\n", s[i].quizAvg);

        printf("\nExam Average: %.2lf\n", s[i].examAvg);

        printf("\nWeighted Average: %.2lf\n", weighted);

        if(i != (*ptr - 1)) //if not last student
        {
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        }
    }
}

/*
This function displays the user all the choices that they can make and returns their choice
*/
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

/*
This function prints all of the grades onto a text file named gradebook.txt
*/
void outputText(student_t s[], int *ptr)
{
    FILE *outp = fopen("gradebook.txt", "w"); //create pointer

    for(int i = 0; i < *ptr; i++) //for number of students
    {
        double weighted = (.5 * s[i].homeworkAvg); //calculate weighted avg

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

    fclose(outp); //closes file
}