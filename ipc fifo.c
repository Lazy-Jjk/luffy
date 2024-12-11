#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#define FIFO_NAME "myfifo"
int main() {
    pid_t pid;
    char write_msg[] = "Hello via FIFO!", read_msg[50];
    mkfifo(FIFO_NAME, 0666);
    pid = fork();
    if (pid == 0) { // Child process
        int fd = open(FIFO_NAME, O_RDONLY);
        read(fd, read_msg, sizeof(read_msg));
        printf("Child received: %s\n", read_msg);
        close(fd);
    } else { // Parent process
        int fd = open(FIFO_NAME, O_WRONLY);
        write(fd, write_msg, strlen(write_msg) + 1);
        close(fd);
    }
    unlink(FIFO_NAME);
    return 0;
}

