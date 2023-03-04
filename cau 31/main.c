#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h)


#define MAX_LEN 100

long long int Number(char* str)
{
    int len = strlen(str);
    char num[MAX_LEN];
    int num_len = 0;

    for (int i = 0; i < len; i++)
    {
        if (isdigit(str[i]))
        {
            num[num_len++] = str[i];
        }
    }

    // In ra số cuối cùng nếu có
    long long int MSV = atoi(num);
    return MSV;
}

long long int isSNT(long long int n){
    if(n < 2)
        return 0;
   for(int i = 2; i<= sqrt(n); i++){
        if(n%i == 0)
            return 0;
   }
    return 1;
}

long long int FindSNTLane(long long int n){
    while(isSNT(--n) != 1){

    }
    return n;
}

long long int FindSNTTop(long long int n){

     while(isSNT(++n) != 1){

    }
    return n;
}


long long int nearestSNT(long long int n){
    if(n < 2)
        return  FindSNTTop(n);

    long long int a = FindSNTLane(n);
    long long int b = FindSNTTop(n);
    if(n-a <= b-n)
        return a;
    else return b;

}

long long int nhaBingPhuongCoLap(long long int a,long long int k){
   long long int n = 123456;
    long long int b = 1;
    if(k == 0)
        return b;
    long long int A = a;
    if(k%2 == 1){
        b = a;
    }
    k/=2;
    while(k != 0 ){
        A = A*A %n;
        if(k%2 == 1)
            b = A*b %n;
        k /= 2;
    }


    return b;
}
int main()
{
    char str[MAX_LEN];
    fgets(str, MAX_LEN, stdin);

    long long int MSV = Number(str);

    long long int a = nearestSNT(MSV);
    printf("%lld\n", a);
    printf("%lld", nhaBingPhuongCoLap(MSV, a));
}
