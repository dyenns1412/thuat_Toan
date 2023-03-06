#include<stdio.h>
#include<math.h>

int sumDivisor (int x)
{
    int sum = 0;
    for (int i = 1; i <= x/2; i++)
    {
        if (x % i == 0)
        {
            sum += i;
        }
    }
    return sum;
}
int checkFriendlyNumber(int n)
{
    for(int i=1; i<n; i++)
	{
		int x = sumDivisor(i);
		if(x<n && x>i && sumDivisor(x)==i && i!=sumDivisor(i))
			printf("%d %d\n", i, x);
	}
}
int main()
{
    int n;
    scanf("%d", &n);
    checkFriendlyNumber(n);

	return 0;
}