#include <stdio.h>
#include <unistd.h>
#include <string.h>
int main() {
    int pipefd[2];
    pid_t pid;
    char write_msg[] = "Hello from parent!", read_msg[50];
    if (pipe(pipefd) == -1) {
        perror("Pipe failed");
        return 1;
    }
    pid = fork();
    if (pid < 0) {
        perror("Fork failed");
        return 1;
    }
    if (pid == 0) { // Child process
        close(pipefd[1]);
        read(pipefd[0], read_msg, sizeof(read_msg));
        printf("Child received: %s\n", read_msg);
        close(pipefd[0]);
    } else { // Parent process
        close(pipefd[0]);
        write(pipefd[1], write_msg, strlen(write_msg) + 1);
        close(pipefd[1]);
    }
    return 0;
}


