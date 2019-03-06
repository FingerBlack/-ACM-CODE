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
int  dp[N][N];
int a[N],sum[N];
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	int n;
	cin>>n;
	sum[0]=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]+a[i];
	}
//	for(int i=1;i<=n;i++){
//		dp[i][i]=a[i];
//	}
	for(int i=1;i<=n;i++){
		for(int j=i-1;j>=1;j--){
			dp[j][i]=inf;
			for(int k=j;k<i;k++){
				dp[j][i]=min(dp[j][i],dp[j][k]+dp[k+1][i]+sum[i]-sum[j-1]);
			}
		//	cout<<dp[j][i]<<endl;
		}
	}
	cout<<dp[1][n]<<endl;
	return 0;
}


