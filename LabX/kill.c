#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

void signal_handler(int sig) {
    if (sig == SIGUSR1) {
        printf("Child process received SIGUSR1 from parent.\n");
    }
}

int main() {
    pid_t pid = fork();

    if (pid == -1) {
        // Fork failed
        perror("fork failed");
        exit(1);
    } else if (pid > 0) {
        // Parent process
        printf("Parent process, sending signal to child...\n");
        sleep(2); // Sleep to ensure child is ready
        kill(pid, SIGUSR1); // Send signal to child
    } else {
        // Child process
        signal(SIGUSR1, signal_handler); // Set up signal handler
        printf("Child process, waiting for signal...\n");
        pause(); // Wait for signal to arrive
    }

    return 0;
}
