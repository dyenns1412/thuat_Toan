
#include<stdlib.h>
#include<stdio.h>
#include<math.h>




int change(int a)
{
    int p[3], dem = 0;
    while(a>0)
    {
        p[dem] = a%10;
        a/=10;
        dem++;
    }
    int sum = 0;
    for(int i = 0; i<dem; i++)
    {
        sum += p[i]*pow(10,2-i);
    }
    return sum;
}

int checkNT(int a)
{
    for(int i = 2 ; i<sqrt(a); i++)
    {
        if(a%i == 0)
            return 0;
    }
            return 1;

}
void checkSoLapPhuong()
{
    int  prime[10];
    for(int i =0; i<10; i++)
    {
        prime[i] = 1;
        if((i*i*i)<100)
            prime[i] = 0;
        else
        {
            prime[i] = i*i*i;


        }

    }
    for(int i = 0; i<10; i++)
        {
            if(prime[i] !=0)
            {

                int tam = change(prime[i]);
                if(checkNT(tam)==1)
                    printf("%d", tam);
                }
        }
}
int main()
{
    checkSoLapPhuong();

}
