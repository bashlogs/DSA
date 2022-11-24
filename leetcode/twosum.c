#include <stdio.h>
#include <stdlib.h>
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i,j;
    int a,b;
    returnSize = (int *)malloc(sizeof(int) * 2);
    for(i=0;i<numsSize;i++){
        a = nums[i];
        for(j=i+1;j<numsSize;j++){
            b = nums[j];
            if((a + b) == target){
                returnSize[0] = i;
                returnSize[1] = j;
                return returnSize;
            }
        }
    }
    return returnSize;
}
int main(int argc, char const *argv[])
{
	/* code */
	int nums[] = {2, 7, 11, 15};
    int* returnSize;
	int *data = twoSum(nums, 3, 9, returnSize);

	printf("First: %d, second: %d\n", data[0], data[1]);

	free(data);
	return 0;
}