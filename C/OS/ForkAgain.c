#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main() {
        int id;
        printf("Hi guys\n");
        id = fork();
        if(id>0){
                printf("This is process : %d \n",getpid());
        }
        else if (id==0) {
                printf("Fork created id : %d \n",getpid());
                printf("Fork parent id : %d \n",getppid());
        }
        else {
                printf("Creation failed");
        }
        return 0;
}