#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();
    if (pid == 0) {
        printf("Child process exiting.\n");
        exit(0);
    } else if (pid > 0) {
        printf("Child process created with PID = %d\n", pid);
        sleep(5);
        system("ps -l");
        wait(NULL);
        printf("Zombie process cleaned up.\n");
    }
    return 0;
}
