#include <stdio.h>
#include <stdlib.h>

int procession(int n){
    int m = n;
    int temp = 2;
    while(m > 1){
        if(n%temp == 0){
            if(n%(temp*temp) == 0){
                printf("%d\n", n);
                return 0;
            }
        }


        while(m%temp == 0){
            m /= temp;
        }
        temp++;
    }
}

int main()
{
    int n;

    scanf("%d" ,&n);

    for(int i = 2; i<n; i++){

        procession(i);
    }


}
