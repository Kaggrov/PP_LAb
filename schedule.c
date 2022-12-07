#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int main()
{
    int iterations = 8,itern = 1,i;

    #pragma omp parallel for schedule(static,2)
    for(i=1;i<=iterations;i++)
    { 
        int t = omp_get_thread_num();
        itern += 1;
        itern%=2;

        printf("Thread %d itern %d value : %d\n",t,itern+1,i);
    }
}