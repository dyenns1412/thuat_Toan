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

    for(int i=2; i<=n; i++)
    {
        if(prime[i] == 1)
        {
            for(int j=i+1; j<=n; j++)
            {
                if(prime[j] == 1)
                {


                    if(checkNT(j-i)==1 && checkNT(j+i)==1 )
                        printf("%d\n%d", i, j);
                }
            }
        }

    }
}

int main()
{
    int n;
    scanf("%d", &n);
    procesion(n);

}
