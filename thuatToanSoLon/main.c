#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define true 1

int a[50],b[50], c[50];
int w,t,e;

void show(int a[], int t)
{
    printf("(%d(", e);
    for(int i=t-1; i>=1; i--)
    {
        printf("%d,",a[i]);
    }
    printf("%d))\n", a[0] );
}

void nhap(int a[], int t)
{
    for(int i=t-1; i>=0; i--)
    {
        scanf("%d",&a[i]);
    }

}
void nhap_SoLieu(int a[], int b[], int *w,int *t)
{
    printf("Nhap so bit(w) va do dai tu(t): ");
    scanf("%d%d", &(*w), &(*t));

    printf("Nhap so nguyen a va b: \n");
    printf("Nhap so a: ");
    nhap(a,*t);
    printf("Nhap so b: ");
    nhap(b,*t);

}
int mod (int a, int b)// đây là phép kiểm tra phép lấy dư có thực hiện với số âm hay không
{
    if(b < 0)
        return -mod(-a, -b);
    int ret = a % b;
    if(ret < 0)
        ret+=b;
    return ret;
}

void Multiprecision_addion(int a[], int b[], int c[], int w, int t, int *e)// thuật toán cộng
{
    int tam;
    tam = pow(2,w);
    c[0] = a[0] + b[0];

    if (c[0]>=0 && c[0]<tam)
        *e = 0;
    else *e = 1;

    c[0] = mod(c[0], tam);

    for (int i =1; i<t; i++)
    {
        c[i] = a[i] + b[i]+*e;
        if (c[i]>=0 && c[i]<tam)
            *e = 0;
        else *e = 1;
        c[i] = mod(c[i], tam);
    }

}

void Multiprecision_subtraction(int a[], int b[], int c[], int w, int t, int *e)// thuật toán trừ
{
    int tam;
    tam = pow(2,w);
    c[0] = a[0] - b[0];

    if (c[0]>=0 && c[0]<tam)
        *e = 0;
    else *e = 1;

    c[0] = mod(c[0], tam);

    for (int i =1; i<t; i++)
    {
        c[i] = a[i] - b[i]-*e;
        if (c[i]>=0 && c[i]<tam)
            *e = 0;
        else *e = 1;
        c[i] = mod(c[i], tam);
    }
}

void chuyenDoi(long long int p, int w, int t, int a[])// chuyển số nguyên lớn về dạng mảng
{
    for(int i = t-1; i>=0; i--)
    {
        a[i] = p/pow(2,i*w);
        p -= a[i]*pow(2,i*w);
    }
}

long long int chuyenDoiNguoc(int c[], int a, int t)// chuyển đổi mảng về số nguyên lớn
{
    for(int i=0; i<t; i++)
    {
        a = c[i]*pow(2,t-1-i);
    }
    return a;
}

int addition_in_Fp()
{

    int P[50], C[50];
    long long int p;
    printf("Nhap so modulo p: ");
    scanf("%lld", &p);
    //copy thuật toán cộng


    nhap_SoLieu(a,b,&w,&t);

    Multiprecision_addion(a,b,c,w,t,&e);


    //bước 2
    if(e==1)
    {
        chuyenDoi(p,w,t,P);// chuyển p về dạng mảng
        //copy thuật toán trừ
        Multiprecision_subtraction(c,P,C,w,t,&e);// thực hiện c-p
        show (C,t);
    }
    else
    {
        long long int n,m;// biến n để lưu giá trị của mảng c về số nguyên lớn, m để lưu giá trị của e
        chuyenDoiNguoc(c,n,t);// thực hiện đưa mảng c về dạng số nguyên lớn và lưu vào n để so sánh với p
        if(n>=p)
        {
            chuyenDoi(p,w,t,P);
            Multiprecision_subtraction(c,P,C,w,t,&m);
            show(C,t);

        }
        else     show(c,t);
    }
}

void subtraction_in_Fq()
{
    int P[50], C[50];
    long long int p;
    printf("Nhap so modulo p: ");
    scanf("%lld", &p);
    //copy thuật toán cộng


    nhap_SoLieu(a,b,&w,&t);

    Multiprecision_subtraction(a,b,c,w,t,&e);


    //bước 2
    if(e==1)
    {
        //copy thuật toán trừ
        chuyenDoi(p,w,t,P);
        Multiprecision_addion(c,P,C,w,t,&e);
        show(C,t);
    }
    else
    {
        show(c,t);
    }
}

