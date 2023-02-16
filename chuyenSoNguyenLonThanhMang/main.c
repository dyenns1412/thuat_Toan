#include <stdio.h>
#include <math.h>
void chuyenSoNguyenLon(int arr[100], long long int p, int W,long long int a)
{
    int m = ceil(log(p)/log(2));// hàm ceil là hàm làm tròn lên 1 đơn vị nếu có chữ số thập phân
    int t = ceil((float)m/W);
    int tg = a;
    for(int i=t-1; i>=0; i--)
    {
        int z = pow(2,W*i);
        arr[i]=tg/z;
        tg=tg%z;
    }
    printf("A= [ ");
    for(int i=t-1; i>=0; i--)
    {
        printf("%d",arr[i]);
        if(i!=0)
        {
            printf("   ");
        }
        else
        {
            printf(" ]");
        }
    }
}
int main()
{
    long long int a,p;
    int W, arr[100];
    printf(" Nhap p, w, a\n");
    scanf("%lld",&p);
    scanf("%d",&W);
    scanf("%lld",&a);
    chuyenSoNguyenLon(arr,p,W,a);
}
