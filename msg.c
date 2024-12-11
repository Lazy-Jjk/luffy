#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <unistd.h>
struct msg_buffer {
    long msg_type;
    char msg_text[100];
};
int main() {
    int msgid;
    struct msg_buffer message;
    pid_t pid;
    msgid = msgget(IPC_PRIVATE, 0666 | IPC_CREAT);
    if (msgid < 0) {
        perror("Message queue creation failed");
        return 1;
    }
    pid = fork();
    if (pid < 0) {
        perror("Fork failed");
        return 1;
    }
    if (pid == 0) { // Child process
        msgrcv(msgid, &message, sizeof(message.msg_text), 1, 0);
        printf("Child received: %s\n", message.msg_text);
    } else { // Parent process
        message.msg_type = 1;
        strcpy(message.msg_text, "Hello via Message Queue!");
        msgsnd(msgid, &message, sizeof(message.msg_text), 0);
        wait(NULL); // Wait for child process
        msgctl(msgid, IPC_RMID, NULL); // Cleanup
    }
    return 0;
}

