#include<stdio.h>
int main(){
	int i,j, a[10],temp,n;
	printf("\n Enter the number of elements to be sorted:");
	scanf("%d",&n);
	printf("\n Enter the actual elements:");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<n-1;i++){
		for(j=0;j<n-1;j++){
			if(a[j]>a[j+1]){
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	printf("\n Ascending order is:\n");
	for(i=0;i<n;i++){
		printf("%d \t",a[i]);
	}
	return 0;
}