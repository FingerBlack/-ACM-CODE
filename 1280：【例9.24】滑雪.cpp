#include<iostream>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<set>
#include<math.h>
#include <stack>
using namespace  std;
#define local
const int N=511,inf=1e8;
int  dp[N][N]={0},n,m;
int sum[N]={0},pos[N][N];
int a[N][N];
int dir[4][2]={1,0,-1,0,0,1,0,-1};
void dfs(int x,int y)
{
	int dx,dy;
    for(int i=0;i<4;i++){
    	dx=x+dir[i][0];
    	dy=y+dir[i][1];
    	if(dx>=1&&dx<=n&&dy>=1&&dy<=m&&a[x][y]>a[dx][dy]){
    		if(dp[dx][dy]<dp[x][y]+1){
    			dp[dx][dy]=dp[x][y]+1;
    			dfs(dx,dy);
    		}
    	}
    }
}
//int sum[N][N]={0};
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	cin>>n>>m;
	//cout<<n<<m<<endl;
	//memset(dp,0x3f3f,sizeof dp);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			dp[i][j]=1;
	//		cout<<i<<j<<' '<<a[i][j]<<endl;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			dfs(i,j);
		}
	}
	int maxx=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			maxx=max(dp[i][j],maxx);
		}
	}
	cout<<maxx<<endl;
	//cout<<dp[2][4]<<endl;
	return 0;
}
