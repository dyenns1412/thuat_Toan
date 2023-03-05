#include<stdio.h>
#include<math.h>
// bài này gặp lỗi là khi nhập n>= 6 thì bộ nhớ bị tràn mà chưa tìm được cách khắc phục
long long int max(long long int a,long long int b){
    if(a>b) return a;
    return b;
}


void eratosthenes(long long int a,long long int b){
    long long int prime[b-a+1];
    for(long long int i = 0; i<=b-a+1;i++){
        prime[i] = 1;
    }

    for(long long int i = 2; i<=sqrt(b); i++){
        for(long long int j = max((i*i), (i+a-1)/i*i); j<=b; j+=i){
            long long int k = j-a;
            prime[k] = 0;

        }

    }
  for(long long int i = a; i<=b; i++){
        if(prime[i-a])
        printf("%0.1f\n",(float)i);
    }

}
int main()
{
    int n;
    scanf("%d",&n);
    long long int a = pow(10,n-1), b = pow(10,n)-1;
    eratosthenes(a,b);

}
