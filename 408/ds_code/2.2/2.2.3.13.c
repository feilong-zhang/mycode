#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define N 3

int GetMissMin(int* A){
	int bak[N+2]={0},i=0;
	for(;i<N;i++){
		if(A[i]>0&&A[i]<=N)
			bak[A[i]]=1;
	}
	for(i=1;i<N+2;i++){
		if(bak[i]==0)
		return i;
	}
}

int main(){
	int A[N]={1,2,3};
	printf("%d",GetMissMin(A));
} 

