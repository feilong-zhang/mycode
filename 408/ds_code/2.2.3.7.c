#include <stdio.h>
#include <stdlib.h>

#define M 10
#define N 15

void ListSwap(int* a,int m,int n){
	int b[m],i=0,k=0,j=0,z=0;
	for(;i<m;i++){
		b[k++]=a[i];
	}
//	printf("b[]:\n");
//	for(z=0;z<k;z++){
//		printf("%d ",b[z]);
//	}printf("\n");
//	for(z=0;z<M+N;z++){
//		printf("%d ",a[z]);
//	}printf("\n");
	for(;i<m+n;i++){
		a[j++]=a[i];
	}
//	for(z=0;z<M+N;z++){
//		printf("%d ",a[z]);
//	}printf("\n");
	for(i=0;i<k&&j<m+n;i++){
		a[j++]=b[i];
	}
}

int main(){
	int a[M+N];
	int i=0;
	for(;i<M+N;i++){
		a[i]=rand()%100+1;
	}
	for(i=0;i<M+N;i++){
		printf("%d ",a[i]);
	}printf("\n");
	ListSwap(a,M,N);
	for(i=0;i<M+N;i++){
		printf("%d ",a[i]);
	}
}
