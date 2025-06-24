#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define N 3

int Max(int a,int b){
	if(a>b)
	return a;
	return b;
} 
int Min(int a,int b){
	if(a>b)
	return b;
	return a;
} 

int D(int a,int b,int c){
	return (Max(a,Max(b,c))-Min(a,Min(b,c)))*2;
}

int MinD(int* S1,int a,int* S2,int b,int* S3,int c){
	int min=D(S1[0],S2[0],S3[0]),i=0,j=0,k=0;//printf("%d ",min);
	for(;i<a&&j<b&&k<c;){
		if(D(S1[i],S2[j],S3[k])<min)
			min=D(S1[i],S2[j],S3[k]);
		if(Min(S1[i],Min(S2[j],S3[k]))==S1[i])
			i++;
		else if(Min(S1[i],Min(S2[j],S3[k]))==S2[j])
			j++;
		else k++;
	}
	
	return min;
}

int main(){
	int S1[3]={-1,0,9},S2[4]={-25,-10,10,11},S3[5]={2,9,17,30,41};
	printf("%d",MinD(S1,3,S2,4,S3,5));
} 

