#include <stdio.h>
#include <stdlib.h>

int checkNT(int n)
{
    int count =0;
    for(int i = 1; i<n; i++)
    {
        if(n%i == 0)
        {
            count++;
        }
    }

    if(count == 1)
    {
        return 1;
    }
    return 0;
}

int procession(int n)
{
    int count =0;
    for(int i = 1; i<n; i++)
    {
        if(checkNT(i) == 1)
            count ++;
    }
    if(checkNT(count) == 1)
        return 1;
    return 0;
}



int main()
{
    int a,b;
    scanf("%d%d", &a, &b);
    int dem = 0;
    for(int i=a; i<=b; i++)
    {
        if(procession(i) == 1)
            dem++;
    }
    printf("%d",dem);
}
