#include <stdio.h>

#define MAX_PAGES 50
#define MAX_FRAMES 20

int main() {
        int referenceString[MAX_PAGES], frames[MAX_FRAMES];
        int pageFaults = 0, n, numFrames, i, j, k, leastUsedIndex, pageFound;

        printf("Enter the number of pages: ");
        scanf("%d", &n);

        printf("Enter the reference string: ");
        for (i = 0; i < n; i++) {
                scanf("%d", &referenceString[i]);
        }

        printf("Enter the number of frames: ");
        scanf("%d", &numFrames);

        for (i = 0; i < numFrames; i++) {
                frames[i] = -1;
        }

        printf("\nPage Frames:\n");
        for (i = 0; i < n; i++) {
                pageFound = 0;

                for (j = 0; j < numFrames; j++) {
                        if (frames[j] == referenceString[i]) {
                                pageFound = 1;
                                break;
                        }
                }

                if (!pageFound) {
                        pageFaults++;

                if (i < numFrames) {
                        frames[i] = referenceString[i];
                } else {
                        int usage[MAX_FRAMES] = {0};
                        for (j = 0; j < numFrames; j++) {
                                for (k = i - 1; k >= 0; k--) {
                                        if (frames[j] == referenceString[k]) {
                                                usage[j] = i - k;
                                                break;
                                        }
                                }
                        }
                        leastUsedIndex = 0;
                        for (j = 1; j < numFrames; j++) {
                                if (usage[j] > usage[leastUsedIndex]) {
                                        leastUsedIndex = j;
                                }
                        }
                        frames[leastUsedIndex] = referenceString[i];
                }

                for (j = 0; j < numFrames; j++) {
                        printf("%d\t", frames[j]);
                }

                printf("\n");
                }
        }

        printf("\nThe number of page faults is %d (%.2f%)\n", pageFaults,(double)pageFaults/n*100);
        printf("\nThe number of page hits is %d (%.2f%)\n", n-pageFaults,(double)(n-pageFaults)/n*100);
        return 0;
}
