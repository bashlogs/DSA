#include <stdio.h>
#include <stdbool.h>

bool duplicate(int* nums, int numsSize){
  int i=0;
    int j=1;
    while(i <= numsSize ){
        while(j <= numsSize){
            if(nums[i] == nums[j]){
                return 1;
            }
            j++;
        }
        i++;
        j++;
    }
  return 0;
}
int main(){
  int *nums[] = {1,2,3,1};
  int numsSize = sizeof(nums)/sizeof(nums[0]);
  bool a = duplicate(&nums, numsSize);
  printf("NumSize: %d\n", numsSize);
  printf("%d\n", a);
  return 0;
}
