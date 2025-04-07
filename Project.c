#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a student record
struct Student {
    int id;
    char name[50];
    float marks;
    struct Student* next;
};

struct Student* head = NULL;

// Function to add a new student record
void addStudent(int id, char name[], float marks) {
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
    newStudent->id = id;
    strcpy(newStudent->name, name);
    newStudent->marks = marks;
    newStudent->next = head;
    head = newStudent;
    printf("Student record added successfully!\n");
}

// Function to display all student records
void displayStudents() {
    struct Student* temp = head;
    if (temp == NULL) {
        printf("No student records found.\n");
        return;
    }
    printf("\nStudent Records:\n");
    printf("ID\tName\t\tMarks\n");
    while (temp != NULL) {
        printf("%d\t%s\t%.2f\n", temp->id, temp->name, temp->marks);
        temp = temp->next;
    }
}

// Function to search for a student by ID
void searchStudent(int id) {
    struct Student* temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            printf("Student Found: ID: %d, Name: %s, Marks: %.2f\n", temp->id, temp->name, temp->marks);
            return;
        }
        temp = temp->next;
    }
    printf("Student with ID %d not found.\n", id);
}

// Function to update a student record
void updateStudent(int id, float newMarks) {
    struct Student* temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            temp->marks = newMarks;
            printf("Student record updated successfully!\n");
            return;
        }
        temp = temp->next;
    }
    printf("Student with ID %d not found.\n", id);
}

// Function to delete a student record
void deleteStudent(int id) {
    struct Student* temp = head, *prev = NULL;
    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Student with ID %d not found.\n", id);
        return;
    }
    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
    printf("Student record deleted successfully!\n");
}

int main() {
    int choice, id;
    char name[50];
    float marks;

    do {
        printf("\nStudent Record Management System\n");
        printf("1. Add Student\n2. Display Students\n3. Search Student\n4. Update Student\n5. Delete Student\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Marks: ");
                scanf("%f", &marks);
                addStudent(id, name, marks);
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                printf("Enter ID to search: ");
                scanf("%d", &id);
                searchStudent(id);
                break;
            case 4:
                printf("Enter ID to update: ");
                scanf("%d", &id);
                printf("Enter new Marks: ");
                scanf("%f", &marks);
                updateStudent(id, marks);
                break;
            case 5:
                printf("Enter ID to delete: ");
                scanf("%d", &id);
                deleteStudent(id);
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);
    
    return 0;
}
