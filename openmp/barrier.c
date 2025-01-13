#include <stdio.h>
#include <omp.h>

void big_calc(int thread_id) {
    printf("Thread %d is executing big_function()\n", thread_id);
    for (int i = 0; i < 10000; i++);
    printf("Thread %d finished big_function()\n", thread_id);
}

int main() {
    #pragma omp parallel num_threads(4) //sets 4 thread
    {
        int thread_id = omp_get_thread_num();
        big_calc(thread_id);
        #pragma omp barrier // threads wait here until every thread finishes the function

    //completion 
        if (thread_id == 0) {
            printf("All threads finished big_function and passed the barrier.\n");
        }
    }
    return 0;
}
