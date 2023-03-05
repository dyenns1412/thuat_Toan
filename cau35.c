#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 #include <math.h>

 int mod(int a, int k, int n){
    int b = 1;
    if(k == 0)
    return b;
    int A = a;

    if(k%2 == 1)
        b = A;
    k /= 2;
    
    while ((k!=0))
    {
        A = A*A %n;
        if(k%2 == 1)
         b = b*A %n;
         k /= 2;
    }
    return b;
    
 }

int miller_Rabin(int n){
    srand(time(0));

    if(n == 2 || n == 3)
        return 1;
    if(n%2 == 0 || n <2)
        return 0;

    int temp = n-1;
    int res, pos = 0, a;

    while (1)
    {
        res = temp/2;
                pos++;

        if(res%2 == 1) 
        break;
        temp = res;
    }

    int y;
    for(int i = 0;i <pos; i++){
        a = rand()%(n-2)+2;

        y = mod(a,res,n);

         if( y != 1 && y != n-1){
            
           int j = 1;

           while ((pos-1 >= j && y != n-1))
           {
                y = y*y %n;
                if(y == 1)
                return 0;
                j++;
           }

           if(y != n-1)
           return 0;
           
            
         }
    }
    return pos;

    
}
 int main(){
    int n;
    scanf("%d" , &n);
    for(int i = 2; i<= n; i++){
        if(miller_Rabin(i) != 0){
                 printf("%d ", i);
                 // công thức độ chính xác = 1 - 1/4^k
                  printf("Do chinh xac la : %.5f\n", (1-pow(0.25,miller_Rabin(i))));
        }
       
    }

    system("pause");

 }