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

void Delchongfu(SeqList* P_L){
	int i=1,k=1;
	for(;i<P_L->length;i++){
		if(P_L->data[i]!=P_L->data[i-1])
		P_L->data[k++]=P_L->data[i];
	}P_L->length=k;return;
}

int main(){
	SeqList L;
	InitList(&L);//&在C语言中是取地址的意思 
	ListInsert(&L,1,5);
	ListInsert(&L,2,6);
	ListInsert(&L,3,6);
	ListInsert(&L,4,6);
	ListInsert(&L,5,7);
	ListInsert(&L,6,7);
	ListInsert(&L,7,7);
	ListInsert(&L,8,8);
	ListInsert(&L,9,8);
	ListInsert(&L,10,9);
	ListInsert(&L,11,10);
	ListPrint(&L); 
	Delchongfu(&L);
//	DelT(&L,19);//删除顺序表中所有特定值 
	ListPrint(&L);

} 
