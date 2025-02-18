#include<stdio.h>

int partition_exchange(int a[],int l,int h);
void quick_sort(int a[],int l,int h);

int main(){
	int n;
	printf("Enter the number of elements in the array:");
	scanf("%d",&n);
	int a[n];
	printf("Enter the elements of the array:\n");
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
    int l=0;
    int h=n-1;
    
    quick_sort(a,l,h);
    
    printf("The sorted array:\n");
    for(int i=0;i<n;i++){
    	printf("%d ",a[i]);
	}
		return 0;
}



int partition_exchange(int a[],int l,int h){

		int si=l;
		int ei=h;
		int pivot=a[l];
		
		while(si<ei){
			while(a[si]<=pivot){
				si++;
			}
			while(a[ei]>pivot){
				ei--;
			}
			if(si<ei){
			
			int temp;
			temp=a[si];
			a[si]=a[ei];
			a[ei]=temp;
		}
		
		}
		a[l]=a[ei];
		a[ei]=pivot;
	
	return ei;
}

void quick_sort(int a[],int l,int h){
	if(l<h){
	
	int pos=partition_exchange(a,l,h);
	
		quick_sort(a,pos+1,h);
	    quick_sort(a,l,pos-1);
	}
}

