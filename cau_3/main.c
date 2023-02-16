
#include <stdio.h>
#include <math.h>

void printDivisors(int n, int sum1, int dem)
{
    int sum2 =0, count = 0;
    // Note that this loop runs till square root
    for (int i=1; i<=n; i++)
    {
        if (n%i==0)
        {
           sum2 += i;
           count ++;

        }
    }

    printf("%d", n+sum2+count - sum1 - dem);
}

int main()
{
    int n;
    scanf("%d", &n);

    int dem =0, sum1 =0;
    for (int i=2; i<=n; i++)
    {
        int count=0;
        for(int j=1; j<i; j++)
        {
            if(i % j == 0)
            {
                count++;
            }
        }
        if(count == 1)
        {
            if(n%i == 0){
            sum1 += i;
            dem++;
            }

        }
    }
    printDivisors(n,sum1,dem);
    return 0;
}



