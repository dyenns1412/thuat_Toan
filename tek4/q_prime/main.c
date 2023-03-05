#include<stdio.h>
#include<math.h>

void SortUp2(int a[], int n)// hàm sắp xếp tăng dần
{
    for(int i=0; i<n; i++)
        for(int j=0; j<=i; j++)
        {
            if(a[j]>a[i])
            {
                a[i]=a[i]+a[j];
                a[j]=a[i]-a[j];
                a[i]=a[i]-a[j];
            }
        }
}

void check(int n)
{

    //sàng tất cả số nguyên tố nhỏ hơn n
    int m = n/2;
    int check[m+1];

    for(int i = 2 ; i <= m ; i++)
    {
        check[i]=1;
    }

    for(int i = 2; i <= m; i++)
    {
        if(check[i]==1)
        {
            for(int j = i*i; j<=m; j+=i)
            {
                check[j]=0;
            }

        }
    }

    int a[100];//tạo 1 mảng để lưu các số nguyên tố
    int dem = 0;
    for(int i = 2 ; i<=m; i++)
    {
        if(check[i]==1)
        {
            a[dem] = i;
            dem++;
        }
    }
    //cho các số q-prime vào 1 mảng
    int mang[100],tam =0;
    for(int i = 0; i<dem-1; i++)
    {
        if(a[i]*a[i]*a[i] <= n)//lập phương số nguyên tố
        {
            mang[tam] = a[i]*a[i]*a[i];
            tam++;
        }

        for(int j = i+1; j<dem; j++)
        {

            if((a[i]*a[j])<=n)
            {

                mang[tam] = a[i]*a[j];//tích 2 số nguyên tố
                tam++;

            }

        }

    }
    //nếu không có số nào thì in No
    if(tam == 0) printf("No");

    //sắp xếp lại mảng các số q-prime theo thứ tự tăng dần
    SortUp2(mang,tam);

    //in các số q-prime theo thứ tự tăng dần
    for(int i=0; i<tam; i++)
    {
        printf("%d\n",mang[i]);
    }
}


int main()
{
    // Ý tưởng: số q-prime là các số có tích là 2 số nguyên tố khác nhau hoặc lập phương số nguyên tố
    int n;
    scanf("%d",&n);// nhập số nguyên n
    check(n);
}
