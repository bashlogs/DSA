#include<stdio.h>
int main(){
    int a[10],i,j,temp,n;
    printf("\n Enter number of elements: ");
    scanf("%d",&n);
    printf("\n Enter elements: ");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=1;i<n;i++){
        temp=a[i];
        j=i-1;
        while(a[j]>temp&&j>=0){
            a[j+1]=a[j];
            --j;
        }
        a[j+1]=temp;
    }
    printf("\n Sorted list: ");
    for(i=0;i<n;i++)
        printf("\t%d",a[i]);
    return 0;
}
