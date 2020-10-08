#include <stdio.h>
#define ARRAY_SIZE 7

int main(void){
    int array[ARRAY_SIZE] ={1,2,3,4,5,6,8};
    int pos;
    int result;
    int key = 3;
    int left, right;

    result = -1;
    left = 0;
    right = ARRAY_SIZE - 1;

    while(left <= right){
        pos = left + (right - left) / 2;
        if(key == array[pos]){
            result = pos;
            break;
     } else if(key > array[pos]){
            left = pos + 1; 
     } else{
            right = pos - 1;
     }
    }

    printf("result = %d\n",result);
    
    return 0;
}