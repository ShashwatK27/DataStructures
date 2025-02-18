#include<stdio.h>
int main(){
    int n,index1,index2;
    printf("Enter the number of elements of the array:");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements of array:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter the index1 of array:\n");
    scanf("%d",&index1);
    printf("Enter the index2 of array:\n");
    scanf("%d",&index2);
    
    while(index1<index2){
        int p;
        p=a[index1];
        a[index1]=a[index2];
        a[index2]=p;
        index1++;
        index2--;
    }
    printf("Sorted array:\n");
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}