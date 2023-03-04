#include <stdio.h>
#include <stdlib.h>

int main()
{
    int prime[1001], A[1000], dem = 0;
    for(int i = 0; i<= 1000; i++)
    {
        prime[i] = 1;
    }
    for(int i = 2; i<= 1000; i++)
    {
        if(prime[i] == 1)
        {
            for(int j = i*i; j<= 1000; j += i)
            {
                prime[j] = 0;
            }
        }
    }
    for(int i = 2; i<=1000; i++)
    {
        if(prime[i] == 1)
        {
            A[dem] = i;
            dem++;
        }
    }
    for(int i = 0; i<dem; i++)
    {
        int tam = A[i]*2;
        while(tam <= 1000){
            printf("%d %d\n", A[i], tam);
            tam += A[i];
        }
    }
     for(int i = 0; i<dem; i++)
       {
           for(int j = i; j<dem; j++)
           {
               if( A[i]*A[j] <= 1000)
               {
                   for(int k = A[j]+1; k<1000; k++)
                   {
                       if(k%A[j] != 0 && A[i]*k<=1000)
                       {
                           printf("%d %d\n", A[i]*A[j], A[i]*k);
                       }
                   }

               }
           }
       }

}
