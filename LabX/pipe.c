#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

int main() {
    int pipe_fd[2];
    pid_t pid;
    char buffer[128];

    // Create a pipe
    if (pipe(pipe_fd) == -1) {
        perror("Pipe failed");
        return 1;
    }

    pid = fork();

    if (pid < 0) {
        // Fork failed
        perror("Fork failed");
        return 1;

    } else if (pid == 0) {
        // Child process
        close(pipe_fd[1]); // Close the write end of the pipe
        read(pipe_fd[0], buffer, sizeof(buffer));
        printf("Message received by child: %s\n", buffer);
        close(pipe_fd[0]);

    } else {
        // Parent process
        close(pipe_fd[0]); // Close the read end of the pipe
        const char *message = "Operating systems";
        write(pipe_fd[1], message, strlen(message) + 1);
        printf("Message sent from parent: %s\n", message);
        close(pipe_fd[1]);
    }

    return 0;
}
