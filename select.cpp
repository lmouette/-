#include<bits/stdc++.h>
using namespace std;
int n,k; //n��5�ı���  k��ʾ��kСԪ��  
int a;
vector<int>s;
void select(vector<int> s,int n,int k){
	vector<int>ant,m,s1,s2;
	ant=s;
	for(int i=0;i<n;i+=5){  //s�������һ�飬+����5 
		int len=min(5,n-i);
		sort(ant.begin()+i,ant.begin()+i+len);
		m.push_back(ant[i+(len-1)/2]); //��λ�� 
	}
	sort(m.begin(),m.end());
	int midd=m[(m.size()-1)/2];
	for (int i = 0; i < n; i += 5) {
	if (n-i<5) { //���鲻��5����ֱ�ӱ����ȴ�С
		for (int j = i; j < n; j++) {
			if (ant[j] > midd) s2.push_back(ant[j]);
			else if(ant[j]<midd) s1.push_back(ant[j]);
		}
		break;
	}
	//�������Ϊ5��ʱ
	if (ant[i + 2] < midd) {//������λ��С��mʱ
		for (int j = i; j <=i+2; j++) s1.push_back(ant[j]);
		for (int j = i + 3; j < i+5; j++){
			if (ant[j] > midd) s2.push_back(ant[j]);
			else s1.push_back(ant[j]);
		}
	}
	else if (ant[i + 2] > midd) {//������λ������mʱ
		for (int j = i; j <= i+2; j++) {
			if (ant[j] > midd)	s2.push_back(ant[j]);
			else s1.push_back(ant[j]);
		}
		for (int j = i + 3; j < i+5; j++) s2.push_back(ant[j]);
	}
	else { //���� 
		for (int j = i; j < i+2; j++) s1.push_back(ant[j]);
		for (int j = i + 3; j <i+5; j++) s2.push_back(ant[j]);
		}
	}
	//���� 
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
	cout<<"\n��"<<k<<"С������";
	select(s, n, k);
}
//10 5
//7 8 9 1 2 3 4 5 6 10
