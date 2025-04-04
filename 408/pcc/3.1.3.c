#include <stdio.h>
//循环左移
unsigned int circularLeftShift(unsigned int value, int n) {
    return (value << n) | (value >> (32 - n)); // 循环左移
}
//循环右移
unsigned int circularRightShift(unsigned int value, int n) {
    return (value >> n) | (value << (32 - n)); // 循环左移
}
int main(){
    unsigned int usi = 0x12345678; // 待循环移位的32位无符号整数
    int d=4;//移位距离（即一次循环移动几位）
    
    printf("Original value: 0x%x\n", usi);
    printf("Circular left shift by %d bits:0x%x\n",d,circularLeftShift(usi,d)); 
    printf("Circular right shift by %d bits:0x%x\n",d,circularRightShift(usi,d)); 
    return 0;
}