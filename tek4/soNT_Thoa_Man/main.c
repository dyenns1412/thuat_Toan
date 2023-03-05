#include<stdio.h>
#include<math.h>
#include<stdlib.h>


int main()
{
    int n;
    scanf("%d", &n);
    int check[n+1];

    for(int i = 0 ; i <= n ; i++)
    {
        check[i]=1;
    }
    int dem = 0;
    for(int i = 2; i <= n; i++)
    {
        if(check[i]==1)
        {
            for(int j = i*i; j<=n; j+=i)
            {
                check[j]=0;
            }

        }
    }
        for(int i = 2; i <= n; i++){
            if(check[i] == 1){
                dem++;
            }
        }
        printf("%d", dem);


}
