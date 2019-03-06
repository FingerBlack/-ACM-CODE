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
const int N=101,inf=1e8;
int  dp[N][N],n,m;
char a[N];
int sum[N][N]={0};
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	cin>>n>>m;
	scanf("%s",a+1);
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++)
			sum[i][j]=sum[i][j-1]*10+(int)(a[j]-'0');
		dp[i][0]=sum[1][i];
	//	sum[i]=sum[i-1]+a[i];
	}
//	for(int i=1;i<=n;i++){
//		dp[i][i]=a[i];
//	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				dp[i][k]=max(dp[i][k],dp[j][k-1]*sum[j+1][i]);
			}
		//	cout<<dp[j][i]<<endl;
		}
	}
	cout<<dp[n][m]<<endl;
	return 0;
}


