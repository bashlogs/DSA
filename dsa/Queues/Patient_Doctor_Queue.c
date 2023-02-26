#include <stdio.h>

#define MAX_PATIENTS 100
#define MAX_DOCTORS 10

int main() {
    // Initialize patient and doctor counters
    int num_patients = 0;
    int num_doctors = 5;
    
    // Initialize arrays to keep track of patient names and doctor availability
    char patient_names[MAX_PATIENTS][50];
    int doctor_availability[MAX_DOCTORS] = {0};
    
    while (1) {
        // Print menu options
        printf("1. Add patient\n");
        printf("2. Assign doctor\n");
        printf("3. View patient list\n");
        printf("4. View doctor availability\n");
        printf("5. Exit\n");
        
        // Get user input for menu choice
        int choice;
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: // Add patient
                if (num_patients >= MAX_PATIENTS) {
                    printf("Maximum number of patients reached.\n");
                } else {
                    printf("Enter patient name: ");
                    scanf("%s", patient_names[num_patients]);
                    printf("Patient %s added to the list.\n", patient_names[num_patients]);
                    num_patients++;
                }
                break;
            case 2: // Assign doctor
                if (num_doctors == 0) {
                    printf("No doctors available.\n");
                } else {
                    int assigned = 0;
                    for (int i = 0; i < num_doctors; i++) {
                        if (doctor_availability[i] == 0) {
                            doctor_availability[i] = 1;
                            printf("Patient %s assigned to doctor %d.\n", patient_names[assigned], i+1);
                            assigned++;
                            if (assigned == num_patients) {
                                break;
                            }
                        }
                    }
                    if (assigned < num_patients) {
                        printf("Not enough doctors available.\n");
                    }
                }
                break;
            case 3: // View patient list
                printf("Patient list:\n");
                for (int i = 0; i < num_patients; i++) {
                    printf("%d. %s\n", i+1, patient_names[i]);
                }
                break;
            case 4: // View doctor availability
                printf("Doctor availability:\n");
                for (int i = 0; i < num_doctors; i++) {
                    printf("Doctor %d: %s\n", i+1, doctor_availability[i] ? "Available" : "Not available");
                }
                break;
            case 5: // Exit
                return 0;
            default: // Invalid choice
                printf("Invalid choice.\n");
                break;
        }
    }
}
