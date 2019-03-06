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
const int N=111;
int n,m,t,sum=0;
int dp[N][N]; 
int w[1001],o[1001],h[1001];
void check(){
	memset(dp,0x3f3f,sizeof dp);
	dp[0][0]=0;
	for(int i=1;i<=t;i++){
		for(int j=n;j>=0;j--){
			for(int k=m;k>=0;k--){
				int dj=min(n,j+o[i]);
				int dk=min(m,k+h[i]);
				dp[dj][dk]=min(dp[dj][dk],dp[j][k]+w[i]);
			}
		}
	}
}
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	cin>>n>>m>>t;
	for(int i=1;i<=t;i++){
		scanf("%d%d%d",&o[i],&h[i],&w[i]);
	}
	check();
	cout<<dp[n][m]<<endl;
	return 0;
}
