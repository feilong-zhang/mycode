#include<stdio.h>
#include<stdbool.h>
//ѭ�������� ���� 
typedef struct LNode{
	int data;
	struct LNode* next; 
}LNode,* LinkList;

LinkList InitList(){//��ʼ�� ��ͷ�ڵ� 
	LNode* L=(LNode*)malloc(sizeof(LNode));//L=NULL; ����ͷ��� ֱ�� return true;
	if(L==NULL) return L;
	L->next=L;//ѭ�������� 
	return L;
}

bool Empty(LinkList L) {
	if(L->next==L)
		return true;
	else 
		return false;
}

bool IsTail(LinkList L,LNode* p){
	if(p->next==L)
		return true;
	return false;
}

int Length(LinkList L){
	int len=0;
	LNode* p=L;
	while(p->next!=NULL){
		p=p->next;
		len++;
	}return len;
}

LNode* GetElem(LinkList L,int i){//��ȡ��i�����ĵ�ַ 
	LNode* p=L;
	int j=0;
	while(p!=NULL&&j<i){
		p=p->next;
		j++;
	}return p;
}

LNode* LocateElem(LinkList L,int e){//����ָ��ֵ 
	LNode* p=L->next;
	while(p!=NULL&&p->data!=e)
		p=p->next;
	return p;//����������e�򷵻�NULL 
}

bool ListInsert(LinkList L,int i,int e){
	LNode* p=L;
	int j=0;
	while(p!=NULL&&j<i-1){
		p=p->next;
		j++;
	}
	if(j!=i-1) return false;//����i���������� 
	LNode* s=(LNode*)malloc(sizeof(LNode));
	if(s==NULL) return false;//�����ڴ����ʧ��
	s->data=e;
	s->next=p->next;
	p->next=s;
	return true;
} 

bool DelLNode(LinkList L,int i,int* e){//ɾ�������е�i���ڵ� 
	int j=0;
	LNode* p=L;
	while(p->next!=NULL&&j<i-1){
		p=p->next;
		j++;
	}//��ѭ��ʱj==i-1 
	if(p->next==NULL||j!=i-1)//j != i-1 ˵��û�������ҵ���i-1����㣨�Ƿ�λ�ã�
		return false;// p->next == NULL ˵����i����㲻���ڣ�Խ�磩  
	LNode* s=p->next;
	(*e)=s->data;
	p->next=p->next->next;
	free(s);return true;
}

LinkList ListHeadInsert(LinkList L){
	int input=-1;
	printf("������Ҫ��������ݣ�");
	scanf("%d",&input);
	LNode* p=L,*s=NULL;
	while(input!=9999){
		s=(LNode*)malloc(sizeof(LNode));
		if(s==NULL) return NULL;//�ڴ������� 
		s->next=p->next;
		s->data=input;
		p->next=s;	
		printf("������Ҫ��������ݣ�");
		scanf("%d",&input);
	}
	return L;
}

LinkList ListTailInsert(LinkList L){
	int input=-1;
	printf("������Ҫ��������ݣ�");
	scanf("%d",&input);
	LNode* r=L,*s=NULL;//r��ֵ�����һ�����ݽڵ�ĵ�ַ 
	while(input!=9999){
		s=(LNode*)malloc(sizeof(LNode));
		if(s==NULL) return NULL;
		s->data=input;
		s->next=NULL;//s->next=r->next; 
		r->next=s;
		r=s;
		printf("������Ҫ��������ݣ�");
		scanf("%d",&input);
	}return L;
}

void ListPrint(LinkList L){
	printf("List:");
	for(L=L->next;L!=NULL;L=L->next)
		printf("%d ",L->data);
	printf("\n");
	return;
}

void DestroyList(LinkList* L){
	LNode* temp,* R=(*L);
	for(;R!=NULL;){
		temp=R;
		R=R->next;
		free(temp);
	}
	(*L)=NULL;
	return;
}

int main(){
	  LinkList L=InitList(); 
    if(L==NULL){
        printf("�����ʼ��ʧ�ܣ�\n");
        return -1;
    }
    //ͷ�巨����
	ListHeadInsert(L); 
    ListPrint(L);
    
//    // β�巨����
//    ListTailInsert(L);
//    ListPrint(L);

    // ���Բ���
    if(ListInsert(L, 1, 123)){
        printf("�ڵ�1��λ�ò���123��: ");
        ListPrint(L);
    } else {
        printf("����ʧ�ܣ�\n");
    }

    // ����ɾ��
    int val;
    if(DelLNode(L, 2, &val)){
        printf("ɾ����2��Ԫ�أ�ֵΪ%d����: ", val);
        ListPrint(L);
    } else {
        printf("��2��Ԫ��ɾ��ʧ�ܣ�\n");
    }

    // ���԰��±����
    LNode* p = GetElem(L, 2);
    if(p) printf("��2������ֵΪ: %d\n", p->data);
    else printf("δ�ҵ���2�����\n");

    // ���԰�ֵ����
    p = LocateElem(L, 123);
    if(p) printf("�ҵ�ֵΪ123�Ľ��\n");
    else printf("δ�ҵ�ֵΪ123�Ľ��\n");

    // ����������
    printf("������Ϊ: %d\n", Length(L));

    // ��������
    DestroyList(&L);
    printf("����������\n");
    return 0;
	
} 
