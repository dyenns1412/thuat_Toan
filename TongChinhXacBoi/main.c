#include<stdio.h>
#include<math.h>
void chuyenSoNguyenLon(int arr[100],int p,int W,int a,int t)
{
    int tg = a;
    for(int i = t-1 ; i>=0; i--)
    {
        int z = pow(2,W*i);
        arr[i]=tg/z;
        tg = tg%z;
    }
}
int main()
{
    int W,m,t,e,w,h,arr[100],brr[100],c[100];
    long long int p,a,b;
    printf("Nhap cac so p,W,a,b:\n");
    scanf("%lld%d%lld%lld",&p,&W,&a,&b);
    m = ceil(log(p)/log(2));
    t = ceil((float)m/W);
    chuyenSoNguyenLon(arr,p,W,a,t);
    chuyenSoNguyenLon(brr,p,W,b,t);
    e = 0;
    for(int i =0; i<t; i++)
    {
        w=arr[i]+brr[i]+e;
        h = pow(2,W);
        if(w>=h)
        {
            e=1;
            c[i]=w%h;
        }
        else
        {
            e=0;
            c[i]=w%h;
        }
    }
    printf("A+B=(%d, [",e);
    for(int i = t-1 ; i>=0; i--)
    {
        printf("%d",c[i]);
        if(i==t-1)
        {
            printf("\t");
        }
        else if(i!=0 && i!=t-1)
        {
            printf("   ");
        }
        else
        {
            printf("])");
        }
    }
}
