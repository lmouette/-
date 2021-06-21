#include<bits/stdc++.h>
using namespace std;
#define Inf 1 << 31 - 1
struct node{
	double x;
	double y;
};
struct node point[200005];
int mpt[300005];
double dis(node a,node b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)); 
}
bool cmp1(node a,node b){
	if(a.x==b.x)return a.y<b.y;
	return a.x<b.x;
} 
bool cmp2(int a,int b){
	return point[a].y<point[b].y;
}
double run(int left,int right){
	int d = Inf; 
	if(left == right)return d; 
	if(left + 1 == right) return dis(point[left],point[right]); 
	int mid = left+ right >> 1; 
	double d1 = run(mid,right); 
	double d2 = run(left,mid - 1);
	double minn = min(d1,d2); 
	int k = 0;
	for(int i = left;i <= right;i++){
		if(fabs(point[mid].x-point[i].x)<=minn){
			mpt[++k]=i;
		}
	} 
	sort(mpt+1,mpt+k+1,cmp2); 
	for(int i = 1;i <= k;i++){
		for(int j = i + 1;j <= k && point[mpt[j]].y - point[mpt[i]].y <= minn;j++)
		{
			if(minn >= dis(point[mpt[i]],point[mpt[j]]))
				minn= dis(point[mpt[i]],point[mpt[j]]);
		}
	}
	return minn;
}
int main(){
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin>> point[i].x >> point[i].y;
	}
	sort(point + 1,point + n + 1,cmp1);
	printf("%.4lf",run(1,n));
	return 0;
}