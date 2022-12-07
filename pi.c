#include<math.h>
#include<omp.h>
#include<stdio.h>
#include<stdlib.h>

#define num_steps 100000

int main()
{
    double pi = 0;

    //serial 
    double start = omp_get_wtime();

    for(int k = 0;k<num_steps;k++)
    {
        pi+= pow(-1,k) / (2*k+1) ;
    }
    pi  = 4*pi;
    double end = omp_get_wtime();

    double time  = end-start;

    printf("Value of pi in serial : %lf with time : %lf\n",pi,time);


    //parallel
    pi = 0;
    start = omp_get_wtime();

    int size = omp_get_num_threads();
    double thread[size];

    #pragma omp parallel for 
    for(int k=0;k<num_steps;k++)
    {
        int t = omp_get_thread_num();
        thread[t] += pow(-1,k) /(2*k+1);
    }

    for(int i=0;i<size;i++)
    {
        pi+=thread[i];
    }
    pi = 4*pi;

    end = omp_get_wtime();
    time = end-start;

    printf("Value of pi in parallel : %lf with time %lf\n",pi,time);

    return 0;

}