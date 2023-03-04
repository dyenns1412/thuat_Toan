#include <stdio.h>
#include <stdlib.h>

void procession(int n){
    int prime[n+1];
    for(int i = 0; i<= n; i++){
        prime[i] = 1;
    }

    for(int i = 2; i<=n ; i++){
        if(prime[i] == 1){
            for(int j = i*i; j <= n; j += i){
                prime[j] = 0;
            }
        }
    }

    for(int i = 2; i<=n - 2 ; i++){
        if(prime[i] == 1){
            if(prime[i+2] == 1)
                printf("%d %d\n", i, i+2);
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    procession(n);

}
