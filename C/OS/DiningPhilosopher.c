#include <stdio.h>
#include <stdlib.h>

int tph, philname[20], status[20], howhung, hu[20], cho;

void one();
void two();
void three();
int main() {
        int i;
        printf("\n\nDining Philosopher Problem");
        printf("\nEnter the total number of Philosophers: ");
        scanf("%d", &tph);
        for (i = 0; i < tph; i++) {
                philname[i] = i + 1;
                status[i] = 1;
        }

        printf("How many philosophers are hungry: ");
        scanf("%d", &howhung);

        if (howhung == tph) {
                printf("\nAll philosophers are hungry...\nDeadlock state will occur\nExiting\n");
                exit(0);
        } else {
                for (i = 0; i < howhung; i++) {
                        printf("Enter philosopher %d position (1 to %d): ", i + 1, tph);
                        scanf("%d", &hu[i]);
                        hu[i]--;
                        status[hu[i]] = 2; // 2 means hungry
                }

                do {
                        printf("\nOptions:\n1. One can eat at a time.\n2. Two can eat at a time.\n3. Three can eat at a time.\n4. Exit\nEnter your choice: ");
                        scanf("%d", &cho);
                        switch (cho) {
                                case 1: one(); break;
                                case 2: two(); break;
                                case 3: three(); break;
                                case 4: exit(0);
                                default: printf("\nInvalid choice\n");
                        }
                } while (1);
        }
        return 0;
}

void one() {
        int pos = 0, x;
        printf("\nAllow one philosopher to eat at any time.\n");

        for (x = 0; x < howhung; x++, pos++) {
                printf("\nP %d is granted to eat", philname[hu[pos]]);

                for (int y = pos + 1; y < howhung; y++) {
                        printf("\nP %d is waiting", philname[hu[y]]);
                }
        }
}

void two() {
        int i, j, s = 0, t, r, x;

        printf("\nAllow two philosophers to eat at the same time\n");
        for (i = 0; i < howhung; i++) {
                for (j = i + 1; j < howhung; j++) {
                        if (abs(hu[i] - hu[j]) > 1 && abs(hu[i] - hu[j]) != tph - 1) {
                                printf("\n\nCombination %d:\n", s + 1);
                                t = hu[i];
                                r = hu[j];
                                printf("P %d and P %d are granted to eat\n", philname[t], philname[r]);
                                for (x = 0; x < howhung; x++) {
                                        if (hu[x] != t && hu[x] != r) {
                                                printf("P %d is waiting\n", philname[hu[x]]);
                                        }
                                }
                                s++;
                        }
                }
        }
}
void three() {
        int i,j,k,s=0,t,r,e,x;
        if (howhung<3) printf("\nLess than three Hungry\n");
        printf("\nAllow three philosophers to eat at the same time\n");
        for (i=0; i<howhung; i++){
                for (j = i+1; j<howhung; j++){
                        for(k=j+1; k<howhung; k++){
                                if (    abs(hu[i] - hu[j]) > 1 && abs(hu[i] - hu[j]) != tph - 1 &&
                                        abs(hu[i] - hu[k]) > 1 && abs(hu[i] - hu[k]) != tph - 1 &&
                                        abs(hu[k] - hu[j]) > 1 && abs(hu[k] - hu[j]) != tph - 1
                                ){
                                        printf("\n\nCombination %d:\n", s + 1);
                                        t = hu[i];
                                        r = hu[j];
                                        e = hu[k];
                                        printf("P %d and P %d and P %d are granted to eat\n", philname[t], philname[r], philname[e]);
                                        for (x = 0; x < howhung; x++) {
                                                if (hu[x] != t && hu[x] != r && hu[x] != e) {
                                                        printf("P %d is waiting\n", philname[hu[x]]);
                                                }
                                        }
                                        s++;
                                }
                        }
                }
        }
}
