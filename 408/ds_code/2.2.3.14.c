#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define N 3



int D(int a,int b,int c){
	int ab=0,ac=0,bc=0;
	if(a-b<0)
		ab=b-a;
	else 
		ab=a-b;
	if(a-c<0)
		ac=c-a;
	else
		ac=a-c;
	if(b-c<0)
		bc=c-b;
	else
		bc=b-c;
	return ab+bc+ac;
}

int MinD(int* S1,int a,int* S2,int b,int* S3,int c){
	int min=D(S1[0],S2[0],S3[0]),i=0,j=0,k=0;//printf("%d ",min);
	for(;i<a;i++){
		for(j=0;j<b;j++){
			for(k=0;k<c;k++){
				if(D(S1[i],S2[j],S3[k])<min)
					min=D(S1[i],S2[j],S3[k]);
				//printf("%d ",min);
			}
		}
	}
	
	return min;
}

int main(){
	int S1[3]={-1,0,9},S2[4]={-25,-10,10,11},S3[5]={2,9,17,30,41};
	printf("%d",MinD(S1,3,S2,4,S3,5));
} 

