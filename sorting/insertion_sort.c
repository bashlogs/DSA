/* Efficient for small data set
 * better than selection sort and bubble sort
 *
 */

#include<stdio.h>
int main(){
  int a[100],n,temp,i=0,j=0;
  printf("Enter how many number you want to enter?: ");
  scanf("%d",&n);
  for(i=0;i<n;i++){
    printf("Enter %dst number: ", i+1);
    scanf("%d",&a[i]);
  }
  //insertion sort
  for(i=1;i<n;i++){
    temp = a[i]; // n[i] means 2nd position
    j=i-1; // j = first position
    while((temp<a[j] && (j>=0))){ // while temp<n[j] means second position < first position && j >= 0 
      a[j+1] = a[j]; // normal swap to change position of n[1] to n[0];
      j=j-1; // to repeat the process;
    }
    a[j+1] = temp; // to initialise the second position value;
  }
  printf("Order in sorted elements: ");
  for(i=0;i<n;i++){
    printf("%d\t",a[i]);
  }
  return 0;
}
