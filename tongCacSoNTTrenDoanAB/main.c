#include<stdio.h>
#include<math.h>
long long int max(long long int a,long long int b)
{
    if(a>b) return a;
    return b;
}


void eratosthenes(int a,int b)
{
   int prime[b-a+1];
    for(int i = 0; i<=b-a; i++)
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
    int sum = 0;
    for(int i = max(a,2); i<=b; i++)
    {
        if(prime[i-a])
        {
            sum += i;;


        }
    }
    printf("%d", sum);

}
int main()
{
    int a,b;
    scanf("%d%d",&a, &b);
    eratosthenes(a,b);

}
