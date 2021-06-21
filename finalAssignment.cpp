#include<bits/stdc++.h>

using namespace std;
const int MAXN=1005;
const int MAXV=20005;
int path[MAXN][MAXV];
int dp[MAXV];

int sum;  
int n; 
int t[MAXN];
int ans[MAXN];  
int main()
{
    sum=0;
    memset(dp,0,sizeof dp);
    memset(path,0,sizeof path);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>t[i];
        sum+=t[i];
    }
    int V=sum/2;
    for(int i=1;i<=n;i++){
        for(int j=V;j>=t[i];j--){
            if(dp[j-t[i]]+t[i]>dp[j]){
                dp[j]=dp[j-t[i]]+t[i];
                path[i][j]=1;
            }
        }
    }

    for(int i=n,j=V;i>=1&&j>0;i--){
        if(path[i][j]){
            ans[i]=1;
            j-=t[i];
        }
    }
    cout<<"总加工时间为:";
    cout<<max(dp[V],(sum-dp[V]))<<endl;
    cout<<"调度方案为:"<<endl;
    for(int i=1;i<=n;i++){
        cout<<"任务:"<<i<<" "<<"加工机器:"<<ans[i]+1<<endl;
    }
}