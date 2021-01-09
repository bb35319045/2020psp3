#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int id;
    char name[19];  //  市の名前、UTF-8対応
    float members;  //  世帯人員
    int total;      //  食料合計
    int grain;      //  穀類
    int seafood;    //  魚介類
    int meat;       //  肉類
    int milk;       //  乳卵類
    int vegetable;  //  野菜類
    int fruit;      //  果物
    int seasoning;  //  調味料
    int snack;      //  菓子類
    int cocking;    //  調理料理
    int drink;      //  飲料
    int liquor;     //  酒類
    int eatout;     //  外食
} City;

#define DEBUG
#define MAX_CITY    47


void PrintCity(City city)
{
    printf("%d, %s, %.2f, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", 
        city.id, city.name, city.members, city.total, 
        city.grain, city.seafood, city.meat, city.milk, city.vegetable, city.fruit,
        city.seasoning, city.snack, city.cocking, city.drink, city.liquor, city.eatout);
}

void PrintArray(City city[], int size)
{
    int i;

    for (i=0; i<size; i++) {
        PrintCity(city[i]);
    }
}

int LoadData(City arrayCity[])
{
    char buf[256];
    FILE* fp;

    fp = fopen("consumption.csv","r");
    if(fp==NULL){
        fputs("File open error\n",stderr);
        return -1;
    }

    int cn = 0; // 市の数
    while(fgets(buf,sizeof(buf),fp) != NULL){
        sscanf(buf,"%d,%[^,],%f,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d", 
            &(arrayCity[cn].id), arrayCity[cn].name, &(arrayCity[cn].members), &(arrayCity[cn].total), 
            &(arrayCity[cn].grain),  &(arrayCity[cn].seafood),  &(arrayCity[cn].meat), &(arrayCity[cn].milk), 
            &(arrayCity[cn].vegetable),  &(arrayCity[cn].fruit),  &(arrayCity[cn].seasoning),  &(arrayCity[cn].snack),
            &(arrayCity[cn].cocking),  &(arrayCity[cn].drink),  &(arrayCity[cn].liquor),  &(arrayCity[cn].eatout));
#ifdef DEBUG
        PrintCity(arrayCity[cn]);
#endif
        cn++;
    }

    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        return -1;
    }

    return cn;
}


void BubbleSort(City arrayCity[], int size)
{
    int cnt;
    int pos;
    City array_tmp;
 
   while(1){
       cnt = 0;
       for(pos=0; pos<size-1; pos++){
         if(arrayCity[pos].total > arrayCity[pos+1].total){  
            array_tmp = arrayCity[pos];
            arrayCity[pos] = arrayCity[pos+1];
            arrayCity[pos+1] = array_tmp;
            cnt++;
         }  
       }
       if(cnt == 0){
           break;
       }
   }
}


void QuickSort(City arrayCity[], int left, int right)
{
    City pivot;
    City array_tmp;  

    int index_left;
    int index_right;
    int size = right - left;

    
    if(size > 0){
       pivot = arrayCity[left];  
            
       while(1){
         index_left = left;
         index_right = right;   
                
         while(pivot.seafood >= arrayCity[index_left].seafood){
            index_left++;       
         }
         while(pivot.seafood < arrayCity[index_right].seafood){
            index_right--;
         } 
         if(index_left >= index_right){
            break;
         }else{
            array_tmp = arrayCity[index_left];
            arrayCity[index_left] = arrayCity[index_right];
            arrayCity[index_right] = array_tmp;
         }
       }
      
       array_tmp = arrayCity[left];
       arrayCity[left] = arrayCity[index_right];
       arrayCity[index_right] = array_tmp;

       QuickSort(arrayCity, left, index_right-1);
       QuickSort(arrayCity, index_right+1, right);
    }
}


