#include <stdio.h>
#define ARRAY_SIZE 7

int main(void){
    int array[ARRAY_SIZE] ={1,5,3,8,2,4,6};
    int pos;
    int result;
    int key = 3;

    result = -1;

    for(pos=0 ; pos<ARRAY_SIZE ; pos++){
        if(key == array[pos]){
            result = pos;
            break;
        } else{

        }
        
    }
    printf("result = %d\n",result);
    return 0;
}