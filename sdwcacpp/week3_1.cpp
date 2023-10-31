#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Student {
    char name[20];
    int enrolledYear;
    int yearsCompleted;
    struct Student* next;
} Student;

void setupStudent(Student* student, const char* name, int enrolledYear) {
    student->enrolledYear = enrolledYear;
    strncpy(student->name, name, sizeof(student->name) - 1);
    student->name[sizeof(student->name) - 1] = '\0';
    student->yearsCompleted = 0; // Initialize yearsCompleted to zero
    student->next = NULL; // Set next to NULL
}

void advanceStudent(Student* student) {
    student->yearsCompleted++;
}

int getEnrollmentYear() {
    bool inputOk = false;
    int enrolledYear = 0;
    char yearBuffer[5];

    while (!inputOk) {
        puts("Enter an enrollment year: ");
        fgets(yearBuffer, sizeof(yearBuffer), stdin);
        fflush(stdin);

        char* endCheck;
        enrolledYear = (int)strtol(yearBuffer, &endCheck, 0);

        if (endCheck == (yearBuffer + strlen(yearBuffer))) {
            inputOk = true;
        } else {
            puts("That wasn't a valid enrollment year.");
        }
    }

    return enrolledYear;
}

int countStudents(Student* head) {
    int count = 0;
    Student* current = head;

    while (current != NULL) {
        count++;
        current = current->next;
    }

    return count;
}

void addStudent(Student** head, Student* newStudent) {
    if (*head == NULL) {
        *head = newStudent;
    } else {
        Student* current = *head;

        while (current->next != NULL) {
            current = current->next;
        }

        current->next = newStudent;
    }
}

int main() {
    Student* head = NULL; // Initialize the head of the linked list

    Student* mrValue = (Student*)malloc(sizeof(Student));
    setupStudent(mrValue, "Mr Value", 2017);
    addStudent(&head, mrValue);

    Student* msDynamic = (Student*)malloc(sizeof(Student));
    setupStudent(msDynamic, "Ms Dynamic", 2017);
    addStudent(&head, msDynamic);

    char nameBuffer[40];
    puts("Enter a name: ");
    fgets(nameBuffer, sizeof(nameBuffer), stdin);
    fflush(stdin);

    int enrolledYear = getEnrollmentYear();

    Student* custom = (Student*)malloc(sizeof(Student));
    setupStudent(custom, nameBuffer, enrolledYear);
    addStudent(&head, custom);

    // Traverse the linked list and print the student information
    Student* current = head;

    while (current != NULL) {
        printf("Name: %s\n", current->name);
        printf("Enrollment Year: %d\n", current->enrolledYear);
        printf("Years Completed: %d\n", current->yearsCompleted);

        current = current->next; // Move to the next student
    }

    // Count the number of students in the linked list
    int studentCount = countStudents(head);
    printf("Number of students: %d\n", studentCount);

    // Free the dynamically allocated memory
    current = head;

    while (current != NULL) {
        Student* nextStudent = current->next;
        free(current);
        current = nextStudent;
    }

    return 0;
}
