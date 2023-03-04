#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int nhanBinhPhuongCoLap(int a, int k, int n){
    int b = 1, A = a;
    if(k == 0){
        return b;
    }

    if(k%2 == 1)
    {
        b = a;
    }
    k /= 2;

    while(k!=0){
        A = A*A %n;
        if(k % 2 == 1){
            b = (A*b) %n;
        }
        k /= 2;
    }

    return b;

}

int isPrime(int n)
{

    if(n == 2 || n == 3)
        return 1;

    if(n <= 1 || n%2 == 0)
        return 0;

    int p = n-1;
    int r,a, s = 0;

    while(1)
    {

        r = p/2;
        s++;
        if(r%2 == 1)
        {
            break;
        }
        p = r;
    }

    int y ;

    for(int i = 0; i<s; i++){
        a = (rand()%(n-3))+2;

        y = nhanBinhPhuongCoLap(a,r,n);
        if(y!=1 && y!= n-1){
            int j = 1;
            while(j<=(s-1) && y != n-1 ){
                y = (y*y) %n;
                if( y == 1)
                    return 0;
                j++;
            }
            if(y  != n-1)
                return 0;
            else if(y == n-1)
                return 1;
        }
        else if(y == 1 || y == n-1)
            return 1;

    }


}

int main()
{
    int n;
    scanf("%d", &n);


    for(int i = 2; i<=n; i++)
    {
        if(isPrime(i) == 1)
            printf("%d ", i);
    }

    return 0;
}
