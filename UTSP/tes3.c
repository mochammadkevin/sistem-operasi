#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

// exec.c
int main()
{
    puts("Running command");

    char *args[] = {"ps", "--forest", NULL};
    execvp(args[0], args);

    puts("Done");
    return 0;
}