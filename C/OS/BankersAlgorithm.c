#include <stdio.h>
#define MAX_PROCESSES 10
#define MAX_RESOURCES 10

struct Process {
        int max[MAX_RESOURCES];
        int allocated[MAX_RESOURCES];
        int need[MAX_RESOURCES];
};

int isSafe(int processes, int resources, struct Process proc[], int available[]) {
        int work[MAX_RESOURCES];
        int finish[MAX_PROCESSES] = {0};
        int safeSeq[MAX_PROCESSES];
        int count = 0;

        for (int i = 0; i < resources; i++)
                work[i] = available[i];

        while (count < processes) {
                int found = 0;
                for (int p = 0; p < processes; p++) {
                        if (!finish[p]) {
                                int j;
                                for (j = 0; j < resources; j++)
                                        if (proc[p].need[j] > work[j])
                                                break;
                                if (j == resources) {
                                        for (int k = 0; k < resources; k++)
                                                work[k] += proc[p].allocated[k];
                                safeSeq[count++] = p;
                                finish[p] = 1;
                                found = 1;
                        }
                }
        }
        if (!found)
                return 0;
        }

        printf("Safe sequence is: ");
        for (int i = 0; i < processes; i++)
                printf("P%d ", safeSeq[i]);
        printf("\n");
        return 1;
}

int main() {
        int processes, resources;
        struct Process proc[MAX_PROCESSES];
        int available[MAX_RESOURCES];
        printf("Enter the number of processes: ");
        scanf("%d", &processes);
        printf("Enter the number of resources: ");
        scanf("%d", &resources);
        for (int i = 0; i < processes; i++) {
                printf("Process P%d\n", i + 1);
                for (int j = 0; j < resources; j++) {
                        printf("Max resources for R%d: ", j + 1);
                        scanf("%d", &proc[i].max[j]);
                }
        }

        for (int i = 0; i < processes; i++) {
                for (int j = 0; j < resources; j++) {
                        printf("Allocated resources for R%d in P%d: ", j + 1, i + 1);
                        scanf("%d", &proc[i].allocated[j]);
                        proc[i].need[j] = proc[i].max[j] - proc[i].allocated[j];
                }
        }

        int total[MAX_RESOURCES];
        for (int i = 0; i < resources; i++) {
                printf("Total resources for R%d: ", i + 1);
                scanf("%d", &total[i]);
        }
        for (int i = 0; i < resources; i++) {
                int allocated = 0;
                for (int j = 0; j < processes; j++)
                        allocated += proc[j].allocated[i];
                available[i] = total[i] - allocated;
        }

        if (isSafe(processes, resources, proc, available))
                printf("The system is in a safe state.\n");
        else
                printf("The system is in an unsafe state.\n");
        return 0;
}
