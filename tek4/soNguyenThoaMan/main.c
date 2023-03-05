
#include <stdio.h>
#include <stdlib.h>

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

int main()
{
    long long int a,b;
    scanf("%lld%lld", &a, &b);
    long long int sum = 0;
    for(long long int i = a; i<=b; i++)
    {
       if(checkNT(i) == 1){
        sum += i;
       }
    }


    if(checkNT(sum) == 1)
        printf("YES");
    else printf("NO");
}
