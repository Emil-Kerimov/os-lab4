#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int local_var = 0;
    pid_t pid1, pid2;

    pid1 = fork();
    if (pid1 == 0) {
        local_var++;
        printf("Child 1: Local var = %d, PID = %d, PPID = %d\n", local_var, getpid(), getppid());

        pid2 = fork();
        if (pid2 == 0) {
            local_var++;
            printf("Grandchild 1.1: Local var = %d, PID = %d, PPID = %d\n", local_var, getpid(), getppid());
        } else if (pid2 > 0) {
            wait(NULL);
        }
    } else if (pid1 > 0) {
        wait(NULL);

        pid1 = fork();
        if (pid1 == 0) {
            local_var++;
            printf("Child 2: Local var = %d, PID = %d, PPID = %d\n", local_var, getpid(), getppid());

            pid2 = fork();
            if (pid2 == 0) {
                local_var++;
                printf("Grandchild 2.1: Local var = %d, PID = %d, PPID = %d\n", local_var, getpid(), getppid());
            } else if (pid2 > 0) {
                wait(NULL);
            }
        } else if (pid1 > 0) {
            wait(NULL);
        }
    }
    return 0;
}
