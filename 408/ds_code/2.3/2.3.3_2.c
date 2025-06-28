#include<stdio.h>
#include<stdbool.h>
//循环双链表！！ 
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

bool InsertNextDNode(DNode* p,DNode* s){//在p结点之后插入s 
	if(p->next==NULL){
		s->next=p->next;//等价为s->next=NULL; 
		s->prior=p;
		p->next=s;
		return true;
	} else{
		s->next=p->next;//p不是最后节点 
		p->next->prior=s;
		s->prior=p;
		p->next=s;
		return true;
	}
		
}

bool DelNextDNode(DNode* p){//在p结点之后删除q 
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
		printf("链表为空！\n");
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
		printf("双链表初始化成功！");
	else printf("失败！"); 
	
	if(Empty(L)) 
		printf("双链表为空！");
	else printf("双链表非空！"); 
	
	
		DNode* s=(DNode*)malloc(sizeof(DNode));
		s->data=rand()%100+1;
		if(InsertNextDNode(L,s))
			printf("插入节点s成功，s->data=%d\n",s->data);
		else printf("插入节点s失败！"); 
		
		DNode* s1=(DNode*)malloc(sizeof(DNode));
		s1->data=rand()%100+1;
		if(InsertNextDNode(L,s1))
			printf("插入节点s1成功，s1->data=%d\n",s1->data);
		else printf("插入节点s1失败！"); 
		
		DNode* s2=(DNode*)malloc(sizeof(DNode));
		s2->data=rand()%100+1;
		if(InsertNextDNode(L,s2))
			printf("插入节点s2成功，s2->data=%d\n",s2->data);
		else printf("插入节点s2失败！"); 
		
		DNode* s3=(DNode*)malloc(sizeof(DNode));
		s3->data=rand()%100+1;
		if(InsertNextDNode(L,s3))
			printf("插入节点s3成功，s3->data=%d\n",s3->data);
		else printf("插入节点s3失败！"); 
	
	
	DelNextDNode(L);
	ListPrint(L);
	
	DelNextDNode(L);
	ListPrint(L);
	
	DestoryList(L);
	L=NULL;
	ListPrint(L);
	
	
} 
