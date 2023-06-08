#include <iostream> 
using namespace std; 
#include <ctime> 
const int NUM = 50000; 

 void fillarr(int* arr, int SIZE) {  
   srand(time(NULL)); 
 for (int i = 0; i < SIZE; i++) {  
   arr[i] = rand() % 100; 
 } 
 }  

int findpivot(int* arr, int SIZE, int i, int j){  
  int firstkey = i; 
 int pivot = arr[firstkey]; 
 while (i < j) {   
   while (i < SIZE && arr[i] <= pivot) {    i++; }   
   while (arr[j] > pivot) {    j--; } 
   if (i < j) {   
     swap(arr[i], arr[j]);  } 
 }  
  swap(arr[firstkey], arr[j]); 
 return j; 
} 

int partition(int* arr, int l, int r, int pivot) {  
  int pivotValue = arr[pivot]; 
 swap(arr[pivot], arr[r]); 
 int storeIndex = l; 
 for (int i = l; i < r; i++) {  
   if (arr[i] < pivotValue) {    
     swap(arr[i], arr[storeIndex]); 
   storeIndex++; 
  } 
 }  
  swap(arr[storeIndex], arr[r]); 
 return storeIndex; 
}  

void quicksort(int *arr, int SIZE, int i, int j) {  
  int *stack=new int[SIZE]; 
 int top = -1; 
 stack[++top] = i; 
 stack[++top] = j; 
  while (top >= 0) {   j = stack[top--]; 
  i = stack[top--]; 
   int pivotindex = findpivot(arr, SIZE, i, j); 
   if (pivotindex - 1 > i) {    
     stack[++top] = i; 
   stack[++top] = pivotindex - 1; 
  }    
   if (pivotindex + 1 < j) {    
     stack[++top] = pivotindex + 1; 
   stack[++top] = j; 
  }  
                   } 
} 

void vsort(int* arr, int SIZE) { 
  for (int i = 0; i < SIZE; i++) {   
    int j = i; 
  while (arr[j] < arr[j - 1]) {    
    swap(arr[j], arr[j - 1]); 
   if (--j == 0)     break; 
  }  
  } 
}  

void RestoreArray(int *arr1, int* arr2) {  
  for (int i = 0; i < NUM; i++)   
    arr1[i] = arr2[i]; 
}  

int A[NUM], B[NUM]; 

 int main() {  
   fillarr(B, NUM); 
 double qsum = 0, vsum = 0; 
 RestoreArray(A, B); 
 clock_t begt, endt; 
 for (int i = 0; i < 5; i++) {  
  begt = clock(); 
  quicksort(A, NUM, 0, NUM - 1); 
  endt = clock(); 
  RestoreArray(A, B); 
  qsum += (endt - begt); 
 } 
  cout<<"time of quick sort= "<<qsum/5<<endl; 
 RestoreArray(A, B); 
 for (int i = 0; i < 5; i++) {   
  begt = clock(); 
  vsort(A, NUM); 
  endt = clock(); 
  RestoreArray(A, B); 
  vsum += (endt - begt); 
 } 
   cout << "time of vstavka sort= " << vsum/5; 
 return 0; 
}
