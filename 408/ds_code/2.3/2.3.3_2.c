#include<stdio.h>
#include<stdbool.h>
//ѭ��˫������ 
typedef struct DNode{
	int data;
	struct DNode* next,*prior; 
}DNode,* DLinkList;

DLinkList InitDLinkList(){
	DLinkList L=(DNode*)malloc(sizeof(DNode));
	if(L==NULL) return NULL;
	L->next=L;
	L->prior=L;
	return L;
}

bool Empty(DLinkList L){
	if(L->next==L) return true;
	return false;
}

IsTail(DLinkList L,DNode* p){
	if(p->next==L) return true;
	return false;
}

bool InsertNextDNode(DNode* p,DNode* s){//��p���֮�����s 
	if(p->next==NULL){
		s->next=p->next;//�ȼ�Ϊs->next=NULL; 
		s->prior=p;
		p->next=s;
		return true;
	} else{
		s->next=p->next;//p�������ڵ� 
		p->next->prior=s;
		s->prior=p;
		p->next=s;
		return true;
	}
		
}

bool DelNextDNode(DNode* p){//��p���֮��ɾ��q 
	if(p->next==NULL) return false;
	DNode* q=p->next;
	if(q->next!=NULL){
		q->next->prior=p;
		p->next=q->next;
		free(q);
		return true;
	}else{
		p->next=q->next;
		free(q);
		return true;
	}
}

void DestoryList(DLinkList L){
	while(L->next!=NULL)
		DelNextDNode(L);
	free(L);
	return;
}

void ListPrint(DLinkList L){
	printf("List:");
	if(L->next==NULL||L==NULL){
		printf("����Ϊ�գ�\n");
		return;
	}
	DNode* q=L->next;
	while(q!=NULL){
		printf("%d ",q->data);
		q=q->next;
	}printf("\n");
	return;
		
}

int main(){
	DLinkList L=InitDLinkList();
	
	if(L) 
		printf("˫�����ʼ���ɹ���");
	else printf("ʧ�ܣ�"); 
	
	if(Empty(L)) 
		printf("˫����Ϊ�գ�");
	else printf("˫����ǿգ�"); 
	
	
		DNode* s=(DNode*)malloc(sizeof(DNode));
		s->data=rand()%100+1;
		if(InsertNextDNode(L,s))
			printf("����ڵ�s�ɹ���s->data=%d\n",s->data);
		else printf("����ڵ�sʧ�ܣ�"); 
		
		DNode* s1=(DNode*)malloc(sizeof(DNode));
		s1->data=rand()%100+1;
		if(InsertNextDNode(L,s1))
			printf("����ڵ�s1�ɹ���s1->data=%d\n",s1->data);
		else printf("����ڵ�s1ʧ�ܣ�"); 
		
		DNode* s2=(DNode*)malloc(sizeof(DNode));
		s2->data=rand()%100+1;
		if(InsertNextDNode(L,s2))
			printf("����ڵ�s2�ɹ���s2->data=%d\n",s2->data);
		else printf("����ڵ�s2ʧ�ܣ�"); 
		
		DNode* s3=(DNode*)malloc(sizeof(DNode));
		s3->data=rand()%100+1;
		if(InsertNextDNode(L,s3))
			printf("����ڵ�s3�ɹ���s3->data=%d\n",s3->data);
		else printf("����ڵ�s3ʧ�ܣ�"); 
	
	
	DelNextDNode(L);
	ListPrint(L);
	
	DelNextDNode(L);
	ListPrint(L);
	
	DestoryList(L);
	L=NULL;
	ListPrint(L);
	
	
} 
