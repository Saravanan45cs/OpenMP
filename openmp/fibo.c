#include <stdio.h>
#include <omp.h>

int fibo(int n){
    int x,y;

    if(n<2) return n;

    #pragma omp task shared(x)// use shared or else it will be private and the value returned will be 0
    x=fibo(n-1);

    #pragma omp task shared(y)
    y=fibo(n-2);

    #pragma omp taskwait
    return x+y;
}


int main(){

    int n=5;
    int ans=fibo(n);

    printf("%d\n",ans);

}