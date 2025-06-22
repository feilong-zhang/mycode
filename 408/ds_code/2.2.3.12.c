#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define N 8

int GetMainX(int* A){
	int bak[N]={0},i=0;
	for(;i<N;i++){
		bak[A[i]]++;
	}
	int Max=bak[0];
	for(i=0;i<N;i++){
		if(bak[i]>Max)
			Max=bak[i];
	}
	if(Max>N/2)
	return Max;
	return -1;
}

int main(){
	int A[N]={0,5,5,3,5,1,5,7};
	printf("%d ",GetMainX(A));
} 

