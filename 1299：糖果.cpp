#include<iostream>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<set>
#include<math.h>
#include <stack>
#include<set>
using namespace  std;
#define local
const int N=1111,inf=1e8;
int  dp[N][N]={0},n,m,k;
int a[N],b[N];
//int sum[N][N]={0};
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<k;i++)
		dp[0][i]=-inf;
	for(int i=1;i<=n;i++){

		for(int j=k-1;j>=0;j--){
			dp[i][j]=max(dp[i-1][j],dp[i-1][(j+k-a[i]%k)%k]+a[i]);
		//	cout<<dp[i][j]<<' ';
		}
		//cout<<endl;
	}
	cout<<dp[n][0]<<endl;
	return 0;
}
