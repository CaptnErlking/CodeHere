#include<stdio.h>
#define MX_PR 50
#define MX_BL 50
struct Process {
        int size;
        int allocated;
};
struct Block {
        int size;
        int allocated;
};
int main() {
        struct Process Pro[MX_PR];
        struct Block Blo[MX_BL];
        int Bnum,Pnum;
        int i,j;
        printf("Best Fit Memory Allocation: \n");
        printf("Enter the number of Blocks : ");
        scanf("%d",&Bnum);
        printf("Enter the number of Processes : ");
        scanf("%d",&Pnum);
        printf("Enter the size of %d Blocks\n",Bnum);
        for (int i=0; i<Bnum; i++) {
                scanf("%d",&Blo[i].size);
                Blo[i].allocated = 0;
        }
        printf("Enter the size of %d Processes\n",Pnum);
        for (int i=0; i<Pnum; i++) {
                scanf("%d",&Pro[i].size);
                Pro[i].allocated = 0;
        }
        for (int i=0; i<Bnum-1; i++){
                for (int j=i+1; j<Bnum-i-1; j++){
                        if (Blo[j].size>Blo[j+1].size){
                                struct Block temp = Blo[j];
                                Blo[j] = Blo[j+1];
                                Blo[j+1] = temp;
                        }
                }
        }
        for (int i=0; i<Pnum-1; i++){
                for (int j=i+1; j<Pnum-i-1; j++){
                        if (Pro[j].size>Pro[j+1].size){
                                struct Process temp = Pro[j];
                                Pro[j] = Pro[j+1];
                                Pro[j+1] = temp;
                        }
                }
        }
        printf("\nAllocation of blocks using Best Fit is as Follows:\n");
        printf("\nProcesses\tProcessSize\tBlockSize\n");
        for (int i=0; i<Pnum; i++) {
                for (int j=0; j<Bnum; j++) {
                        if (!Blo[j].allocated && Pro[i].size <= Blo[j].size) {
                                Blo[j].allocated = 1;
                                Pro[i].allocated = 1;
                                printf("%d\t\t%d\t\t%d\n",i,Pro[i].size,Blo[j].size);
                                break;
                        }
                }
                if (!Pro[i].allocated) {
                        printf("Process %d must wait as no sufficient memory\n",i);
                }
        }
        return 0;
}
