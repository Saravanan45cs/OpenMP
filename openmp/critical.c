#include <stdio.h>
#include <omp.h>

int main() {
    int sum = 0;
    omp_set_num_threads(8);

    #pragma omp parallel for 
        for(int i=1;i<=100;i++){
            //#pragma omp critical 
            //one thread waits for the other to complete the task (mutual exclusion)

            // #pragma omp atomic //guarantees one thread could update the variable at a time
            sum+=1; //race condition. different values of sum will be displayed
        }

    printf("Final sum = %d\n", sum);
    return 0;
}
