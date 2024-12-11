#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <unistd.h>
int main() {
    int shmid;
    char *shared_mem;
    pid_t pid;
    shmid = shmget(IPC_PRIVATE, 1024, IPC_CREAT | 0666);
    if (shmid < 0) {
        perror("Shared memory creation failed");
        return 1;
    }
    pid = fork();
    if (pid < 0) {
        perror("Fork failed");
        return 1;
    }
    if (pid == 0) { // Child process
        shared_mem = (char *)shmat(shmid, NULL, 0);
        printf("Child received: %s\n", shared_mem);
        shmdt(shared_mem);
    } else { // Parent process
        shared_mem = (char *)shmat(shmid, NULL, 0);
        strcpy(shared_mem, "Hello via Shared Memory!");
        shmdt(shared_mem);
        wait(NULL); // Wait for child process
        shmctl(shmid, IPC_RMID, NULL); // Cleanup
    }
    return 0;
}

