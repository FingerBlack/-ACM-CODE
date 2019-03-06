#include<iostream>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<set>
#include<math.h>
using namespace  std;
#define local
const int N=1001;
int dp[N][N]={0},w[N],c[N];
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&w[i],&c[i]);
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<=n;j++){
			if(j>=w[i])
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+c[i]);
			else{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
//	for(int i=1;i<=m;i++){
//		for(int j=1;j<=n;j++){
//			cout<<dp[i][j]<<' ';
//		}
//		cout<<endl;
//	}
	cout<<dp[m][n]<<endl;
	return 0;
}
