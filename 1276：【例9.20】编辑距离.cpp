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
const int N=2101,inf=1e8;
int  dp[N][N],n,m;
char a[N],b[N];
//int sum[N][N]={0};
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	//cin>>n>>m;
	scanf("%s%s",a+1,b+1);
	n=strlen(a+1);
	m=strlen(b+1);
	for(int i=1;i<=n;i++){
		dp[i][0]=i;
	}
	for(int i=1;i<=m;i++){
		dp[0][i]=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
			if(a[i]==b[j]){
				dp[i][j]=dp[i-1][j-1];
			}else{
				dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
			}
	//	sum[i]=sum[i-1]+a[i];
	}

	cout<<dp[n][m]<<endl;
	return 0;
}

