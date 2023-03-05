#include <stdio.h>
#define true 1
#include <math.h>

int sum(long long int n){
    int ans = 0;
    while(n>0){
        ans += n%10;
        n /= 10;
    }
    return ans;
}

int smith(long long int n){
   int sum1 = sum(n);
    int sum2 = 0 ;
    for(long long int i=2; i<= n; i++){
        while(n%i == 0){
            sum2 += sum(i);
             n /= i;
        }
    }
    if(n != 1){
        sum2 += sum(n);
    }
    if(sum1 == sum2)
        return 1;
    return 0;
}

int main()
{

    long long int t;
    scanf("%lld", &t);
    while(t--){
        long long int a,b;
        scanf("%lld%lld", &a, &b);
        int dem = 0;
        for(long long int i = a; i<=b; i++){
           if (smith(i) == 1){
            dem++;
           }

        }

        printf("%d\n", dem);
    }


}
