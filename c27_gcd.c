#include<stdio.h>
#include<math.h>

int isPrime(int n)
{
    if (n<=1) return 0;
    for (int i=2; i*i<=n;i++)
    {
        if(n%i==0) return 0;
    }
    return 1;
}

int gcd(int a, int b) // theo thuật toán Eclude
{
    if(b==0) return a;
    return gcd(b,a%b);
}

int main ()
{  
    int a, b;
    while (a<=0 || b>=1000)
    {
      scanf("%d %d", &a, &b);
    }
   
    for( int i=a; i<=b;i++)
    {
        for( int j=i+1; j<=b; j++)
        {
            if(isPrime (gcd(i,j)))
            { 
                printf("(%d, %d) ", i, j);
            }
        }
    }
     return 0;
}