#include <stdio.h>
#include <stdlib.h>

int checkNT(int n)
{
    if(n<2)
        return 0;
    if(n == 2)
        return 1;

    for(int i=2; i<=sqrt(n); i++)
    {
        if(n%i == 0)
            return 0;
    }
    return 1;
}

int gcd(int a, int b)
{
    int A = a;
    int B = b;
    int R;
    while(B>0)
    {
        R = A%B;
        A = B;
        B =R;
    }
    return A;
}
int main()
{
    int a[4];
    for(int i=0; i<4; i++)
    {
        scanf("%d", &a[i]);
    }
    int dem = 0;
    for(int i = 0; i<3; i++)
    {
        for(int j=i+1; j<4; j++)
        {
            if(checkNT(gcd(a[i], a[j])) == 1)
            {
                if(a[i] <a[j])
                printf("%d, %d\n", a[i], a[j]);
                else                 printf("%d, %d\n", a[j], a[i]);
                dem++;

            }


        }

    }
    if(dem == 0)
    printf("0\n");
}
