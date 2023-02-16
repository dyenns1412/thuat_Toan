#include <iostream>
#define true 1
#include <math.h>


using namespace std;

long long int sum(long long int n){
    long long int ans = 0;
    while(n>0){
        ans += n%10;
        n /= 10;
    }
    return ans;
}

int smith(long long int n){
    long long int sum1 = sum(n);
    long long int sum2 = 0 ;
    for(long long int i=2; i<= sqrt(n)+1; i++){
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
    cin>>t;
    while(t--){
        long long int a,b;
        cin>> a>>b;
        long long int dem = 0;
        for(long long int i = a; i<=b; i++){
           if (smith(i) == 1){
            dem++;
           }

        }

        cout<<dem<<'\n';
    }


}
