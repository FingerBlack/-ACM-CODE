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
int dp[N]={0},w[N],c[N];
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	int k,m,t;
	cin>>t;
	while(t--){
		cin>>m>>k;
		memset(dp,0,sizeof dp);
		for(int i=1;i<=m;i++){
			scanf("%d",&w[i]);
		}
		for(int i=1;i<=m;i++){
			scanf("%d",&c[i]);
		}
		for(int i=1;i<=m;i++){
			dp[i]=c[i];
			for(int j=1;j<i;j++){
				if(w[i]>w[j]+k){
					dp[i]=max(dp[i],dp[j]+c[i]);
				}
			}
		//	for(int i=1;i<=m;i++){
		//	maxx=max(maxx,dp[i]);
		//		cout<<dp[i]<<' ';
		//	}
		//	cout<<endl;
		}
		int maxx=0;
		for(int i=1;i<=m;i++){
			maxx=max(maxx,dp[i]);
		//	cout<<dp[i]<<' ';
		}
		//cout<<endl;
	//	for(int i=1;i<=m;i++){
	//		for(int j=1;j<=n;j++){
	//			cout<<dp[i][j]<<' ';
	//		}
	//		cout<<endl;
	//	}
		cout<<maxx<<endl;
	}
	return 0;
}
