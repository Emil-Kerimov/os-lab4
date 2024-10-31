#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void print_process_info(int print_pid, int print_ppid, int print_uid, int print_gid) {
    if (print_pid) printf("Process ID (PID): %d\n", getpid());
    if (print_ppid) printf("Parent Process ID (PPID): %d\n", getppid());
    if (print_uid) printf("User ID (UID): %d\n", getuid());
    if (print_gid) printf("Group ID (GID): %d\n", getgid());
}

int main(int argc, char *argv[]) {
    int print_pid = 1, print_ppid = 1, print_uid = 1, print_gid = 1;
    if (argc > 1) {
        print_pid = atoi(argv[1]);
        print_ppid = atoi(argv[2]);
        print_uid = atoi(argv[3]);
        print_gid = atoi(argv[4]);
    }
    print_process_info(print_pid, print_ppid, print_uid, print_gid);
    return 0;
}
