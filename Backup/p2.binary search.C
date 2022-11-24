//Practical 2
#include<stdio.h>
int main(){
	int mid,i,low,high,search,n,a[100];
	printf("\n Enter the total number of elements to be stored in an array:");
	scanf("%d",&n);
	printf("\n Enter the elements in array:");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	printf("\n Enter the value to be searched:");
	scanf("%d",&search);
	low=0;
	high=n-1;
	mid=(low+high)/2;
	while(low<=high){
		if(a[mid]<search)
			low=mid+1;
		else
			if(a[mid]==search){
				printf("%d is found at location %d.",search,mid+1);
				break;
			}
			else
				high=mid-1;
				mid=(low+high)/2;
	}
	if(low>high)
		printf("\n Element not found.");
	return 0;
}