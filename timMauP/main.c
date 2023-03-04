#include<stdio.h>
#include<string.h>

int LastOccurrence(char *P,char x)
{
    for(int i= strlen(P)-1; i>=0; i--)
    {
        if(P[i]==x)
        {
            return i;
        }
    }
    return -1;
}



void search(char *T,char *P)
{
    int n = strlen(T);// Độ dài chuỗi n
    int m= strlen(P);// Độ dài chuỗi m

    int temp = 0;// lưu chữ độ dài phần chuỗi bị cắt

    int tam = n;// lưu độ dài của chuỗi trước khi cắt

    while(n>0)
    {

        int i= m-1;
        int j=m-1;

        int min = 0 ;
        int flag=0;


        while( i < strlen(T))
        {
            if(T[i]!=P[j])
            {
                if( j < 1 + LastOccurrence(P,T[i]))
                {
                    min = j;
                }
                else
                {
                    min =1 + LastOccurrence(P,T[i]);
                }
                i= i+m-min;
                j=m-1;

            }
            else
            {

                if(j==0)
                {

                    strncpy(T, T +( i+1),(n-i-1));// cắt chuỗi từ vị trị xuất hiện đến hết chuỗi

                    n = n-i-1;// chuỗi còn độ dài n - i- 1
                    printf("%d\n",i+temp);
                    flag=1;
                    temp = i+1+temp;// vị trí xuất hiện trong chuỗi mới ứng với vị trí trong chuỗi ban đầu
                    tam = n; // dùng để lưu chữ độ dài của chuỗi trước khi cắt làm điều kiện cho kết thúc vòng lặp ở phía dưới
                    T[n] = '\0';// kết thúc chuỗi
                    break;
                }

                i--;
                j--;
            }
        }

        if(flag==0 && n == tam)// nếu độ dài mới bằng độ dài chuỗi trước đó thì hết vị trí xuất hiện
        {
            break;
        }
    }


}
int main()
{
    char T[1000],P[1000];
    gets(T);
    gets(P);
    if(strlen(T) > strlen(P))
    search(T,P);
    else{
            search(P,T);

    }
    return 0;
}

