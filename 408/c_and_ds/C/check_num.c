#include<stdio.h>
int IsAllDigit(char p[]);
IsAllDigit(char p[]){
    int i=0;
for(;p[i]!='\0'&&i<21;i++){
    if(!(p[i]>='0'&&p[i]<='9'))
    return 0;
}return 1;
}
int main()
{
    char arr[21];
    printf("Please input a string:");
    gets(arr);
   // printf("The string is %s\n",arr);
if(IsAllDigit(arr))
printf("The string is digit string.");
else
printf("The string is not digit string.");
}