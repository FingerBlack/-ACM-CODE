#include<iostream>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<set>
#include<math.h>
#include<stack>
using namespace  std;
#define local
const int N=1001,inf=1e9;
int f[N][N]={0};
int a[N];
int pre[N]={0};
int dp[N];
int k=1;


int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&f[i][j]);
		}
		pre[i]=-1;
	}
	dp[0]=0;
	for(int i=1;i<n;i++){
		dp[i]=inf;
		for(int j=0;j<i;j++){
			if(f[j][i]!=0){
				if(dp[j]+f[j][i]<dp[i]){
					dp[i]=dp[j]+f[j][i];
					pre[i]=j;
				}
			}
		}
	}
	cout<<"minlong="<<dp[n-1]<<endl;
	stack<int >ss;
	int i=n-1;
	while(pre[i]!=-1){
		ss.push(i);
		i=pre[i];
	}
	ss.push(i);
	int flag=0;
	while(!ss.empty()){
		if(flag)cout<<' ';
		flag++;
		cout<<ss.top()+1;
		ss.pop();
	}
	return 0;
}
