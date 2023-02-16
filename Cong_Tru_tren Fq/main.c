
#include<stdio.h>
#include<math.h>
void chuyenMang(int A[100],int p,int W,int a,int t)
{
    for(int i = t-1 ; i>=0; i--)
    {
        int z = pow(2,W*i);
        A[i]=a/z;
        a = a%z;
    }
}
int cong(int a1[100],int b1[100],int c1[100],int t,int W)
{
    int e = 0;
    for(int i =0; i<t; i++)
    {
        int w=a1[i]+b1[i]+e;
        int h = pow(2,W);
        if(w>=h)
        {
            e=1;
            c1[i]=w%h;
        }
        else
        {
            e=0;
            c1[i]=w%h;
        }
    }
    return e;
}
int tru(int a1[100],int b1[100],int c1[100],int t,int W)
{
    int e = 0;
    for(int i =0; i<t; i++)
    {
        int w=a1[i]-b1[i]-e;
        int h = pow(2,W);
        if(w<0)
        {
            c1[i]=h+w;
            e=1;
        }
        else if(w>=h)
        {
            c1[i] =w%h;
            e=1;
        }
        else
        {
            e=0;
            c1[i]=w%h;
        }
    }
    return e;
}
int main()
{
    int a1[100], b1[100], c1[100], P[100];
    int p, W, a, b,e;
    printf("Nhap p, w, a, b\n ");
    scanf("%d%d%d%d",&p,&W,&a,&b);
    int m = ceil(log(p)/log(2));
    int t = ceil((float)m/W);
    chuyenMang(a1,p,W,a,t);
    chuyenMang(b1,p,W,b,t);
    e=cong(a1,b1,c1,t,W);
    if(e==1)
    {
        chuyenMang(P,p,W,p,t);
        tru(c1,P,c1,t,W);
    }
    else
    {
        chuyenMang(P,p,W,p,t);
        for(int i = t-1 ; i>=0; i--)
        {
           if(c1[i]>=P[i])
           {
               e=tru(c1,P,c1,t,W);
               break;
           }
           else
           {
               break;
           }
        }
    }
    printf("A= [%d",c1[t-1]);
    for(int i=t-2;i>=0;i--)
    {
       printf("   %d",c1[i]);
    }
    printf("]");
}
