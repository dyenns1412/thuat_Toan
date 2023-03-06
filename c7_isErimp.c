#include<stdio.h>
#include<math.h>

int isPrime(int x)
{
	if(x<2)
		return 0;
	for(int i=2; i<=sqrt(x); i++)
	{
		if(x%i==0)
			return 0;
	}
	return 1;
}

int reverse(int x)
{
    int r, rev=0;
    while(x>0)
    {
        r = x % 10;
        rev = rev * 10 + r;
        x = x/10;
    }
    return rev;
}
int isEmirp(int n)
{
	if(isPrime(n)==0) return 0;
	return isPrime(reverse(n));
}
int main()
{
    int n;
	scanf("%d", &n);
	
	for(int i=1; i<n; i++)
	{
		if(isEmirp(i))	
			printf("%d\n", i);
	}
	return 0;

}