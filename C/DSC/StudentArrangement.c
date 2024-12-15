#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int id;
    float marks[3];
    float avg;
};

float totalMarks(float marks[], int size) {
    float total = 0;
    for (int i = 0; i < size; i++) {
        total += marks[i];
    }
    return total;
}

void sortStudents(struct Student students[], int n) {
    struct Student temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (totalMarks(students[i].marks, 3) < totalMarks(students[j].marks, 3)) {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    struct Student students[n];

    for (int i = 0; i < n; i++) {
        printf("Enter details for student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("ID: ");
        scanf("%d", &students[i].id);
        printf("Enter marks for 3 subjects: ");
        for (int j = 0; j < 3; j++) {
            scanf("%f", &students[i].marks[j]);
        }
        students[i].avg = totalMarks(students[i].marks, 3) / 3;
    }

    sortStudents(students, n);

    printf("\nStudent details in descending order of total marks:\n");
    for (int i = 0; i < n; i++) {
        printf("Name: %s, ID: %d, Marks: %.2f, %.2f, %.2f, Average: %.2f\n",
               students[i].name, students[i].id,
               students[i].marks[0], students[i].marks[1], students[i].marks[2],
               students[i].avg);
    }

    return 0;
}
