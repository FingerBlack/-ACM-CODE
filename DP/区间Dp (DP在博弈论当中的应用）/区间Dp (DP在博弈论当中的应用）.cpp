#include<iostream>
#include<algorithm>
using namespace  std;
#define local;
const int maxn =1e3;
const int inf =1e9;
int dp[maxn][maxn];
int n;
int sum[maxn];
int g1[maxn][maxn];
int g2[maxn][maxn];
//
int dealer(){
	for(int i=0;i<n;i++){
		dp[i][i]=sum[i]-sum[i-1];
		g1[i][i]=dp[i][i];
		g2[i][i]=dp[i][i];
	}

	for(int j=0;j<n;j++){
		for(int i=0;i<j;i++){
			int minn=0;
			minn=min(g1[i+1][j],minn);
			minn=min(g2[i][j-1],minn);
			dp[i][j]=sum[j]-sum[i-1]-minn;
			cout<<"dp "<<i<<" "<<j<<" "<<dp[i][j]<<endl;
			g1[i][j]=min(g1[i+1][j],dp[i][j]);
			g2[i][j]=min(g2[i][j-1],dp[i][j]);
		}
	}
	return dp[0][n-1];
}
int main()
{
#ifdef local
freopen("in","r",stdin);
freopen("out","wt+",stdout);
#endif
	while(cin>>n&&n){
		memset(dp,0,sizeof dp);
		memset(sum,0,sizeof sum);
		memset(g1,0,sizeof g1);
		memset(g2,0,sizeof g2);
		int x;
		cin>>x;
		sum[0]=x;
		for (int i = 1; i < n; ++i)
		{	

			cin>>x;
			sum[i]=sum[i-1]+x;
			//cout<<sum[i]<<endl;
			/* code */
		}
		cout<<dealer()<<endl;
		
	}		
	return 0;
}
