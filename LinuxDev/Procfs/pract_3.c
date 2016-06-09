// Count parents process of programm by pid

#include <stdio.h>
#include <string.h>
#include <linux/limits.h>

int read_proc(int pid) {
    char fname[255];
    FILE *input;
    int ppid;
    char tcomm[PATH_MAX];
    char state;

    sprintf(fname, "/proc/%i/stat", pid);
    input = fopen(fname, "r");

    fscanf(input, "%i %s %c %i", &pid, tcomm, &state, &ppid);
    fclose(input);
    return ppid;
}

int main(int argc, char *argv[]) {
    if (argc != 2)
        return -1;
    int pid, ppid;
    int init_pid = 1;
    sscanf(argv[1], "%i", &pid);
    printf("%i\n", pid);
    ppid = read_proc(pid);
    while (ppid != init_pid) {
        printf("%i\n", ppid);
        ppid = read_proc(ppid);
    }
    printf("%i\n", init_pid);
    return 0;
}
