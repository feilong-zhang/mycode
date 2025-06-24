#include<stdio.h>

//void MySizeof(int arr[],int* a){
//	printf("MySizeof sizeof(arr)=%d \nMySizeof sizeof(a)=%d \n",sizeof(arr),sizeof(a));
//}

int main(){
	int arr[5]={0},*p;
	p=arr;
	printf("sizeof(int)=%d\n",sizeof(int));
	printf("arr=%p\n p=%p\n",arr,p);
	printf("sizeof(int*)=%d\n",sizeof(int*));
	printf("sizeof(arr)=%d\n sizeof(p)=%d",sizeof(arr),sizeof(p));
//	MySizeof(arr,arr);
//	printf("main sizeof(arr)=%d \nmain sizeof(&arr[0])=%d",sizeof(arr),sizeof(&arr[0]));
} 
