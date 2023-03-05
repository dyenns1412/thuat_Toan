#include<stdio.h>
#include<math.h>

int nhanBinhPhuongCoLap(long long int a,long long int k,long long int n)
{
    long long int b = 1;
    long long int A=a;
    if(k==0)
    {
        return b;
    }
    else
    {
        if(k%2==1)
        {
            b=a;
        }
        k/=2;
        while(k>0)
        {
            A=(A*A)%n;
            if(k%2==1)
            {
                b=(b*A)%n;
            }
            k/=2;
        }
    }
    return b;
}
int main()
{
    long long int a,n,b,flag=0;
    scanf("%lld",&n);
    scanf("%lld%lld",&a,&b);
    long long int r,s=0;
    long long int p = n-1; //101 100 r=50 ,s=1,p=50,r=25,s=2 100= 2^2*25
    while(1)
    {
        r=p/2;
        s++;
        if(r%2==1)
        {
            break;
        }
        p=r;
    }
    printf("Kiem tra so nguyen n=%lld:\n",n);
    printf("%lld-1 = 2^%lld.%lld\n",n,s,r);
    for(int i = a +1 ; i<=b-1; i++)
    {
        printf("Co so a= %lld:\n",i);
        long long int y = nhanBinhPhuongCoLap(i,r,n); // y1!=1 và giá trị nó khác 100 else y=1
        if(y!=1&&y!=n-1)
        {
            printf("y= %lld => (y!=1)&&(y!=n-1)\n",y);
            int j=1;
            printf("   j=%lld\n",j);
            while((j<=s-1) && (y!=n-1) && y!=1)
            {
                printf("   j=%lld, y=%lld =>(j<=s-1)&&(y!=n-1)\n",j,y);
                y=(y*y)%n;
                if(y==1)
                {
                    printf("   y=%lld\n",y);
                    printf("Ket qua: Hop so\n");
                    flag=0;
                }
                j++;
            }
            if(y!=n-1&&y!=1)
            {
                printf("y = %lld => y!=n-1\n",y);
                printf("Ket qua: Hop so\n");
                flag=0;
            }
            else
            {
                printf("Ket qua: Nguyen to\n");
                flag=1;
            }
        }
        else
        {
            printf("Ket qua: Nguyen to\n");
            flag=1;
        }

    }
    if(flag==0)
    {
        printf("%d la hop so",n);
    }
    else
    {
        printf("%d co the la nguyen to",n);
    }
}
