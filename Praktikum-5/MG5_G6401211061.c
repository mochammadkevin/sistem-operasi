#include <stdio.h>
#include <pthread.h>

#define N 16
#define NumberofThreads 4

int sum = 0;

void *array_sum(void *arg) {
    int *nums = (int *)arg;
    int temp = 0;
    for (int i = 0; i < N; i++) {
        temp += nums[i];
    }
    sum += temp;
    return NULL;
}

int main() {
    pthread_t t[NumberofThreads];
    int A[N] = {68, 34, 64, 95, 35, 78, 65, 93,
                51, 67, 7, 77, 4, 73, 52, 91};

    for (int i = 0; i < NumberofThreads; i++) {
        pthread_create(&t[i], NULL, array_sum, (void *)A);
    }

    for (int i = 0; i < NumberofThreads; i++) {
        pthread_join(t[i], NULL);
    }

    printf("%d\n", sum);
    return 0;
}
