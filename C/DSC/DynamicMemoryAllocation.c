#include <stdio.h>
#include <stdlib.h>
struct Time {
        int hour;
        int minute;
        int second;
        struct Time* next;
};
void displayTime(struct Time* t) {
        while (t != NULL) {
                printf("%02d:%02d:%02d\n", t->hour, t->minute, t->second);
                t = t->next;
        }
}
int main() {
        struct Time* time1 = (struct Time*)malloc(sizeof(struct Time));
        struct Time* time2 = (struct Time*)malloc(sizeof(struct Time));
        printf("Enter the first time (hour minute second): ");
        scanf("%d %d %d", &time1->hour, &time1->minute, &time1->second);
        printf("Enter the second time (hour minute second): ");
        scanf("%d %d %d", &time2->hour, &time2->minute, &time2->second);
        time1->next = time2;
        time2->next = NULL;
        printf("The times are:\n");
        displayTime(time1);
        free(time1);
        free(time2);
        return 0;
}
