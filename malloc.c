/*
 * Dynamic allocation of memory using malloc, calloc, free, realloc
 *
 * It is used for dynamically allocate array
 * For ex. As it can be seen that the length (size) of the array above made is 9. But what if there is a requirement to change this length 
 * If there is a situation where only 5 elements are needed to be entered in this array. In this case, the remaining 4 indices are just wasting memory in this array. So there is a requirement to lessen the length (size) of the array from 9 to 5.
 * Take another situation. In this, there is an array of 9 elements with all 9 indices filled. But there is a need to enter 3 more elements in this array. In this case, 3 indices more are required. So the length (size) of the array needs to be changed from 9 to 12.
 *
 */

// Malloc - ptr = (cast-type*) malloc(byte-size)

#include<stdio.h>
#include<stdlib.h>
int main(){
  int* ptr; //This pointer holds the base address of the block created
  int n, i;
  printf("Enter the number of element: ");
  scanf("%d",&n);
  printf("Entered number in the element: %d\n",n);

  ptr = (int*)malloc(n*sizeof(int));
  if(ptr == NULL){
    printf("Memory not allocated\n");
  }  
  else{
    printf("Memory successfully allocated using malloc");
    for(i=0;i<n;i++){
      ptr[i] = i+1;
    }
    printf("The element of the array are: ");
    for(i=0;i<n;i++){
      printf("%d, ",ptr[i]);
    }
  }
  return 0;
}
