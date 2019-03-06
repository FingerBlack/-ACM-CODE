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
const int N=10001;
int dp[N][N],n,m;
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	memset(dp,0x3f3f,sizeof dp);
	for(int j=1;j<=10;j++){
		dp[1][j]=1;
		dp[0][j]=0;
	}
	for(int j=1;j<=100;j++){
		dp[j][1]=j;
	}
	for(int i=2;i<=100;i++){
		for(int j=2;j<=10;j++){
			for(int t=1;t<=i;t++){
				dp[i][j]=min(dp[i][j],max(dp[t-1][j-1],dp[i-t][j])+1);
			}
		}
	}
	while(scanf("%d%d",&n,&m)!=-1){
		cout<<dp[n][m]<<endl;
	}	
	return 0;
}
