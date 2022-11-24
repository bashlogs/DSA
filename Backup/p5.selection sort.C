#include<stdio.h>
int main(){
	int a[10],i,n,temp,j;
	printf("\n Enter the number of elements to be sorted:");
	scanf("%d",&n);
	printf("\n Enter the elements to be sorted:");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if (a[i]>a[j]){
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
	printf("\n The sorted list is: ");
	for(i=0;i<n;i++){
		printf("\t%d",a[i]);
	}
	return 0;
}