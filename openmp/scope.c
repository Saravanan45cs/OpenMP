#include <stdio.h>
#include <omp.h>

int main() {

    int sum = 0;

    #pragma omp parallel shared(sum) //shared variable  
    //if private(sum) is used the global result 0 will be printed as the sum is not initialized
    {
        int local_sum = 0;
        
        #pragma omp for
        for (int i = 0; i < 10; i++) {
            local_sum += i;
        }
        
        #pragma omp critical
        sum += local_sum;  //Combine local_sum into shared sum
    }

    printf("Final sum = %d\n", sum);//45
    return 0;
}


//FOR PI PROGRAM

/*  #include <stdio.h>
    #include <omp.h>
    static long num_steps = 100000000;
    double step;
    int main ()
    {
        int i;
        double x, pi, sum = 0.0;
        double start_time, run_time;


        
        step = 1.0/(double) num_steps;

                
        start_time = omp_get_wtime();
        #pragma omp parallel for private(x) reduction(+:sum) 
        for (i=1;i<= num_steps; i++){
            x = (i-0.5)*step;
            sum = sum + 4.0/(1.0+x*x);
        }

        pi = step * sum;
        run_time = omp_get_wtime() - start_time;

        printf("\n pi with %ld steps is %lf in %lf seconds\n ",num_steps,pi,run_time);//0.06
} */



