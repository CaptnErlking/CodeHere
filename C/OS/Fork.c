#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
int main() {
        //make two process which run same
        //program after this instruction
        pid_t p = fork();
        if(p<0){
                perror("Fork fail");
                exit(1);
        }
        printf("Hii Guys, process_id(pid) = %d \n", getpid());
        return 0;
}
