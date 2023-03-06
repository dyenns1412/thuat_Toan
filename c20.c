#include<stdio.h>
#include<math.h>

int gcd(int a, int b) 
{
    int d,x,y;
    if(b==0) 
      return a;
    return gcd(b,a%b);
}

int main ()
{  
    int m, n, d;
    
      scanf("%d%d%d", &m, &n, &d);
    
   
    for( int i=m; i<n;i++)
    {
        for( int j=i+1; j<n+1; j++)
        {
            int ucln = gcd(i,j);
            if(ucln==d)
            { 
                printf("(%d,%d) ", i, j);
            }
        }
    }
     return 0;
}