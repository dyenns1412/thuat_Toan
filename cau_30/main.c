#include <stdio.h>
#include <stdlib.h>\

int isCarmichael(int n)
{
    //Tìm các số nguyên tố nhỏ hơn sqrt(n)
    int prime[n+1], A[1000], pos = 0;
    for(int i=0; i<=n/2; i++)
    {
        prime[i]= 1;
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

    for(int i = 2; i<= n; i++)
    {
        if(prime[i] == 1)
        {
            A[pos] = i;
            pos++;
        }
    }

    for(int i= 0; i< pos; i++)
    {
        if((n % (A[i]*A[i])) == 0)
        {
            return 0;
        }

    }

    int flag = 0;
    for(int i= 0; i<pos; i++)
    {
        if(n%A[i] == 0)
        {
            flag++;
            if((n-1)%(A[i]-1) != 0)
                return 0;
        }
    }
    if(flag == 0)
        return 0;
    return 1;



}

int main()
{
    int n;
    scanf("%d", &n);
    int dem = 0;
    for(int i=2; i<=n; i++)
    {
        if(isCarmichael(i) == 1)
            dem++;
    }
    printf("%d", dem);

}
