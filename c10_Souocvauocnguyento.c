#include<stdio.h>
#include<math.h>

int isPrime(int n)
{
    if(n<2) return 0;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0) return 0;
    }
    return 1;
}

int soUoc(int n)
{

    int dem=0;
    for (int i=1; i<=n;i++)
    {
        if(n%i==0) dem++;
    }
   printf("%d\n", dem);
}


int soUocNT (int n)
{
    int dem=0;
    for(int i=1; i<=n;i++)
    {
         if(isPrime(i) && n%i==0) dem++;
    }
   
   printf("%d\n", dem);
   
}

int main()
{
    int n;
    scanf("%d", &n);
    soUoc(n);
    soUocNT(n);

}
