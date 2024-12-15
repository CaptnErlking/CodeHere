#include<stdio.h>
#include<stdlib.h>
int mutex = 1;
int full = 0;
int empty = 3;
int x = 0;
void consumer();
void producer();
int wait(int s);
int signal(int s);
int main(){
        int n;
        printf("\n1.Producer\n2.Consumer\n3.Exit\n");
        while(1){
                printf("\nEnter choice : ");
                scanf("%d",&n);
                switch(n){
                        case 1:
                                if(mutex==1 && empty!=0){
                                        producer();
                                } else {
                                printf("Buffer is Full\n");
                                }
                                break;
                        case 2:
                                if(mutex==1 && full!=0){
                                        consumer();
                                } else {
                                printf("Buffer is Empty\n");
                                }
                                break;
                        case 3:
                                printf("Exit\n");
                                exit(0);
                        default:
                                printf("Invalid option\n");
                }
        }
}
int wait(int s){
        return --s;
}
int signal(int s){
        return ++s;
}
void producer(){
        mutex = wait(mutex);
        full = signal(full);
        empty = wait(empty);
        x++;
        printf("\nProducer produces item %d\n",x);
        mutex = signal(mutex);
}
void consumer(){
        mutex = wait(mutex);
        full = wait(full);
        empty = signal(empty);
        printf("Consumer consumes %d\n",x);
        x--;
        mutex = signal(mutex);
}
