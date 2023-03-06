
#include <stdio.h>
#include <math.h>

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

int main()
{
	int a, b, count = 0;
	while (1)
	{
		scanf("%d%d", &a, &b);
		if (a < b) break;
	}
	for (int i = a; i <= b; i++)
	{
		if (isPrime(i)) count++;
	}
	printf("%d\n", count);
	return 0;
}