#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
 #include <stdint.h>
typedef struct student {
    char name[20];
    uint16_t enrolledYear;
    uint8_t yearsCompleted;
    struct student *next;
} student;

void setupStudentWithYear(student *student, const char *name, uint16_t enrolledYear) {
    student->enrolledYear = enrolledYear;
    strncpy(student->name, name, 19);
    student->yearsCompleted = 0;
}

void advanceStudent(student *student) {
    student->yearsCompleted++;
}

int countStudents(const student *head) {
    int count = 0;
    const student *current = head;

    while (current != NULL) {
        count++;
        current = current->next;
    }

    return count;
}

void addStudent(student *newStudent, student *head) {
    student *current = head;

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newStudent;
    newStudent->next = NULL;
}

int main() {
    student mrValue, *msDynamic, *custom;

    // Setting up mrValue
    setupStudentWithYear(&mrValue, "Mr. Value", 2020);

    // Setting up msDynamic
    msDynamic = (student *)malloc(sizeof(student));
    setupStudentWithYear(msDynamic, "Ms. Dynamic", 2021);

    // Setting up custom
    custom = (student *)malloc(sizeof(student));
    char nameBuffer[40];
    char yearBuffer[6];
    uint16_t enyear;
    bool inputOk = false;

    puts("Enter a name: ");
    fgets(nameBuffer, 40, stdin);
    fflush(stdin);

    puts("Enter an enrollment year: ");
    while (!inputOk) {
        fgets(yearBuffer, 6, stdin);
        char *endCheck;
        enyear = (uint16_t)strtol(yearBuffer, &endCheck, 0);

        if (endCheck == (yearBuffer + strlen(yearBuffer))) {
            inputOk = true;
        } else {
            puts("That wasn't a valid year.");
        }

        fflush(stdin);
    }

    setupStudentWithYear(custom, nameBuffer, enyear);

    // Creating a linked list
    mrValue.next = msDynamic;
    msDynamic->next = custom;
    custom->next = NULL;

    // Counting the number of students
    int studentCount = countStudents(&mrValue);
    printf("Number of students: %d\n", studentCount);

    // Advancing all students
    student *current = &mrValue;
    while (current != NULL) {
        advanceStudent(current);
        current = current->next;
    }

    // Adding a new student to the linked list
    student *newStudent = (student *)malloc(sizeof(student));
    setupStudentWithYear(newStudent, "New Student", 2023);
    addStudent(newStudent, &mrValue);

    // Freeing dynamically allocated memory
    free(msDynamic);
    free(custom);
    free(newStudent);

    return 0;
}
