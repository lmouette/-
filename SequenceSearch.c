#include<stdio.h>
#define MAX 20

int SequenceSearch(int a[], int value, int n)// ˳����� 
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
	printf("���������鳤�ȣ�");
	scanf("%d",&n);
	printf("�밴�ǵݼ���ǵ���˳������ÿһ�������Կո������س���������"); 
	for(i=0;i<n;i++){
    	scanf("%d",&a[i]);
	}
  	printf("������Ҫ���ҵ����֣�");
  	scanf("%d",&value);
	index=SequenceSearch(a,value,n);
	printf("�����ֵ��±�Ϊ��%d",index);
	return 0;
}
