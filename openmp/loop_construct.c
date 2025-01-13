#include<stdio.h>
#include<omp.h>
#define MAX 1000


int main(){
    int i,j,a[MAX];


    //since j is dependent change to independent
    // j=5;
    // for(i=0;i<MAX;i++){
    //     j+=2;
    //     a[i]=some_big_op(j);
    // }
    #pragma omp for
    for(i=0;i<MAX;i++){
        j=5+2*(i+1);
        a[i]=some_big_op(j);
    }
}