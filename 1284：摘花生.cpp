#include<iostream>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<set>
#include<math.h>
#include<stack>
using namespace  std;
#define local
const int N=1001,inf=1e9;
//int f[N][N]={0};
int a[N][N],dp[N][N];
int n,m;
int pre[N]={0};
vector<int> edge[N];
int k=1;
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				scanf("%d",&a[i][j]);
				dp[i][j]=a[i][j];
			}
		}
		for(int i=1;i<n;i++){
			dp[i][0]+=dp[i-1][0];
		}
		for(int i=1;i<m;i++){
			dp[0][i]+=dp[0][i-1];
		}
		for(int i=1;i<n;i++){
			for(int j=1;j<m;j++){
				dp[i][j]+=max(dp[i-1][j],dp[i][j-1]);
			}
		}
		cout<<dp[n-1][m-1]<<endl;
	}
	return 0;
}
