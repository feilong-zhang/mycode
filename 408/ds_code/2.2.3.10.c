#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define N 15

void ArrSwapP(int* R,int p){
	if(p>=N||p<0)
	return;
	int bak[p],i=0,j=0,k=0;
	for(;i<p;i++){
		bak[j++]=R[i];
	}
	for(;k<N&&i<N;i++){
		R[k++]=R[i];
	}
	for(i=0;i<j;i++){
		R[k++]=bak[i];
	}return;
}

int main(){
	int R[N],i=0,p=0;
	printf("ÇëÊäÈëP=");
	scanf("%d",&p);
	printf("\n");
	for(;i<N;i++){
		R[i]=rand()%100+1;
		printf("%d ",R[i]);
	}printf("\n");
	ArrSwapP(R,p);
	for(i=0;i<N;i++){
		printf("%d ",R[i]);
	}
} 

