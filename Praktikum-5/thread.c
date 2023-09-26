#include <stdio.h>
#include <pthread.h>

#define N 16

int sum = 0;

void *thread_function(void *arg) {
    int *A = (int *)arg;

    for (int i = 0; i < N; i++) {
        sum += A[i];
    }

    pthread_exit(NULL);
}

int main() {
    int A[N] = {68, 34, 64, 95, 35, 78, 65, 93,
                51, 67, 7, 77, 4, 73, 52, 91};

    pthread_t thread;
    pthread_create(&thread, NULL, thread_function, (void *)A);

    pthread_join(thread, NULL);

    printf("%d\n", sum);
    return 0;
}
