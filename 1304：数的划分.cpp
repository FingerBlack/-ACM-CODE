#include<iostream>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<set>
#include<math.h>
#include <stack>
#include<set>
using namespace  std;
#define local
const int N=1111,inf=1e8;
int  dp[N][N]={0},n,m,k;
int a[N],b[N];
//int sum[N][N]={0};
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	int t;
	cin>>m>>n;
	dp[0][0]=1;
	for(int i=0;i<=10;i++){
//		dp[0][i]=1;
//		dp[i][0]=1;
	}
	for(int k=1;k<=m;k++)
		for(int i=1;i<=n;i++){
			for(int j=k;j<=m;j++){
				dp[i][j]+=dp[i-1][j-k];
				//cout<<dp[i][j]<<' ';
			}
			//cout<<endl;
	}
	cout<<dp[n][m]<<endl;
	return 0;
}
