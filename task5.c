#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void my_system(const char *command) {
    pid_t pid = fork();
    if (pid == 0) {
        execlp(command, command, NULL);
        perror("execlp failed");
        exit(1);
    } else if (pid > 0) {
        wait(NULL);
    } else {
        perror("fork failed");
    }
}

int main() {
    my_system("ls");
    return 0;
}
