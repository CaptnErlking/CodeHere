#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int main() {
    pid_t pid;
    // Create a child process
    pid = fork();
    if (pid < 0) {
        // Fork failed
        perror("Fork failed");
        return 1;
    }
    else if (pid == 0) {
        // Child process
        printf("Child process is running (PID: %d)\n", getpid());
        // Simulating some work in child process
        sleep(2);
        printf("Child process completed.\n");
    }
    else {
        // Parent process
        printf("Parent process is waiting for child to complete...\n");
        wait(NULL);  // Parent waits for the child process to complete
        printf("Child process completed, parent continues.\n");
    }
    return 0;
}
