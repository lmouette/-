#include<stdio.h>
#define MAX 20

int BinarySearch(int a[], int value, int n)//���ֲ��� 
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
	printf("���������鳤�ȣ�");
	scanf("%d",&n);
	printf("�밴�ǵݼ���ǵ���˳������ÿһ�������Կո������س���������"); 
	for(i=0;i<n;i++){
    	scanf("%d",&a[i]);
	}
  	printf("������Ҫ���ҵ����֣�");
  	scanf("%d",&value);
	index=BinarySearch(a,value,n);
	printf("�����ֵ��±�Ϊ��%d",index);
	return 0;
}
