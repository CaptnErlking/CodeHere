#include<stdio.h>
void main(){
        int st[10],bt[10],wt[10],tat[10],n,tq;
        int i,count=0,swt=0,temp,sq=0;
        float awt = 0.0, atat=0.0;
        printf("Enter the number of Process: ");
        scanf("%d",&n);
        printf("Enter Burst Time for Sequence : ");
        for (i=0; i<n; i++){
                scanf("%d",&bt[i]);
                st[i]=bt[i];
        }
        printf("Enter the quantum: ");
        scanf("%d",&tq);
        while(1){
                for(i=0, count=0; i<n; i++){
                        temp = tq;
                        if (st[i]==0){
                                count++; continue;
                        }
                        if (st[i]>tq) st[i]=st[i]-tq;
                        else if (st[i]>=0){
                                temp = st[i]; st[i]=0;
                        }
                        sq=sq+temp;
                        tat[i]=sq;
                }
                if (n==count) break;
        }
        for (i=0; i<n; i++){
                wt[i] = tat[i]-bt[i];
                swt = swt + wt[i];
                atat = atat + tat[i];
        }
        awt = (float) swt/n;
        atat = (float)atat/n;
        printf("ProcessNo.\tBurstTime\tWaitingTime\tTurnAroundTime\n");
        for (i=0; i<n; i++){
                printf("\n%d\t\t%d\t\t%d\t\t%d\t\t", i+1, bt[i], wt[i], tat[i]);
        }
        printf("\nAverage time is %.2f where average turnaround time is %.2f\n", awt, atat);
}
