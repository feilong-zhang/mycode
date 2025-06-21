#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define InitSize 100

typedef struct{
	int *data;
	int MaxSize,length; 
}SeqList;

void InitList(SeqList *P_L){//˳����ʼ�� 
	P_L->data=(int*)malloc(InitSize*sizeof(int));//P_L.data������ 
	P_L->length=0; 
	P_L->MaxSize=InitSize;
}

bool ListInsert(SeqList *P_L,int i,int e){//��i��λ�ò�����Ԫ��e 
	if(i<1||i>(P_L->length+1))//�жϵ�i��λ���Ƿ�Ϸ���1<=i<=(length+1)
		return false;
	if(P_L->length>=P_L->MaxSize)//�ж�˳������Ƿ�С��MaxSize�ռ��С 
		return false;
		int j=(P_L->length);
	for(;j>=i;j--){
		P_L->data[j]=P_L->data[j-1];
	}
	P_L->data[i-1]=e;
	P_L->length++;
	return true;
} 

void ListPrint(SeqList *P_L){//����˳������� 
	if(P_L->length==0){
		printf("˳���Ϊ�գ�");
		return; 
	}
	int i=0;
	printf("˳������ݣ�"); 
	for(;i<P_L->length;i++)
		printf("%d ",P_L->data[i]);
	printf("\n"); 	
	return;	
}

bool ListDel(SeqList* P_L,int i,int* e){//ɾ����i��λ�õ�Ԫ�� 
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

void LocateX(SeqList* P_L,int x){
	int i=0,j=0,k=0;
	for(;i<P_L->length;i++){
		if(P_L->data[i]>=x){
			if(P_L->data[i]==x){
				int mid=P_L->data[i+1];
				P_L->data[i+1]=x;
				P_L->data[i]=mid;return;
			}
			else{
				for(j=P_L->length;j>=i;j--){
					P_L->data[j]=P_L->data[j-1];
				}P_L->data[i]=x;P_L->length++;return;
			}
			
		}
	}
}

int main(){
	SeqList L;
	
	InitList(&L);//&��C��������ȡ��ַ����˼ 
	
	ListInsert(&L,1,1);
	ListInsert(&L,2,3);
	ListInsert(&L,3,5);
	ListInsert(&L,4,9);
	ListInsert(&L,5,11);
	ListInsert(&L,6,13);
	
	ListPrint(&L); 
	LocateX(&L,8);
	ListPrint(&L);
	LocateX(&L,8);
	ListPrint(&L);

} 
