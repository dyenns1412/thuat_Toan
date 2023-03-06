#include<stdio.h>

int isFnumber(int a)
{
    int sum = 0;
    for (int i = 1; i*i <= a; i++)
    {
        if (a % i == 0)
        {
            sum += i;
            int j = a/i;
            if (i != j && j < a) sum += j;
        }
    
    }
    return sum;
}

int main()
{
    int N;
    scanf("%d", &N);
    if (isFnuber(N) < N) printf("YES");
    else printf("NO");
    return 0;
}