#include<stdio.h>
#include<math.h>
#include<time.h>

int isPrime(int n)
{
    if(n<0)
    {
        return 0;
    }
    else
    {
        for(int i=2; i<=sqrt(n); i++)
        {
            if(n%i==0)
            {
                return 0;
            }
        }
    }
    return 1;
}
int GCD(long long int a, long long int b)
{
    long long int A=a;
    long long int B=b;
    while(B>0)
    {
        long long int r=A%B;
        A=B;
        B=r;
    }
    return A;
}
long long int nhanBinhPhuongCoLap(long long int a, long long int k, long long int n)
{
    long long int b=1;
    long long int A=a;
    if( k == 0)
        return b;
    else
    {
        if(k % 2 == 1)
            b = a;
        k /= 2;
        while(k != 0)
        {
            A = A*A % n;
            if(k % 2 == 1)
            {
                b = A*b %n;
            }
            k /= 2;
        }

    }

    return b;
}
int isCarmichael(int n)
{
    if(n <= 3 )
        return 0;
    srand(time(0));
    if(isPrime(n)==1)
    {
        return 0;
    }
    int b= rand()%(n-3) + 2;
    while(b<n)
    {
        if(GCD(b,n)==1)
        {
            int u= nhanBinhPhuongCoLap(b,n-1,n);
            if(u!=1)
            {
                return 0;
            }
        }
        b++;
    }
    return 1;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(long long int i=2; i<=t; i++)
    {
        if(isCarmichael(i)==1)
        {
            printf("%d",i);
            if(i!=t)
            {
                printf("  ");
            }
        }
    }
}
