#include<stdio.h>
#include<math.h>
//9/10
int isPrime(int n)
{

	int i;
	if (n < 2) return 0;
	for (i = 2; i <=n/2; i++)
	{
		if (n % i == 0) return 0;
	}
	return 1;
}
void solve(int a, int b)
{
    int sum=0;
    for(int i=a;i<=b;i++)
    {
        if(isPrime(i)==1)
        {
            sum+=i;
        }
    }
    if(isPrime(sum)==1) printf("YES");
    else printf("NO");
}

int main()
{
    int a,b;
    scanf("%d%d", &a, &b);
    solve(a,b);
    
    return 0;
}

