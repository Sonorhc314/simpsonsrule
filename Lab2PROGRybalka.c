#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#define PI 3.14159

const double a = 0;
const double b = 2*PI;

typedef double(*fptr)(double);

int N=30;

double F(double x)
{
    double f;
    f = log(1/(5-3*cos(x))+1/(x*x));
    if(f == INFINITY)
    {
        f=0;
    }
    return f;
}


double root(fptr h1)
{
    double x;
    double I=0;
    //if(flag==0)
    double h = (b-a)/N;
    N=2*N;
    x=a+h;
    while(x<b)
    {
        I=I+4*(*h1)(x);
        x=x+h;
        if(x>=b)
        {
            break;
        }
        I=I+2*(*h1)(x);
        x=x+h;
    }
    I=(h/3)*(I+(*h1)(b)+(*h1)(a));
    return I;
}

int main()
{
    float er, res, res1;
    int f=0;
    for(er=20; er>=0.001; )
    {
        if(f==0)
        {
            res = root(F);
            printf("\nI=%.3f",res);
            f=1;
        }
        res1 = root(F);
        printf("\nI=%.3f",res1);
        er=(fabs(res-res1))/16;
        res=res1;
        //printf("\n\n%f\n\n ", er);
    }
    //printf("%f ", er);
    int mas[10]={1,2,3,4,5,6,7,9,8,10};
    int *m=&mas[0];
    int mas_d[10];
    for(int i1=0;i1<10;i1++)
    {
        mas_d[i1]=m[i1];
        printf("\n%d ", mas_d[i1]);
    }
    return 0;
}
