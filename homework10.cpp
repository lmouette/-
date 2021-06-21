#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const int maxn=1e5;
int a[maxn],b[maxn],w[maxn];
int n,c1,c2;

int main(){
    int sum,suma;
    printf("请输入集装箱的个数：");
    scanf("%d",&n);
    printf("请输入C1和C2：");
    scanf("%d %d",&c1,&c2);
    printf("请输入W1～Wn：");
    for(int i=1;i<=n;i++) scanf("%d",&w[i]),sum+=w[i];
    sort(w+1,w+1+n);
    int cnt=1;
    for(int i=1;i<=n;i++){
        if(suma+w[i]<=c1){
            a[cnt++]=w[i];
            suma+=w[i];
        }
    }
    if(sum-suma>c2){
        printf("无方案\n");
    }else{
        printf("A:");
        for(int i=1;i<cnt;i++) printf("%d ",a[i]);
        cout<<endl;
        printf("B:");
        for(int i=cnt;i<=n;i++) printf("%d ",w[i]);
    }
    return 0;
}