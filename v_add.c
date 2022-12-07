#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

double *vectAdd(double *c , double *a,double *b,int n)
{
    #pragma omp parallel for 
    for(int i=0;i<n;i++)
    {
        c[i] = a[i] + b[i];
    }

}

int  main()
{
    int n = 5;

    double a[10],b[10],c[10];

    for(int i=0;i<n;i++)
    {
        a[i] = i+1;
        b[i] = i+3;
    }
    vectAdd(c,a,b,n);

    for(int i=0;i<n;i++)
    {
        printf("%f\n",c[i]);
    }

    return 0;
}