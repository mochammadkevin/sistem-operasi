#include <stdio.h>
#include <pthread.h>

#define N 16
#define NUM_THREADS 2

int sum = 0;
int A[N] = {68, 34, 64, 95, 35, 78, 65, 93,
            51, 67, 7, 77, 4, 73, 52, 91};
typedef struct {
    int start;
    int end;
} ThreadInfo;

void *thread_function(void *arg) {
    ThreadInfo *info = (ThreadInfo *)arg;
    int local_sum = 0;

    for (int i = info->start; i < info->end; i++) {
        local_sum += A[i];
    }

    __sync_fetch_and_add(&sum, local_sum);

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    ThreadInfo thread_info[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        thread_info[i].start = i * (N / NUM_THREADS);
        thread_info[i].end = (i + 1) * (N / NUM_THREADS);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_function, &thread_info[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("%d\n", sum);
    return 0;
}
