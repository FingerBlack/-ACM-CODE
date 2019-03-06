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
		int n,m;
		cin>>m>>n;
		for(int i=1;i<=n;i++){
			scanf("%d%d",&w[i],&c[i]);
		}
		for(int i=1;i<=n;i++){
			for(int j=m;j>=w[i];j--){
				dp[j]=max(dp[j],dp[j-w[i]]+c[i]);
			}
		}
	//	for(int i=1;i<=m;i++){
	//		for(int j=1;j<=n;j++){
	//			cout<<dp[i][j]<<' ';
	//		}
	//		cout<<endl;
	//	}
		cout<<dp[m]<<endl;
		return 0;
	}
