#include <stdio.h>
#include <string.h>

// Define a structure for a student
typedef struct {
    char name[50];
    int roll;
    char division;
} Student;

int main() {
    int n, i;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    Student students[n];
    printf("Enter details of each student:\n");
    for (i = 0; i < n; i++) {
        printf("Student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Roll number: ");
        scanf("%d", &students[i].roll);
        printf("Division: ");
        scanf(" %c", &students[i].division);
    }
    char target_name[] = "XYZ";
    int target_roll = 17;
    char target_division = 'X';
    int found = 0;
    for (i = 0; i < n; i++) {
        if (strcmp(students[i].name, target_name) == 0
            && students[i].roll == target_roll
            && students[i].division == target_division) {
            printf("Found the student!\n");
            printf("Name: %s\n", students[i].name);
            printf("Roll number: %d\n", students[i].roll);
            printf("Division: %c\n", students[i].division);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Could not find the student.\n");
    }
    return 0;
}
