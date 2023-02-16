#include <stdio.h>
#include <stdlib.h>

long long int modPrimePow(long long int a, long long int b, int p)
{

    int nhiPhan[50], dem = 0;
    while(b != 0)
    {
        nhiPhan[dem] = b%2;
        dem++;
        b /= 2;
    }

    int ret;

    if(nhiPhan[0] == 0)
        ret = 1;
    if(nhiPhan[0] == 1)
    {
        ret = a;
    }

    for(int i= 1; i<dem; i++)
    {
        a = a*a %p;
        if(nhiPhan[i] == 1)
        {
            ret = a*ret%p;
        }
    }

    return ret;
}


long long int gcd(long long int a, long long int b)
{
    while(b!=0)
    {
        long long int t = a%b;
        a = b;
        b = t;
    }

    return a;
}
int fermat(long long int a,long long int n)
{
    if(gcd(a,n) != 1){
        return 0;
    }
     int ret = modPrimePow(a, n-1, n);
     if(ret == 1){
        return 1;
     }
     return 0;
}

long long int max(long long int a, long long int b){
    if(a>b) return a;
    return b;
}
int check(long long int n){
    for(long long int i = 2; i< max(10,n-1); i++){
        if(fermat(i, n) != 1){
            return 0;
        }
    }
    return 1;
}

int phanTichThuaSo(long long int n){
    int mang[50], dem = 0;
    int tam = 2;

    while(n!=0){
            if(n%tam == 0){
                mang[dem] = tam;
                dem++;
            }
        while(n%tam == 0){
            n = n/tam;
                    printf("+++");

        }
        tam++;
    }
    for(int i =0; i< dem; i++){
        printf("%d ", mang[i]);
    }
    long long  int sum = n;
    for(int i=0; i<dem ; i++){
        sum *=(1-1/mang[i]);
    }
    return sum;
}


int main()
{
    long long int n, k;
    scanf("%lld%lld", &n, &k);
    for(int i= 0; i<k; i++){
        if(n == 1){
            n = 1;
        }

        else n = phanTichThuaSo(n);
        printf("%lld", n);

    }

}
