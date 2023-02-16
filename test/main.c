#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define true 1

int isSquareNumber(int a)
{
    if(a<1)   // trường hợp < 1 => không phải số cp
        return 0;
    int i=1;
    while(i*i<=a)
    {
        if(i*i==a)
        {
            return 1;
        }

        i++;
    }
    return 0;
}

int max(int a, int b)
{
    if(a>b)
        return a;
    return b;
}

void eratosthenes(int a,int b)
{
    // thuật toán sàng phân đoạn
    int prime[b-a+1];
    for(int i = 0; i<=b-a+1; i++)
    {
        prime[i] = 1;
    }

    for(int i = 2; i<=sqrt(b); i++)
    {
        for(int j = max((i*i), (i+a-1)/i*i); j<=b; j+=i)
        {
            int k = j-a;
            prime[k] = 0;
        }
    }

    int dem=0;
    for(int i = a; i<=b; i++)
    {
        if(prime[i-a])
        {
            for(int j = 2; j< sqrt(i/2); j++)
            {
                int k = i - j*j;
                if(isSquareNumber(k)==1)
                    dem++;
            }
        }
    }
    printf("%d", dem);

}

int main()
{
    int a,b;
    scanf("%d%d", &a, &b);
    eratosthenes(a,b);
}
