#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define InitSize 100

typedef struct{
	int *data;
	int MaxSize,length; 
}SeqList;

void InitList(SeqList *P_L){//顺序表初始化 
	P_L->data=(int*)malloc(InitSize*sizeof(int));//P_L.data不能用 
	P_L->length=0; 
	P_L->MaxSize=InitSize;
}

bool ListInsert(SeqList *P_L,int i,int e){//第i个位置插入新元素e 
	if(i<1||i>(P_L->length+1))//判断第i个位置是否合法，1<=i<=(length+1)
		return false;
	if(P_L->length>=P_L->MaxSize)//判断顺序表长度是否小于MaxSize空间大小 
		return false;
		int j=(P_L->length);
	for(;j>=i;j--){
		P_L->data[j]=P_L->data[j-1];
	}
	P_L->data[i-1]=e;
	P_L->length++;
	return true;
} 

void ListPrint(SeqList *P_L){//遍历顺序表内容 
	if(P_L->length==0){
		printf("顺序表为空！");
		return; 
	}
	int i=0;
	printf("顺序表内容："); 
	for(;i<P_L->length;i++)
		printf("%d ",P_L->data[i]);
	printf("\n"); 	
	return;	
}

bool ListDel(SeqList* P_L,int i,int* e){//删除第i个位置的元素 
	if(i<1||i>P_L->length)
		return false;
	*e=P_L->data[i-1];
	int j=i;
	for(;j<P_L->length;j++){
		P_L->data[j-1]=P_L->data[j];
	}
	P_L->length--;
	return true;
} 

void DoubleOne(SeqList* P_L,SeqList* P_R,SeqList* ans){
	ans->data=(int*)malloc((P_L->length+P_R->length)*sizeof(int));//P_L.data不能用 
	ans->length=0; 
	ans->MaxSize=(P_L->length+P_R->length);
	int i=0,j=0,k=0;
	for(;k<ans->MaxSize;){
		if(i<P_L->length&&j<P_R->length)
			if(P_L->data[i]<P_R->data[j]){
				ans->data[k++]=P_L->data[i++];ans->length++;
			}
			else{
				ans->data[k++]=P_R->data[j++];ans->length++;
			}
		else break; 
	}
	for(;i<P_L->length;){
		ans->data[k++]=P_L->data[i++];ans->length++;
	}
	for(;j<P_R->length;){
		ans->data[k++]=P_R->data[j++];ans->length++;
	}
	return;
}

int main(){
	SeqList L;
	SeqList R;
	InitList(&L);//&在C语言中是取地址的意思 
	InitList(&R);
	ListInsert(&L,1,15);
	ListInsert(&L,2,13);
	ListInsert(&L,3,11);
	ListInsert(&L,4,9);
	ListInsert(&L,5,7);
	ListInsert(&L,6,4);
	ListInsert(&R,1,59);
	ListInsert(&R,2,55);
	ListInsert(&R,3,43);
	ListInsert(&R,4,14);
	ListInsert(&R,5,3);
	ListInsert(&R,6,2);
	ListInsert(&R,7,0);
	ListInsert(&R,8,-1);
	ListInsert(&R,9,-2);
	ListInsert(&R,10,-10);
	ListPrint(&L); 
	ListPrint(&R);
	SeqList ans;                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
	DoubleOne(&L,&R,&ans);
	ListPrint(&ans);

} 
