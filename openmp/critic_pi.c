#include <stdio.h>
#include <omp.h>

#define THREADS 2
static long num_steps=100000000;

void main(){

    double pi=0.0;
    double step=1.0/(double)num_steps;

    omp_set_num_threads(THREADS);
    int nthreads;

    #pragma omp parallel
    {
        int i,id,thrds;
        double x,sum;//sum variable not array;
        id=omp_get_thread_num();
        thrds=omp_get_num_threads();

        if(id==0) nthreads=thrds;

        for(i=id,sum=0.0;i<num_steps;i+=nthreads){
            x=(i+0.5)*step;
            sum+=4.0/(1.0+x*x);
        }
        
        #pragma omp critical 
        pi+=sum*step;


    }
}