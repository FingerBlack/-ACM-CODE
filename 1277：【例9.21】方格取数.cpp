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
const int N=11,inf=1e8;
int  dp[N][N][N][N],n,m,x,y,z;
int a[N][N]={0};
//int sum[N][N]={0};
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	cin>>n;
	while(scanf("%d%d%d",&x,&y,&z)!=-1){
		if(!x&&!y&&!z){
			break;
		}
		a[x][y]=z;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)	
			for(int k=1;k<=n;k++){
				for(int h=1;h<=n;h++){	
					dp[i][j][k][h]=max(max(dp[i][j-1][k][h-1],dp[i][j-1][k-1][h]),max(dp[i-1][j][k-1][h],dp[i-1][j][k][h-1]))+a[i][j]+a[k][h];
					if(i==k&&j==h){
						dp[i][j][k][h]-=a[i][j];
					}
				}
	//	sum[i]=sum[i-1]+a[i];
			}
	}

	cout<<dp[n][n][n][n]<<endl;
	return 0;
}

