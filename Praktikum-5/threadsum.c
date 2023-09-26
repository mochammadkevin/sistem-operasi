#include <stdio.h>
#define N 16
int sum = 0;
int main()
{
    int A[N] = {68, 34, 64, 95, 35, 78, 65, 93,
                51, 67, 7, 77, 4, 73, 52, 91};
    for (int i = 0; i < N; i++)
    {
        sum += A[i];
    }
    printf("%d\n", sum);
    return 0;
}
