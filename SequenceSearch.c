#include<stdio.h>
#define MAX 20

int SequenceSearch(int a[], int value, int n)// 顺查查找 
{
   int i;  
   for(i=0; i<n; i++){
  	  if(a[i]==value){
  		return i+1;
	  }
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
	index=SequenceSearch(a,value,n);
	printf("该数字的下标为：%d",index);
	return 0;
}
