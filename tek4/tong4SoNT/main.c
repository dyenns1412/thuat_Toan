#include <stdio.h>
#include <stdlib.h>

int checkNT(int n)
{
    if(n<2) return 0;
    if(n == 2)
        return 1;
    for(int i =2; i<=sqrt(n); i++)
    {
        if(n%i ==0)
            return 0;
    }
    return 1;
}

void procesion(int n)
{
    int prime[n+1];
    for(int i=0; i<=n; i++)
    {
        prime[i] = 1;
    }

    for(int i=2; i<=n; i++)
    {
        if(prime[i] == 1)
        {
            for(int j=i*i; j<=n; j += i)
            {
                prime[j] = 0;
            }
        }
    }
    int mang[100], dem = 0;
    for(int i=2; i<=n; i++)
    {
        if(prime[i] == 1)
        {
            mang[dem] = i;
            dem++;
        }

    }

    for(int i=0; i<dem-3; i++){
        if(mang[i]+mang[i+1]+mang[i+2]+mang[i+3]<=n && checkNT(mang[i]+mang[i+1]+mang[i+2]+mang[i+3]) == 1){
            printf("%d\n%d\n%d\n%d",mang[i],mang[i+1],mang[i+2],mang[i+3]);
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    procesion(n);

}
