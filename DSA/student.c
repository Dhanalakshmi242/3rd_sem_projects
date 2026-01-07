#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    int id;
    char name[50];
    char dept[30];
    int sem;
    float marks;
    struct student *next;
};

struct student *head = NULL;

/* Add Student */
void addStudent() {
    struct student *newNode = (struct student *)malloc(sizeof(struct student));

    printf("Enter Student ID: ");
    scanf("%d", &newNode->id);

    printf("Enter Student Name: ");
    scanf(" %[^\n]", newNode->name);

    printf("Enter Department: ");
    scanf("%s", newNode->dept);

    printf("Enter Semester: ");
    scanf("%d", &newNode->sem);

    printf("Enter Marks: ");
    scanf("%f", &newNode->marks);

    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct student *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }

    printf("✅ Student added successfully!\n");
}

/* Display Students */
void displayStudents() {
    struct student *temp = head;

    if (temp == NULL) {
        printf("⚠ No student records found.\n");
        return;
    }

    printf("\nID\tName\t\tDept\tSem\tMarks\n");
    printf("-------------------------------------------------\n");

    while (temp != NULL) {
        printf("%d\t%s\t%s\t%d\t%.2f\n",
               temp->id, temp->name, temp->dept,
               temp->sem, temp->marks);
        temp = temp->next;
    }
}

/* Search Student */
void searchStudent() {
    int id;
    printf("Enter Student ID to search: ");
    scanf("%d", &id);

    struct student *temp = head;

    while (temp != NULL) {
        if (temp->id == id) {
            printf("✅ Student Found\n");
            printf("ID: %d\nName: %s\nDept: %s\nSem: %d\nMarks: %.2f\n",
                   temp->id, temp->name, temp->dept,
                   temp->sem, temp->marks);
            return;
        }
        temp = temp->next;
    }

    printf("❌ Student not found.\n");
}

/* Delete Student */
void deleteStudent() {
    int id;
    printf("Enter Student ID to delete: ");
    scanf("%d", &id);

    struct student *temp = head;
    struct student *prev = NULL;

    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("❌ Student not found.\n");
        return;
    }

    if (prev == NULL)
        head = temp->next;
    else
        prev->next = temp->next;

    free(temp);
    printf("✅ Student record deleted.\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n====== STUDENT MANAGEMENT SYSTEM ======\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Delete Student\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: deleteStudent(); break;
            case 5:
                printf("👋 Exiting program...\n");
                exit(0);
            default:
                printf("❌ Invalid choice! Try again.\n");
        }
    }
}
