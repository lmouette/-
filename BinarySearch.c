#include<stdio.h>
#define MAX 20

int BinarySearch(int a[], int value, int n)//二分查找 
{
    int low, high, mid;
    low = 0;
    high = n-1;
    while(low<=high)
    {
        mid = (low+high)/2;
        if(a[mid]==value)
            return mid+1;
        if(a[mid]>value)
            high = mid-1;
        if(a[mid]<value)
            low = mid+1;
    }
    return 0;
}


int main(){
	int n,i;
	int a[MAX];
	int value;
	int index; 
	printf("请输入数组长度：");
	scanf("%d",&n);
	printf("请按非递减或非递增顺序输入每一个数（以空格间隔，回车结束）："); 
	for(i=0;i<n;i++){
    	scanf("%d",&a[i]);
	}
  	printf("请输入要查找的数字：");
  	scanf("%d",&value);
	index=BinarySearch(a,value,n);
	printf("该数字的下标为：%d",index);
	return 0;
}
