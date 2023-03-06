#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return (b, a % b);
}

int is_prime(int a)
{
    for (int i = 2; i <= sqrt(a); i++)
    {
        if (a % i == 0)
            return 0;
    }
    return 1;
}

int get_d(int e, int phi_n)
{
    int k = 1;
    while (((k * e) % phi_n) != 1)
    {
        k++;
    }
    return k;
}

int get_e(int phi_n)
{

    int e;
    while (gcd(phi_n, e) != 1)
    {
        e = rand() % (phi_n - 2) + 2; // 2 <= e < phi(n)
    }

    return e;
}

int get_n_and_phi_n(int *p, int *q)
{
    int n, phi_n;
    do
    {
        *p = rand() % 400 + 101; // 101 <= p < 501
    } while (!is_prime(*p));
    do
    {
        *q = rand() % 400 + 101; // 101 <= q < 501
    } while (!is_prime(*q));

    n = (*p) * (*q);

    phi_n = (*p - 1) * (*q - 1);
    return phi_n;
}

int is_number(char *sbd)
{
    int lenght = strlen(sbd);
    char number[50];
    int cnd = 0;

    for (int i = 0; i < lenght; i++)
    {
        if (isdigit(sbd[i]))
        {
            number[cnd] = sbd[i];
            cnd++;
        }
    }
    int Sbd = atoi(number);
    return Sbd;
}

int encrypt_Decrypt(int a, int k, int n)
{
    int b = 1;
    if (k == 0)
        return b;
    long long int A = a;
    if (k % 2 == 1)
    {
        b = a;
    }
    k /= 2;
    while (k != 0)
    {
        A = A * A % n;
        if (k % 2 == 1)
            b = A * b % n;
        k /= 2;
    }

    return b;
}

int main()
{
    printf("Nhap sbd: ");
    char Sbd[50];
    fgets(Sbd, 50, stdin);
    int q, p, phi_N, n, e, d;
    int sbd = is_number(Sbd);
    phi_N = get_n_and_phi_n(&p, &q);

    n = q * p;

    e = get_e(phi_N);
    d = get_d(e, phi_N);

    int c, m;
    c = encrypt_Decrypt(sbd, e, n);
    m = encrypt_Decrypt(c, d, n);
    printf("%d\n%d\n", c, m);
    system("pause");
}
