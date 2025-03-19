#include<stdio.h>

void mergesort(int a[],int l,int h,int mid);
void mergebreak(int a[],int l,int h);

int main(){
	int n;
	printf("Enter the no. of elements required in the array:");
	scanf("%d",&n);
	int a[n];
	printf("Enter the elements of the array:\n");
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	mergebreak(a,0,n-1);
	for(int i=0;i<n;i++){
		printf("%d ",a[i]);
	} 
	return 0;
}

void mergesort(int a[],int l,int h,int mid){
	int i=l;
	int j=mid+1;
	int k=0;
	int temp[h-l+1];
	
	while(i<=mid && j<=h){
		if(a[i]<a[j]){
			temp[k++]=a[i++];
		}
		else{
			temp[k++]=a[j++];
		}
	}
	while(i<=mid){
		temp[k++]=a[i++];
	}
	while(j<=h){
		temp[k++]=a[j++];
	}
	for(int i=l,k=0;i<=h;i++,k++){
		a[i]=temp[k];
	}
}

void mergebreak(int a[],int l,int h){
	if(l<h){
		int mid=(l+h)/2;
		mergebreak(a,l,mid);
		mergebreak(a,mid+1,h);
		mergesort(a,l,h,mid);
		}
}