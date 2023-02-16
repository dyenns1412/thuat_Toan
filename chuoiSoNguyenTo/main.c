#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lenght(char str[])
{
    int dem = 0;
    while(str[dem] != '\0')
        dem++;
    return dem;
}

int checkNT(int n)
{
    if(n == 1)
        return 0;
    for(int i=2; i<=n/2; i++)
    {
        if(n%i==0)
            return 0;
    }
    return 1;
}

int appearAmount(char str[])
{



    int A[1000], count = 0;
    for(int i=0; i<lenght(str); i++ )
    {
        int dem = 1;
        if(str[i] == '0')
            continue;

        for(int j=i+1; j<lenght(str); j++ )
        {
            if(str[i] == str[j])
            {
                dem++;
                str[j] = '0';
            }
        }
        A[count] = dem;
        count++;
    }
    if(checkNT(count)==0)
        return 0;
    for(int i=0; i<count; i++)
    {
        if(checkNT(A[i])==0)
            return 0;
    }
    return 1;
}



int main()
{
    int n;
    scanf("%d", &n);
    while(n--)
    {
        char str[10000];
        fflush(stdin);

        scanf("%s", str);
        if(appearAmount(str) == 0)
            printf("NO\n");
        else printf ("YES\n");
    }
}
