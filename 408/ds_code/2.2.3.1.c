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


int DelMin(SeqList* P_L){
	if(P_L->length==0){
		printf("顺序表为空！\n");
		return -1;
	}
	int min=P_L->data[0],i=0,xb=0;
	for(;i<P_L->length;i++)
		if(P_L->data[i]<min){
			min=P_L->data[i];
			xb=i;	
		}
		if(ListDel(P_L,xb+1,&min))
		return min;
		return -1;
} 

int main(){
	SeqList L;
	InitList(&L);//&在C语言中是取地址的意思 
	ListInsert(&L,1,88);
	ListInsert(&L,2,75);
	ListInsert(&L,3,43);
	ListInsert(&L,4,19);
	ListInsert(&L,5,17);
	ListInsert(&L,6,19);
	ListInsert(&L,7,15);
	ListInsert(&L,8,98);
	ListInsert(&L,9,81);
	ListPrint(&L);
	printf("顺序表中最小的元素是%d",DelMin(&L));
//	int e=-1;
//	if(ListDel(&L,2,&e))
//		printf("删除的元素是%d\n",e);
//	else printf("删除失败！\n"); 
//	ListPrint(&L);
//	int mubiao=23;
//	int tar=-1;
//	tar=LocateElem(&L,mubiao);
//	if(tar!=-1)
//		printf("%d在顺序表中第%d个！\n",mubiao,tar);
//	else
//	printf("%d不在该顺序表中！",mubiao); 
} 
