/* Selection sort
 * set min to the first location
 * search min number in array
 * then swap the first number with the minimum value in the array
 * assign the second element to min
 * repeat
 */

#include<stdio.h>
int main(){
  int a[100],n,i,temp,pass,c, swap;
  printf("Enter how many number you want to enter? :");
  scanf("%d",&n);
  for(i=0;i<n;i++){
    printf("Enter %dst number: ", i+1);
    scanf("%d",&a[i]);
  }

  // Selection sort
  for(i=0;i<(n-1);i++){ // total n-1 pass requires
    temp = i; // set temp = i, first position
    for(c=i+1;c<n;c++){ // set second position
      if(a[temp] > a[c]){ // check the codition
        temp = c; // set value
      }
    }
    if(temp != i){ // swap method
      swap = a[i];
      a[i] = a[temp];
      a[temp] = swap;
    }
  }
  printf("Sorted list: ");
  for(i=0;i<n;i++){
    printf("%d\t", a[i]);
  }
  return 0;

}
