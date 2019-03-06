#include<iostream>
#include<string>
#include<algorithm>
using namespace  std;
#define local
const int N=510;
int f[N];
int mm[N][N]={0};
int dp[N][N];
int a[N];
const int inf=0x3ffffff;
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	int n,m;
	cin>>m>>n;
	int x;
	a[1]=0;
	for(int i=2;i<=m;i++){
		cin>>x;
		a[i]=a[i-1]+x;
		//cout<<a[i]<<endl;
	}
	for(int i=1;i<=m;i++){
		for(int j=i+1;j<=m;j++){
			mm[i][j]=mm[i][j-1]+a[j]-a[(i+j)/2];
			//cout<<mm[i][j]<<" ";
		}
	}
	memset(dp,inf,sizeof dp);	
	for(int i=1;i<=m;i++){
		dp[i][1]=mm[1][i];
	//	cout<<dp[i][1]<<endl;
	}
	for(int i=1;i<=m;i++){
		for(int j=2;j<=n;j++){
			dp[i][j]=inf;
			for(int k=j-1;k<i;k++){
				dp[i][j]=min(dp[i][j],dp[k][j-1]+mm[k+1][i]);
			}
			//cout<<dp[i][j]<<endl;
		}

	}
	cout<<dp[m][n];
	return 0;
}
