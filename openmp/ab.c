#include<stdio.h>
#include<omp.h>

int main(){

    #pragma omp parallel
    {
    int id=0;
    printf("Hello %d ",id);
    printf("World %d ",id);
    }
    
}