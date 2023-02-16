#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int checkNT(int n)
{
    for(int i = 2; i<= sqrt(n); i++)
    {
        if(n%i == 0)
            return 0;
    }
    return 1;
}

int check(int n)
{
//tạo 1 mảng lưu giữ các chữ số của n
    int a[100], dem = 0;

    while(n != 0)
    {
        a[dem] = n%10;
        n /= 10;
        dem++;
    }

    int tam = 0;
    //nghịch đảo số n
    for(int i = 0; i<dem; i++)
    {
        tam += a[i]*pow(10, dem-1-i);
    }

    if(checkNT(tam) == 1)//1 là nguyên tố 0 là hợp số
        return 1;
    return 0;
}

void procesion(int n)
{

    //check các số nguyên tố nhỏ hơn n
    int prime[n];
    for(int i=0; i<n; i++)
    {
        prime[i] = 1;
    }

    for(int i = 2; i<n ; i++)
    {
        if(prime[i] == 1)
        for(int j = i*i; j<n; j+=i)
        {
            prime[j] = 0;
        }
    }
    //kiểm tra nghịch đảo các số nguyên tố có là 1 số nguyên tố hay không
    for(int i = 2; i<n; i++)
    {
        if(prime[i] == 1)
        {
            if(check(i) == 1)
            {
                printf("%d\n", i);
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
