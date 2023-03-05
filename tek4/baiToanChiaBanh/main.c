#include <stdio.h>
#include <stdlib.h>

int check(int n)
{
    int prime[n+1];
    for(int i = 0 ; i <= n ; i++)
    {
        prime[i]=1;
    }
    for(int i = 2; i <= n; i++)
    {
        if(prime[i]==1)
        {
            for(int j = 2*i; j<=n; j+=i)
            {
                prime[j]=0;
            }
        }
    }

    int mang[10000], count = 0;
     for(int i = 2; i <= n; i++){
        if(prime[i] == 1){
            mang[count] = i;
            count++;
        }
     }

     for(int i = 0; i <count; i++){
        for(int j = i; j <count; j++)
            if((mang[i]+mang[j]) == n)
            return 1;
     }
     return 0;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int weight;
        scanf("%d", &weight);
        if(check(weight) == 1) printf("Deepa\n");
        else printf("Arjit\n");
    }
}
