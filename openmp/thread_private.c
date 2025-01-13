#include <stdio.h>
#include <omp.h>


static int counter = 0;
#pragma omp threadprivate(counter)//if threadprivate isnt used it is shared and the value will be the last thread id

int main() {
    #pragma omp parallel num_threads(4)
    {
        counter = omp_get_thread_num();  // Each thread sets its own value
        printf("Thread %d: counter = %d\n", omp_get_thread_num(), counter);
    }

    //counter retains its value for the master thread
    printf("Master thread: counter = %d\n", counter);

    return 0;
}
