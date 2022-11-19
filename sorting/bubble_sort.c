/*
 * Bubble sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in worng order
 * It swaps the elements
 */

#include<stdio.h>

int main(){
  int a[100],i=0,c,pass=0,n,temp;
  printf("How many number are u going to enter?: ");
  scanf("%d",&c);
  for(i=0;i<c;i++){
    printf("Enter %dst number: ",i+1);
    scanf("%d",&a[i]);
  }
  // Bubble sort
  for(pass=0;pass<c-1;pass++){ // If c=5, then total passes = 4
    for(i=0;i<c-pass-1;i++){ // Show How many swap we need, if its 1st pass means pass=0 then 5-0-1 4 swaps after that pass = 1 then 5-1-1 total 3 passes and so on.
      if(a[i]>a[i+1]){
        temp = a[i];
        a[i] = a[i+1];
        a[i+1] = temp;
      }
    }
  }
  printf("In assesnding order: ");
  for(i=0;i<c;i++){
    printf("%d\t",a[i]);
  }
}
