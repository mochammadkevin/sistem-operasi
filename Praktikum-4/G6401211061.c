#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>

int main()
{
    pid_t child = fork();
    if (child == 0)
    {
        while (1)
        {
            puts("child");
            sleep(1);
        }
    }
    else
    {
        sleep(4);
        kill(child, SIGSTOP);

        sleep(3);
        kill(child, SIGCONT);

        sleep(2);
        kill(child, SIGKILL);
    }
    return 0;
}
