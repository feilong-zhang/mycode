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

void TriJiao(SeqList* P_A,SeqList* P_B,SeqList* P_C){
	int i=0,j=0,k=0;
	for(;i<P_A->length&&j<P_B->length&&k<P_C->length;){
		if(P_A->data[i]==P_B->data[j]&&P_A->data[i]==P_C->data[k]){
			printf("%d\n",P_A->data[i]);
			i++;j++;k++;continue;
		}
		else if(P_A->data[i]<P_B->data[j])
			i++;
		else if(P_B->data[j]<P_C->data[k])
			j++;
		else
			k++;
	}return;
}
void TriJiao2(SeqList* P_A,SeqList* P_B,SeqList* P_C){
	int i=0,j=0,k=0;
	for(;i<P_A->length&&j<P_B->length&&k<P_C->length;){
		if(P_A->data[i]==P_B->data[j]&&P_A->data[i]==P_C->data[k]){
			printf("%d\n",P_A->data[i]);
			i++;j++;k++;continue;
		}
		if(P_A->data[i]>P_B->data[j])
			j++;
		else if(P_A->data[i]>P_C->data[k]) 
			k++;
		else i++;
	}return;
}

int main(){
	SeqList A;
	InitList(&A);//&��C��������ȡ��ַ����˼ 
	ListInsert(&A,1,1);
	ListInsert(&A,2,3);
	ListInsert(&A,3,5);
	ListInsert(&A,4,9);
	ListInsert(&A,5,11);
	ListInsert(&A,6,13);
	
	SeqList B;
	InitList(&B);//&��C��������ȡ��ַ����˼ 
	ListInsert(&B,1,1);
	ListInsert(&B,2,3);
	ListInsert(&B,3,4);
	ListInsert(&B,4,8);
	ListInsert(&B,5,9);
	ListInsert(&B,6,13);
	
	SeqList C;
	InitList(&C);//&��C��������ȡ��ַ����˼ 
	ListInsert(&C,1,1);
	ListInsert(&C,2,3);
	ListInsert(&C,3,5);
	ListInsert(&C,4,7);
	ListInsert(&C,5,10);
	ListInsert(&C,6,13);
	
	ListPrint(&A); 
	ListPrint(&B); 
	ListPrint(&C);
	TriJiao2(&A,&B,&C);

} 
