#include<stdio.h>
#include<math.h>
int demSoUoc(int n){
    int dem =1;
    for(int i=1; i<=n/2;i++){
        if( n%i==0 ) {
            dem++;
        }
	}
    return dem;
}

int main(){
	int n;
	scanf("%d",&n);
	int dem = 0;
	for (int i=1; i<=n;i++){
		if(demSoUoc(i)== 3){
			printf("%d\n",i);
			dem++;
		}
	}


}
