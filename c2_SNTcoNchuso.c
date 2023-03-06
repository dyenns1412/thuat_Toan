#include<stdio.h>
#include<math.h>

long long int max(long long int a, long long int b)
{
    if(a>b) return a;
    return b;
}

void sieve2(long long int l, long long int r)
{
    long long int p[r-l+1];
    for(long long int i=0;i<=r-l+1;i++)
    {
        p[i]=1;
    }
    for(long long int i=2;i<=sqrt(r);i++)
    {
        if(p[i])
        {
            for(long long int j=max(i*i,(l+i-1)/i*i);j<=r;j+=i)
            {
                p[j-l]=0;
            }
        }
    }
    for(int i=max(l,2);i<=r;i++)
    {
        if(p[i-l]==1) 
        printf("%.1lf\n ", (double)i);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    long long int l=pow(10,n-1);
    long long int r=pow(10,n)-1;
    sieve2(l,r);
}