void ParticalHeap(City arrayCity[], int size, int node){
    int left;
    int right;
    int count = 0;
    City array_check;
    City array_tmp;

    left = node * 2 + 1;
    right = node * 2 + 2;

    array_check = arrayCity[node];

    if(left <= size){ 
        if(arrayCity[left].meat  < arrayCity[node].meat){
         array_check = arrayCity[left];
        }
    }
    
    if(right <= size){
       if(arrayCity[right].meat < array_check.meat){
         array_check = arrayCity[right];
         count++; 
       }
    }

    if(array_check.meat != arrayCity[node].meat){
        if(count == 1){
        array_tmp = arrayCity[right];
        arrayCity[right] = arrayCity[node];
        arrayCity[node] = array_tmp;
        ParticalHeap(arrayCity, size, right);
     }else{
        array_tmp = arrayCity[left];
        arrayCity[left] = arrayCity[node];
        arrayCity[node] = array_tmp;
        ParticalHeap(arrayCity, size, left); 
     }
}
}

void BuildHeap(City arrayCity[], int size){
 
 int last_node;
 int i;

 last_node = size /2 - 1;

 for(i=last_node; i>=0; i--){
    ParticalHeap(arrayCity, size, last_node);   
 }
}

void HeapSort(City arrayCity[], int size){
     int size_Heap;
     City array_tmp;
     BuildHeap(arrayCity, size);
     
     for(size_Heap=size; size_Heap>1; size_Heap--){
      array_tmp = arrayCity[0];
      arrayCity[0] = arrayCity[size-1];
      arrayCity[size-1] = array_tmp;

      BuildHeap(arrayCity, size-1);
    }
}

void Merge(City arrayCity[], int left, int mid, int right){
    int i,j,k;
    
    City left_buff[mid-left+1];
    City right_buff[right-mid];

    for (i = 0; i <= mid-left; i++){ 
     left_buff[i] = arrayCity[left+i]; 
    }

    for (j = 0; j < right-mid; j++){
      right_buff[j] = arrayCity[mid+1+j];
    }
    
    i = 0;
    j = 0;
    
  for (k = left; k <= right; k++) {
        if ((left_buff[i].liquor <= right_buff[j].liquor && i <= mid-left)||(j >= right-mid && i <= mid-left)){
            arrayCity[k] = left_buff[i];
            i++;
        }else{
            arrayCity[k] = right_buff[j];
            j++;
    }
  }
}


void MergeSort(City arrayCity[], int left, int right){
    int mid;
   
     if(right > left){
      mid = left+  (right - left) /2;
     
      MergeSort(arrayCity, left, mid);
      MergeSort(arrayCity, mid+1, right);

      Merge(arrayCity, left, mid, right);
   }
}

int main(void)
{
 
    //  事前準備。データの読み込み、配列の作成
    City* arrayCity;
    int cn;
    arrayCity = (City*)malloc(sizeof(City) * MAX_CITY);
    cn = LoadData(arrayCity);
    if (cn == -1) {
        exit(EXIT_FAILURE);
    }

    //  食料品合計で並び替え
    printf("===== Sorted by total =====\n");
    BubbleSort(arrayCity, MAX_CITY);
    PrintArray(arrayCity, MAX_CITY);

    //  魚介類で並び替え   
    printf("===== Sorted by seafood =====\n");
    QuickSort(arrayCity, 0, MAX_CITY - 1);
    PrintArray(arrayCity, MAX_CITY);

    //    HeapSort(arrayCity, MAX_CITY);
    printf("===== Sorted by meat =====\n");
    HeapSort(arrayCity, MAX_CITY);
    PrintArray(arrayCity, MAX_CITY);

    //    MerageSort(arrayCity, 0, MAX_CITY-1);
    printf("===== Sorted by liquor =====\n");
    MergeSort(arrayCity, 0, MAX_CITY - 1);
    PrintArray(arrayCity, MAX_CITY);

    //  後処理
    free(arrayCity);

    return 0;
}