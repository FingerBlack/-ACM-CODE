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
int dp[N][N]={0},w[N],c[N],num[N];
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	int n,m,t;
	cin>>m>>n>>t;
//	memset(dp1,0x3f3f,sizeof dp1);
	for(int i=1;i<=t;i++){
		scanf("%d%d",&w[i],&c[i]);
	}
	for(int i=1;i<=t;i++){
		for(int j=m;j>=w[i];j--){
			for(int k=n;k>=c[i];k--){
				dp[j][k]=max(dp[j][k],dp[j-w[i]][k-c[i]]+1);
			}

		}
	}
	int minn=n;
	for(int i=n;i>=0;i--){
		if(dp[m][i]==dp[m][n]){
			//break;
			minn=i;
		}
	}
//	for(int i=1;i<=m;i++){
//		for(int j=1;j<=n;j++){
//			cout<<dp[i][j]<<' ';
//		}
//		cout<<endl;
//	}
	cout<<dp[m][n]<<' '<<n-minn<<endl;
	return 0;
}
