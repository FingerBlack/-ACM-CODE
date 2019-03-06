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
int dp[N]={0},w[N],c[N],num[N];
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	int n,m,ww,cc,numm;
	cin>>n>>m;
	int l=0;
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&ww,&cc,&numm);
		int k=1;
		while(numm>k){
			numm-=k;
			w[l]=k*ww;
			c[l]=k*cc;
			k<<=1;
			l++;
		}
		w[l]=numm*ww;
		c[l++]=numm*cc;
	}
	for(int i=0;i<l;i++){
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
