#include <iostream>
#include <math.h>

using namespace std;

int checkNT(int n){
    for(int i = 2; i <= sqrt(n); i++){
        if(n%i == 0)
            return 0;
    }
    return 1;
}

int max(int a, int b){
    if(a>b)
        return a;
    return b;
}

int main(){
    int a[100], n;
    cin>>n;
    for(int i = 0; i<n; i++)
        cin>>a[i];
    for(int i = 0; i<n; i++){
            if(a[i] == 1 || a[i] == 0)
               {
                   a[i] = 0;
                   continue;
               }
        if(checkNT(a[i]) == 0)
           a[i] = 0;

    }
    int sub = 0;
    for(int i = 0; i<n-1; i++){
        if(a[i] != 0){
            for(int j = i; j<n; j++){
                if(a[j] != 0){

                   int tam = abs(a[i] - a[j]);
                   sub = max(sub,tam);
                }
            }
        }

    }
    cout<< sub;
}
