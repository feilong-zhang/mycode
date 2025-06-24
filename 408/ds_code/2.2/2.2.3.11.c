#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define L 5

int Mid(int* S1,int* S2){
	int i=0,j=0,k=0,ans=0;
	for(;i<L&&j<L;k++){
		if(k==L)
			return ans;
		if(S1[i]<S2[j]){
			ans=S1[i];printf("ans=%d k=%d\n",ans,k);i++;
		}
		else{
			ans=S2[j];printf("ans=%d k=%d\n",ans,k);j++;
		}	
	}
}

int main(){
	int S1[L]={11,13,15,17,19},S2[L]={2,4,6,8,20};
	printf("%d",Mid(S1,S2));
} 

