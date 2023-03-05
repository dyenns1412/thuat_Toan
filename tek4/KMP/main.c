#include <stdio.h>
#include <string.h>


void  kmp_table(char* W, int* T)
{
    int pos = 2;// biến chạy số thứ tự trong bảng T
    int cnd = 0;// Biến chạy vị trí trong chuỗi W
    // mặc định vị trí 0 và 1 trong bảng là -1 và 0
    T[0] = -1;
    T[1] = 0;
    int m = strlen(W);// độ dài chuỗi  w

    while(pos < strlen(W))
    {
        if(W[pos - 1] == W[cnd])
        {
            T[pos] = cnd + 1;
            pos ++;
            cnd ++;
        }
        else if(cnd > 0)
        {
            cnd = T[cnd];
        }
        else
        {
            T[pos] = 0;
            pos ++;
        }
    }

    printf("Ham Failure Function: \n");

    for(int i = 0; i< pos; i++)
    {
        printf("%d ", T[i]);
    }
    printf("\n");
}

int kmp_search(char* S, char* W, int* T)
{

    int m = 0, i= 0;
    while(m+i < strlen(S))
    {

        if(W[i] == S[m+i])
        {
            i++;
            if(i == strlen(W))
            {


                return m;
            }
        }

        else
        {
            if(T[i] > -1)
            {
                i = T[i];
                m += i - T[i];
            }
            else
            {
                i = 0;
                m++;
            }
        }
    }
    return -1;


}


int main()
{
    char W[256];
    char S[256];
    int T[256];
    int result[100];//Lưu các vị trí thỏa mãn
    int count = 0;
    gets(S);
    gets(W);

    kmp_table(W,T);

    int n = strlen(S);
    int temp = 0;
    int doDaiBanDau = n;

    while(n != 0 )
    {



        int flag = 0;
        int i = kmp_search(S,W,T);// biến để lưu trữ vị trí xuất hiện
        if(i != -1)
        {
            strncpy(S, S +( i+1),(n-i-1));// cắt chuỗi từ vị trị xuất hiện đến hết chuỗi
            n = n-i-1;// chuỗi còn độ dài n - i- 1
            temp += i+1;// vị trí xuất hiện trong chuỗi mới ứng với vị trí trong chuỗi ban đầu
            S[n] = '\0';// kết thúc chuỗi

            result[count] = i+temp;
            count++;


            flag = 1;
        }

        // nếu độ dài chuỗi S sau khi thực hiện 1 vòng while mà vẫn bằng đồ dài lúc chưa thực hiện thì thoát chương trình
        if(flag == 0)
        {
            if(n == doDaiBanDau)
                printf("Khong tim thay chuoi W trong chuoi S!!!\n");
            break;
        }
    }
    if(n != doDaiBanDau)
        printf("Vi tri xuat hien chuoi W trong chuoi S la: ");
    for(int i = 0; i<count; i++)
    {
        printf("%d  ", result[i]);
    }
    return 0;

}
