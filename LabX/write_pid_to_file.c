#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    // File to store PIDs
    FILE *file = fopen("pids.txt", "w");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    pid_t pid = fork();

    if (pid == -1) {
        // Fork failed
        perror("fork failed");
        fclose(file);
        exit(1);
    } else if (pid > 0) {
        // Parent process
        fprintf(file, "Parent PID: %d\n", getpid());
        printf("Parent PID: %d\n", getpid());
    } else {
        // Child process
        fprintf(file, "Child PID: %d\n", getpid());
        printf("Child PID: %d\n", getpid());
    }

    fclose(file); // Close the file
    return 0;
}

