#include <stdio.h>
#include <stdlib.h>
#define true 1

int checkNT(long long int n)
{
       if (n < 2)
              return 0;
       else if (n == 2)
              return 1;
       else if (n % 2 == 0)
              return 0;
       for (long long int i = 3; i < n; i += 2)
              if (n % i == 0)
                     return 0;
       return 1;
}


int phanTichThuaSo(int n)
{
    int mang[10], dem = 0;
    int tam = 2;

    while(n >1 )
    {

        if(n%tam ==0)
        {
            mang[dem] = tam;
            dem++;
            n = n/tam;
            tam--;

        }

        tam++;
    }
    printf("[%d",mang[0]);
    for(int i =1; i< dem; i++)
    {

        if(mang[i] == mang[i-1])
            continue;
        if(mang[i] != mang [dem-1])
            printf(", %d", mang[i]);
        else printf(", %d", mang[dem-1]);
    }
    printf("]");
    printf("\n");
        printf("[");

    int prime[dem+1], count = 0;
     for(int i=0; i<dem; i++ ){
        prime[i] = 1;
     }
    for(int i=0; i<dem; i++ )
    {
        int tam = 1;
        if(prime[i] == 0)
            continue;

        for(int j=i+1; j<dem; j++ )
        {
            if(mang[i] == mang[j])
            {
                tam++;
                prime[j] = 0;
            }
        }

         if(mang[i] != mang [dem-1])
            printf("%d, ", tam);
        else printf("%d]", tam);

}



}

int main()
{
    int n;
    scanf("%d", &n);
    phanTichThuaSo(n);

}
