#include<stdlib.h>
#include <stdio.h>

long long int modPrimePow(long long int a, long long int b, int p)
{
    int nhiPhan[50], dem = 0;
    int ret = 1;
    if(b == 0)
        return ret;
    while(b != 0)
    {
        nhiPhan[dem] = b%2;
        dem++;
        b /= 2;
    }




    if(nhiPhan[0] == 1)
    {
        ret = a;
    }

    for(int i= 1; i<dem; i++)
    {
        a = a*a %p;
        if(nhiPhan[i] == 1)
        {
            ret = a*ret%p;
        }
    }

    return ret;
}

int main()
{
    long long int a, b;
    scanf("%lld%lld", &a, &b);
    int  m = 1000000007;
    printf("%lld", modPrimePow(a,b,m));
}
