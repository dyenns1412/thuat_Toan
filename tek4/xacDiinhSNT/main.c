#include <stdio.h>
#include <stdlib.h>
int modPrimePow(int a, int b, int p)
{
    int nhiPhan[50], dem = 0;
    int ret = 1;
    if(b == 0)
        return ret;
    while(b != 0)
    {
        nhiPhan[dem] = b%2;
        dem++;
        b /= 2;
    }

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

int checkNT(int n){
    if(n<2)
        return 0;
    if(n == 2)
        return 1;

    for(int i=2; i<=sqrt(n); i++){
        if(n%i == 0)
            return 0;
    }
    return 1;
}
int main()
{
    int a,k,n;
    scanf("%d%d%d", &a, &k, &n);

    if(checkNT(modPrimePow(a,k,n)) == 1){
        printf("YES");

    } else printf("NO");

    return 0;
}
