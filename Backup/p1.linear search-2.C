//Practical 1
#include<stdio.h>
int main()
{
    int i,search,n,a[100];
    printf("\n Enter the total number of elements to be stored in array:");
    scanf("%d",&n);
    printf("\n Enter the %d elements:",n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("\n Enter the value to be searched:");
    scanf("%d",&search);
    for(i=0;i<n;i++){
        if (a[i]==search){
            printf("\n Element %d is at location %d:" ,search,i+1);
            break;
            }
    }
    if(i==n)
        printf("\n Element not found:");
    return 0;
}