void chuyenDoiCoSo2(int a[], int w, int n)
{
    for(int i=0; i<2*w; i++)
    {
        a[i] = 0;
    }
    for(int i=0; n>0; i++)
    {
        a[i]=n%2;
        n=n/2;
    }

}

int chuyen_Doi_sang_so_thap_phan(int a[], int m)
{
    int sum=0;
    for(int i=0; i<m; i++)
    {
        sum += a[i]*pow(2,i);
    }
    return sum;
}

void integer_multiprecision()
{
    int u, v, sum, p[50],m[50],n[50];
    nhap_SoLieu(a,b,&w,&t);

    for(int i=0; i<t; i++) c[i] = 0;

    for(int i=0; i<t; i++)
    {
        u = 0;
        for(int j = 0; j<t; j++)
        {
            sum = c[i+j]+a[i]*b[j]+u;
            chuyenDoiCoSo2(p,w,sum);
            for(int k=0; k<w; k++)
            {
                m[k] = p[k];
                n[k] = p[k+w];
            }
            u = chuyen_Doi_sang_so_thap_phan(n,w);

            c[i+j] = chuyen_Doi_sang_so_thap_phan(m,w);
        }
        c[i+t] = u;
    }
    show (c,2*t);
}

void show_euclide(long long int d, long long int x, long long int y)
{
    printf("\nd: %lld, x: %lld, y: %lld", d,x,y);
}

void bang(long long int q, long long int r, long long int x, long long int y, long long int a,long long int b, long long int x2, long long int x1, long long int y2, long long int y1)
{
    for(int i=0; i<=70; i++)
    {
        printf("_");
    }
    printf("\n|%6lld|%6lld|%6lld|%6lld|%6lld|%6lld|%6lld|%6lld|%6lld|%6lld|\n", q,r,x,y,a,b,x2,x1,y2,y1);
}

void euclide_Mo_Rong()
{
    long long int a,b,d,x,y,x1,x2,y1,y2,q,r;
    printf("Nhap 2 so nguyen a va b: ");
    scanf("%lld%lld", &a, &b);

    if(b==0)
    {
        d = a;
        x = 1;
        y = 0;
        show_euclide(d,x,y);
    }
    else
    {
        x2 = 1;
        x1 = 0;
        y2 = 0;
        y1 = 1;

        for(int i=0; i<=70; i++)
        {
            printf("_");
        }
        printf("\n|%6s|%6s|%6s|%6s|%6s|%6s|%6s|%6s|%6s|%6s|\n", "q", "r", "x", "y","a","b", "x2","x1", "y2","y1" );
        for(int i=0; i<=70; i++)
        {
            printf("_");
        }
        printf("\n|%6s|%6s|%6s|%6s|%6lld|%6lld|%6lld|%6lld|%6lld|%6lld|\n", "", "", "", "", a,b,x2,x1,y2,y1);

        while(b > 0)
        {
            q = a/b;
            r = a%b;
            x = x2 - q*x1;
            y = y2 -q*y1;
            a = b;
            b = r;
            x2 = x1;
            x1 = x;
            y2 = y1;
            y1 = y;
            bang(q,r,x,y,a,b,x2,x1,y2,y1);
        }
        for(int i=0; i<=70; i++)
        {
            printf("-");
        }
        d = a;
        x = x2;
        y = y2;
        show_euclide(d,x,y);

    }

}

void menu()
{
    printf("\n\t\tMENU\n");
    printf("1. Multiprecision addition\n");
    printf("2. Multiprecision subtraction\n");
    printf("3. addition in Fq\n");
    printf("4. subtraction in Fq\n");
    printf("5. integer multiprecision\n");
    printf("6. euclide mo rong\n");
}
int main()
{
    while (true)
    {

        menu();
        int chon ;
        printf("\tVui loong nhap lua chon: ");
        scanf("%d", &chon);
        system("cls");
        switch(chon)
        {
        case 1:
        {
            nhap_SoLieu(a,b,&w,&t);
            Multiprecision_addion(a,b,c,w,t,&e);
            show(c,t);
            break;
        }
        case 2:{
            nhap_SoLieu(a,b,&w,&t);
            Multiprecision_subtraction(a,b,c,w,t,&e);
            show(c,t);
            break;
        }
        case 3:{
            addition_in_Fp();
            break;
        }
        case 4:{
            subtraction_in_Fq();
            break;

        }
        case 5:{
            integer_multiprecision();
            break;
        }
        case 6:{
            euclide_Mo_Rong();
            break;
        }
        case 0: exit(0);
        }

    }
}
