#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int mod(int a, int k, int n)
{
    int res = 1;
    if (k == 0)
        return res;
    int A = a;
    if (k % 2 == 1)
        res = a;
    k /= 2;
    while ((k != 0))
    {
        A = A * A % n;
        if (k % 2 == 1)
            res = A * res % n;
        k /= 2;
    }
    return res;
}

int fermat(int n)
{

    if (n < 2)
        return 0;
    if (n <= 3)
        return 1;

    int k = 10;

    while ((k--))
    {
        int a = rand() % (n - 2) + 2;
        
        if (mod(a, n - 1, n) != 1)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    srand(time(NULL));
    int n;
    scanf("%d", &n);
    if (fermat(n) == 1)
        printf("%d la so nguyen to\n", n);
    else
        printf("%d khong phai la so nguyen to\n", n);
    system("pause");
}