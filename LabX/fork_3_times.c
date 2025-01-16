#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid1, pid2, pid3;

    // First fork
    pid1 = fork();
    if (pid1 == 0) {
        printf("Child 1 PID: %d, Parent PID: %d\n", getpid(), getppid());
    } else {
        // Second fork
        pid2 = fork();
        if (pid2 == 0) {
            printf("Child 2 PID: %d, Parent PID: %d\n", getpid(), getppid());
        } else {
            // Third fork
            pid3 = fork();
            if (pid3 == 0) {
                printf("Child 3 PID: %d, Parent PID: %d\n", getpid(), getppid());
            } else {
                // Parent process
                printf("Parent PID: %d\n", getpid());
            }
        }
    }

    return 0;
}

