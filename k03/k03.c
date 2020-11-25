#include <stdio.h>

#define DEBUG

#define ALPHABET_LEN    255

char StrOriginal[] = "On a dark deseart highway, cool wind in my hair.";
char StrKey[] = "wind";

char* ForceSearch(char text[], char key[])
{
  int pos = 0;
  int start = 0;
  int Original_len = 0;
  int Key_len = 0;

  while(StrOriginal[Original_len] != '\0'){
      Original_len++;
    }
  
  while(StrKey[Key_len] != '\0'){
      Key_len++;
    }

  while(1){
  if(key[pos] == text[start+pos]){
      pos++;
     }else if(key[pos] == '\0'){
       return &text[start];
       break;
     }else{
       if((Key_len + start) > Original_len){
          return NULL;
          break;
     }else{
      start++;
      pos = 0;
    }
  }
 }
}

char* BMSearch(char text[], char key[])
{ 
  int Original_index = 0;
  int Key_index = 0;
  int table[ALPHABET_LEN];
  int Original_len = 0;
  int Key_len = 0;
  int i;
  int u;

  
 while(StrOriginal[Original_len] != '\0'){
      Original_len++;
    }
  
 while(StrKey[Key_len] != '\0'){
      Key_len++;
    }

  for(i = 0; i <= ALPHABET_LEN; i++){
    table [i] = Key_len;
  }

  for(u = 0; u < Key_len; u++){
    table [key[u]] =  Key_len - (u + 1);
  }

  Original_index = Key_len - 1;
  Key_index = Key_len - 1;
  

  while(1){
  if(key[Key_index] == text[Original_index]){
     if(Key_index == 0){
        return &text[Original_index];
        break;
     }else{
    Key_index--;
    Original_index--;
     }
  }else{
     if(Original_index > Original_len){
        return NULL;
        break;
     }else{
        Original_index = Original_index + table[text[Original_index]];
        Key_index = Key_len - 1;
   }
  }
 }
}


int main(void)
{
    char*   str;
    str = ForceSearch(StrOriginal, StrKey);
    printf("Force Search. Find keyword at: %s\n", str);

    str = BMSearch(StrOriginal, StrKey);
    printf("BM Search. Find keyword at: %s\n", str);

    return 0;
}