#include<stdio.h>
#include<math.h>

int check[100000];

void sangEratosthenes(long long int n)
{
    for(long long int i = 2 ; i<= n ;i++)
    {
        check[i]=1;
    }
    long long int i = 2;
    while(i<=n)
    {

        if(check[i]==1)
        {
            printf("\np=%d\n",i);
            for(int j = 2*i ; j <= n ; j+=i)
            {
                check[j]=0;
            }
            for(int a = 2 ; a <= n ;a++)
            {
                if(check[a]==1)
                {
                    printf("%d  ",a);
                }
            }
        }
        i++;
    }
}
int main()
{
    long long int n,low,high;
    long int delta,k=1,d,m,dem=1;
    scanf("%lld",&n);
    scanf("%ld",&delta);
    printf("Chia pham vi tu 2 den %d thanh cac doan co kich co %d\n",n,delta);
    for(int i = 2; i <= n ;i++)
    {
        check[i]=1;
        if(i==n)
        {
            printf("%d",i);
            break;
        }
        printf("%d  ",i);
        if(k==delta)
        {
            printf("||");
            k=0;
        }
        k++;
    }
    low = delta+2;
    high = (low+delta)-1;
    d =delta+1;
    printf("\nXet doan %d:",dem);
    sangEratosthenes(d);
    while(high<=n && low <=n)
    {
        dem++;
        printf("\nXet doan %d:",dem);
        m = sqrt(high);
        for(int i = 2 ; i <= high ; i++)
        {
            if(check[i]==1 && i<=m)
            {
                printf("\np=%d\n",i);
                for(int j = low ; j <= high ;j++)
                {
                    if(check[j]==1)
                    {
                        for(int h = 2*i ; h <= high ;h+=i)
                        {
                            if(j==h)
                            {
                                check[j]=0;
                            }
                        }
                        if(check[j]==1)
                        {
                            printf("%d  ",j);
                        }
                    }
                }
            }
        }
        high+=delta;
        low+=delta;
        if(high>n)
        {
            high=n;
        }
    }
    printf("\nTat ca cac so nguyen to <= %d:\n",n);
    for(int i = 2; i <=n ;i++)
    {
        if(check[i]==1)
        {
            printf("%d  ",i);
        }
    }
}
