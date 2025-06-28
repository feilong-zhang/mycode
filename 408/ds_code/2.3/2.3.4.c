#include<stdio.h>
#include<stdbool.h>
//循环单链表 ！！ 
typedef struct LNode{
	int data;
	struct LNode* next; 
}LNode,* LinkList;

LinkList InitList(){//初始化 带头节点 
	LNode* L=(LNode*)malloc(sizeof(LNode));//L=NULL; 不带头结点 直接 return true;
	if(L==NULL) return L;
	L->next=L;//循环单链表 
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

LNode* GetElem(LinkList L,int i){//获取第i个结点的地址 
	LNode* p=L;
	int j=0;
	while(p!=NULL&&j<i){
		p=p->next;
		j++;
	}return p;
}

LNode* LocateElem(LinkList L,int e){//查找指定值 
	LNode* p=L->next;
	while(p!=NULL&&p->data!=e)
		p=p->next;
	return p;//若链表中无e则返回NULL 
}

bool ListInsert(LinkList L,int i,int e){
	LNode* p=L;
	int j=0;
	while(p!=NULL&&j<i-1){
		p=p->next;
		j++;
	}
	if(j!=i-1) return false;//考虑i大于链表长度 
	LNode* s=(LNode*)malloc(sizeof(LNode));
	if(s==NULL) return false;//考虑内存分配失败
	s->data=e;
	s->next=p->next;
	p->next=s;
	return true;
} 

bool DelLNode(LinkList L,int i,int* e){//删除链表中第i个节点 
	int j=0;
	LNode* p=L;
	while(p->next!=NULL&&j<i-1){
		p=p->next;
		j++;
	}//出循环时j==i-1 
	if(p->next==NULL||j!=i-1)//j != i-1 说明没有正好找到第i-1个结点（非法位置）
		return false;// p->next == NULL 说明第i个结点不存在（越界）  
	LNode* s=p->next;
	(*e)=s->data;
	p->next=p->next->next;
	free(s);return true;
}

LinkList ListHeadInsert(LinkList L){
	int input=-1;
	printf("请输入要插入的数据：");
	scanf("%d",&input);
	LNode* p=L,*s=NULL;
	while(input!=9999){
		s=(LNode*)malloc(sizeof(LNode));
		if(s==NULL) return NULL;//内存分配错误 
		s->next=p->next;
		s->data=input;
		p->next=s;	
		printf("请输入要插入的数据：");
		scanf("%d",&input);
	}
	return L;
}

LinkList ListTailInsert(LinkList L){
	int input=-1;
	printf("请输入要插入的数据：");
	scanf("%d",&input);
	LNode* r=L,*s=NULL;//r的值是最后一个数据节点的地址 
	while(input!=9999){
		s=(LNode*)malloc(sizeof(LNode));
		if(s==NULL) return NULL;
		s->data=input;
		s->next=NULL;//s->next=r->next; 
		r->next=s;
		r=s;
		printf("请输入要插入的数据：");
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
        printf("链表初始化失败！\n");
        return -1;
    }
    //头插法建表
	ListHeadInsert(L); 
    ListPrint(L);
    
//    // 尾插法建表
//    ListTailInsert(L);
//    ListPrint(L);

    // 测试插入
    if(ListInsert(L, 1, 123)){
        printf("在第1个位置插入123后: ");
        ListPrint(L);
    } else {
        printf("插入失败！\n");
    }

    // 测试删除
    int val;
    if(DelLNode(L, 2, &val)){
        printf("删除第2个元素（值为%d）后: ", val);
        ListPrint(L);
    } else {
        printf("第2个元素删除失败！\n");
    }

    // 测试按下标查找
    LNode* p = GetElem(L, 2);
    if(p) printf("第2个结点的值为: %d\n", p->data);
    else printf("未找到第2个结点\n");

    // 测试按值查找
    p = LocateElem(L, 123);
    if(p) printf("找到值为123的结点\n");
    else printf("未找到值为123的结点\n");

    // 测试链表长度
    printf("链表长度为: %d\n", Length(L));

    // 销毁链表
    DestroyList(&L);
    printf("链表已销毁\n");
    return 0;
	
} 
