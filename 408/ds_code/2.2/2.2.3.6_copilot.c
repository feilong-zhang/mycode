#include <stdio.h>
#include <stdlib.h>

#define InitSize 100

typedef struct {
    int *data;
    int length;
    int MaxSize;
} SeqList;

// 顺序表初始化
void InitList(SeqList *L) {
    L->data = (int *)malloc(InitSize * sizeof(int));
    L->length = 0;
    L->MaxSize = InitSize;
}

// 顺序表插入
void ListInsert(SeqList *L, int pos, int elem) {
    if (pos < 1 || pos > L->length + 1) return;
    if (L->length >= L->MaxSize) return;
    int j = L->length;
    for (; j >= pos; j--)
        L->data[j] = L->data[j - 1];
    L->data[pos - 1] = elem;
    L->length++;
}

// 顺序表打印
void ListPrint(const SeqList *L) {
	int i = 0;
    for (; i < L->length; i++)
        printf("%d ", L->data[i]);
    printf("\n");
}

// 合并两个有序顺序表，返回新顺序表
SeqList MergeSeqList(const SeqList *A, const SeqList *B) {
    SeqList C;
    C.data = (int *)malloc((A->length + B->length) * sizeof(int));
    C.length = 0;
    C.MaxSize = A->length + B->length;
    int i = 0, j = 0, k = 0;
    while (i < A->length && j < B->length) {
        if (A->data[i] <= B->data[j])
            C.data[k++] = A->data[i++];
        else
            C.data[k++] = B->data[j++];
    }
    while (i < A->length)
        C.data[k++] = A->data[i++];
    while (j < B->length)
        C.data[k++] = B->data[j++];
    C.length = k;
    return C;
}

int main() {
    SeqList A, B;
    InitList(&A);
    InitList(&B);

    // 假设顺序表A和B已经有序，插入数据
    ListInsert(&A,1,15);
	ListInsert(&A,2,13);
	ListInsert(&A,3,11);
	ListInsert(&A,4,9);
	ListInsert(&A,5,7);
	ListInsert(&A,6,4);
	
	ListInsert(&B,1,59);
	ListInsert(&B,2,55);
	ListInsert(&B,3,43);
	ListInsert(&B,4,14);
	ListInsert(&B,5,3);
	ListInsert(&B,6,2);
	ListInsert(&B,7,0);
	ListInsert(&B,8,-1);
	ListInsert(&B,9,-2);
	ListInsert(&B,10,-10);

    printf("A: ");
    ListPrint(&A);
    printf("B: ");
    ListPrint(&B);

    SeqList C = MergeSeqList(&A, &B);

    printf("Merged: ");
    ListPrint(&C);

    // 释放内存
    free(A.data);
    free(B.data);
    free(C.data);

    return 0;
}
