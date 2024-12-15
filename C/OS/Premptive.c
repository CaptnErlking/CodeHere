#include <stdio.h>
#include <stdbool.h>
struct Process {
        int id, burstTime, priority;
};
void sortProcesses(struct Process p[], int n) {
        for (int i = 0; i < n - 1; i++) {
                for (int j = 0; j < n - i - 1; j++) {
                        if (p[j].priority > p[j + 1].priority) {
                        struct Process temp = p[j];
                        p[j] = p[j + 1];
                        p[j + 1] = temp;
                        }
                }
        }
}
int main() {
        int n;
        printf("Enter number of processes: ");
        scanf("%d", &n);
        struct Process p[n];
        for (int i = 0; i < n; i++) {
                printf("Enter burst time and priority for process %d: ", i + 1);
                scanf("%d %d", &p[i].burstTime, &p[i].priority);
                p[i].id = i + 1;
        }
        sortProcesses(p, n);
        int completionTime[n], waitingTime[n], turnaroundTime[n];
        int currentTime = 0;
        int completedCount = 0;
        for(int i = 0; i < n; i++){
                completionTime[i] = currentTime + p[i].burstTime;
                turnaroundTime[i] = completionTime[i];
                waitingTime[i] = turnaroundTime[i] - p[i].burstTime;
                currentTime += p[i].burstTime;
        }
        float avgWaitingTime = 0, avgTurnaroundTime = 0;
        for (int i = 0; i < n; i++) {
                avgWaitingTime += waitingTime[i];
                avgTurnaroundTime += turnaroundTime[i];
        }
        avgWaitingTime /= n;
        avgTurnaroundTime /= n;
        printf("\nProcess ID\tBurst Time\tPriority\tCompletion Time\tTurnaround Time\tWaiting Time\n");
        for (int i = 0; i < n; i++) {
                printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
                p[i].id, p[i].burstTime, p[i].priority,
                completionTime[i], turnaroundTime[i], waitingTime[i]);
        }
        printf("\nAverage Waiting Time: %.2f", avgWaitingTime);
        printf("\nAverage Turnaround Time: %.2f", avgTurnaroundTime);
        printf("\n\nGantt Chart:\n");
        for (int i = 0; i < n; i++) {
                printf("| P%d\t", p[i].id);
        }
        printf("|\n");
        printf("0 ");
        for (int i = 0; i < n; i++) {
                printf("  %d\t", completionTime[i]);
        }
        printf("\n");
        return 0;
}
