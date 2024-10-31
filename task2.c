#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

void run_for_seconds(int seconds) {
    int counter = 0;
    time_t start = time(NULL);
    while (time(NULL) - start < seconds) {
        counter++;
    }
    printf("Process ID %d, Counter: %d\n", getpid(), counter);
}

int main() {
    int seconds = 3;
    pid_t pid = fork();
    if (pid == 0) {
        run_for_seconds(seconds);
    } else if (pid > 0) {
        run_for_seconds(seconds);
    } else {
        perror("fork failed");
    }
    return 0;
}
