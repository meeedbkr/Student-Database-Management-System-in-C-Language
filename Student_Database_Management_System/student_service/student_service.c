#include <stdio.h>
#include "student_service.h"

static LinkedList* studentsList = NULL;

void initializeStudentService() {
    studentsList = createLinkedList();
}

void cleanupStudentService() {
    destroyLinkedList(studentsList);
    studentsList = NULL;
}

void addStudentService() {
    Student newStudent;
    printf("Enter Student Name: ");
    scanf(" %[^\n]", newStudent.name);
    printf("Enter Roll Number: ");
    scanf("%d", &newStudent.rollNumber);
    printf("Enter Age: ");
    scanf("%d", &newStudent.age);
    printf("Enter Grade: ");
    scanf("%f", &newStudent.grade);

    insertNode(studentsList, &newStudent);
    printf("Student added successfully.\n");
}

void displayAllStudentsService() {
    displayLinkedList(studentsList);
}

void searchStudentService() {
    int rollNumber;
    printf("Enter Roll Number to search: ");
    scanf("%d", &rollNumber);

    Node* result = findNode(studentsList, rollNumber);
    if (result != NULL) {
        printf("Student Found:\n");
        printf("Name: %s, Roll Number: %d, Age: %d, Grade: %.2f\n",
               result->student.name, result->student.rollNumber, result->student.age, result->student.grade);
    } else {
        printf("Student not found.\n");
    }
}

void updateStudentService() {
    int rollNumber;
    printf("Enter Roll Number to update: ");
    scanf("%d", &rollNumber);

    Node* result = findNode(studentsList, rollNumber);
    if (result != NULL) {
        printf("Enter new Grade: ");
        scanf("%f", &result->student.grade);
        printf("Student information updated.\n");
    } else {
        printf("Student not found.\n");
    }
}

void deleteStudentService() {
    int rollNumber;
    printf("Enter Roll Number to delete: ");
    scanf("%d", &rollNumber);

    deleteNode(studentsList, rollNumber);
}

void saveToFileService() {
    char filename[100];
    printf("Enter the filename to save data: ");
    scanf(" %[^\n]", filename);

    saveToFile(studentsList, filename);
}

void loadFromFileService() {
    char filename[100];
    printf("Enter the filename to load data from: ");
    scanf(" %[^\n]", filename);

    cleanupStudentService();
    studentsList = loadFromFile(filename);
}
