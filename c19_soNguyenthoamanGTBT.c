#include<stdio.h>

int check(int a)
{
    if (a == 1) return 0;
    if (a == 2) return 1;
    for (int i = 2; i*i <= a; i++)
    {
        if (a % i == 0) return 0;
    }
    return 1;
}

int main()
{ 
    int n, m;
    scanf("%d %d", &n, &m);
    int  A, B, C;
    scanf(" %d %d %d",  &A, &B, &C);
   
    for (int i = n; i <= m; i++)
    {
        if (check(A*i*i + B*i + C) == 1)
        {
            printf("%d", i);
            break;
        }
        
    }
    return 0;
}