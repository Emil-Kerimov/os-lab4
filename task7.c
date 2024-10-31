#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <math.h>
#include <time.h>

int calculate_hits(int radius, int n) {
    int m = 0;
    for (int i = 0; i < n; i++) {
        double x = (double)rand() / RAND_MAX * radius;
        double y = (double)rand() / RAND_MAX * radius;
        if (x * x + y * y <= radius * radius) {
            m++;
        }
    }
    return m;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <radius> <number of throws>\n", argv[0]);
        return 1;
    }

    int radius = atoi(argv[1]);
    int n = atoi(argv[2]);
    srand(time(NULL));

    pid_t pid = fork();
    if (pid == 0) {
        int m = calculate_hits(radius, n);
        exit(m);
    } else if (pid > 0) {
        int status;
        wait(&status);
        int m = WEXITSTATUS(status);
        double S_p = 4.0 * radius * radius;
        double S_m = ((double)m / n) * S_p;
        printf("Estimated area of the circle: %f\n", S_m);
        printf("Estimated value of π: %f\n", S_m / (radius * radius));
    }
    return 0;
}
