#include<stdio.h>
#include<stdlib.h>
#define MAX 20 
void Merge(int* A,int p,int r,int q){
	int x,y;
	int B[MAX],C[MAX];
	x=q-p+1;
	y=r-q;
	
	for(int i=1;i<=x;i++)
	{
		B[i]=A[i+p-1];	
	}
	
	for(int i=1;i<=y;i++)
	{
		C[i]=A[q+i];
	}
	int i=1,j=1,k=p;
	for(;i<=x&&j<=y;k++)
	{
		if(B[i]<=C[j]){
			
			A[k]=B[i];
			i++;
		}
		else{
			A[k]=C[j];
			j++;
		}
	
	}
	if(i>x){
		for(int m=k;m<=r;m++){
			A[m]=C[j+m-k];
		}		
	}
	else{
		for(int m=k;m<=r;m++){
			A[m]=B[i+m-k];
		}
	}
	

	
}
void MergeSort(int* A,int p,int r){
	  int q;
	 
	 if(p<r){
		 q=(p+r)/2;
		MergeSort(A,p,q);
		MergeSort(A,q+1,r);
	    Merge(A,p,r,q);
	 }	
	    
	
	
}


int main(){
	int A[8]={3,4,6,2,5,8,7,1};
	printf ("排序前数组：\n");
	for(int i=0;i<8;i++)
        printf("%d\t",A[i]);
    printf("\n");
    
	MergeSort(A,0,7);
	
	printf ("排序后数组：\n");
	
	for(int i=0;i<8;i++)
        printf("%d\t",A[i]);
	
	
	
	return 0;
}
