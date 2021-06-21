#include<bits/stdc++.h>
using namespace std;
int n,k; //n是5的倍数  k表示第k小元素  
int a;
vector<int>s;
void select(vector<int> s,int n,int k){
	vector<int>ant,m,s1,s2;
	ant=s;
	for(int i=0;i<n;i+=5){  //s划成五个一组，+的是5 
		int len=min(5,n-i);
		sort(ant.begin()+i,ant.begin()+i+len);
		m.push_back(ant[i+(len-1)/2]); //中位数 
	}
	sort(m.begin(),m.end());
	int midd=m[(m.size()-1)/2];
	for (int i = 0; i < n; i += 5) {
	if (n-i<5) { //若组不足5个，直接遍历比大小
		for (int j = i; j < n; j++) {
			if (ant[j] > midd) s2.push_back(ant[j]);
			else if(ant[j]<midd) s1.push_back(ant[j]);
		}
		break;
	}
	//该组个数为5个时
	if (ant[i + 2] < midd) {//该组中位数小于m时
		for (int j = i; j <=i+2; j++) s1.push_back(ant[j]);
		for (int j = i + 3; j < i+5; j++){
			if (ant[j] > midd) s2.push_back(ant[j]);
			else s1.push_back(ant[j]);
		}
	}
	else if (ant[i + 2] > midd) {//该组中位数大于m时
		for (int j = i; j <= i+2; j++) {
			if (ant[j] > midd)	s2.push_back(ant[j]);
			else s1.push_back(ant[j]);
		}
		for (int j = i + 3; j < i+5; j++) s2.push_back(ant[j]);
	}
	else { //等于 
		for (int j = i; j < i+2; j++) s1.push_back(ant[j]);
		for (int j = i + 3; j <i+5; j++) s2.push_back(ant[j]);
		}
	}
	//分治 
	int cnt1 = s1.size(), cnt2 = s2.size();
	if (k==cnt1+1) {
		cout<<midd<<endl;
		return;
	}else if (k <= cnt1)
		select(s1, cnt1, k);
	else
		select(s2, cnt2, k-cnt1-1);
} 
int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a;
		s.push_back(a);
	}
	cout<<"n="<<n<<" k="<<k<<endl;
	for(int i=0;i<s.size();i++){
		cout<<s[i]<<" ";
	}
	cout<<"\n第"<<k<<"小的数是";
	select(s, n, k);
}
//10 5
//7 8 9 1 2 3 4 5 6 10
