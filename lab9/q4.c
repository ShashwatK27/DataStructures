#include <stdio.h>
#include <string.h>
#include <stdlib.h>




typedef struct {
    char name[50];
    int age;
    char gender[10];
    int waitingNumber;
} Patient;

Patient queue[100];
int totalPatients = 0;


void addPatient() {
    if (totalPatients >= 100) {
        printf("The queue is full. Cannot add more patients.\n");
        return;
    }

    Patient newPatient;

    printf("\nEnter patient's name: ");
    scanf(" %[^\n]", newPatient.name);

    printf("Enter age: ");
    scanf("%d", &newPatient.age);

    printf("Enter gender: ");
    scanf(" %s", newPatient.gender);

    newPatient.waitingNumber = totalPatients + 1;
    queue[totalPatients++] = newPatient;

    printf("Patient added! Waiting Number: %d\n", newPatient.waitingNumber);
}


void examinePatient() {
    if (totalPatients == 0) {
        printf("\nNo patients to examine.\n");
        return;
    }

    printf("\nNow examining: %s (Waiting Number: %d)\n",
           queue[0].name, queue[0].waitingNumber);

    
    for (int i = 1; i < totalPatients; i++) {
        queue[i - 1] = queue[i];
        queue[i - 1].waitingNumber--;
    }

    totalPatients--;
}


void displayQueue() {
    if (totalPatients == 0) {
        printf("\nNo patients in the queue.\n");
        return;
    }

    printf("\nCurrent Patients in Queue:\n");
    for (int i = 0; i < totalPatients; i++) {
        printf("Waiting Number: %d | Name: %s | Age: %d | Gender: %s\n",
               queue[i].waitingNumber, queue[i].name,
               queue[i].age, queue[i].gender);
    }
}


int main() {
    int choice;

    while (1) {
        printf("\n Hospital Queue System \n");
        printf("1. Add Patient\n");
        printf("2. Examine Next Patient\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPatient();
                break;
            case 2:
                examinePatient();
                break;
            case 3:
                displayQueue();
                break;
            case 4:
                printf("Exiting... Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}



