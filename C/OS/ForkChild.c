#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main() {
    pid_t pid;
    // Fork a child process
    pid = fork();
    if (pid < 0) {
        // Fork failed
        fprintf(stderr, "Fork Failed\n");
        return 1;
    }
    else if (pid == 0) {
        // Child process
        printf("This is the child process. My PID is %d\n", getpid());
    }
    else {
        // Parent process
        printf("This is the parent process. My child's PID is %d and my PID is %d\n", pid, getpid());
    }
    return 0;
}
