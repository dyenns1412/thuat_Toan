#include <stdio.h>
#include <math.h>
#define MAX 100

int isTPrime(int x)
{
	int cnt=0;
	for(int i=1; i<=x; i++)
	{
		if(x%i==0)
			cnt++;
	}
	
	if(cnt == 3)
		return 1;
	return 0;
}

void solve(int n)
{
	int cnt2=0;
	for(int i=1; i<=n; i++)
	{
		if(isTPrime(i)==1)
        {
            printf("%d\n", i);
            cnt2++;
        }
			
	}
	
}

int main()
{
	int n;
	scanf("%d", &n);
	
	solve(n);

	return 0;
}
