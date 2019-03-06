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
const int N=101;
//int f[N][N];
int dp[N][N]={0};
int a[N][N]={0};
int pre[N][N];
//int k1=1,k2=1;
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	int n,m;
	cin>>n>>m;
//	cout<<n<<' '<<m<<endl;
	for(int i=1;i<=n;i++){
		a[i][0]=0;
		for(int j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
		}
	}	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			dp[i][j]=dp[i-1][j];
			pre[i][j]=0;
//			cout<<i<<' '<<j<<endl;
			for(int k=1;k<=j;k++){
				if(dp[i-1][j-k]+a[i][k]>=dp[i][j]){
					dp[i][j]=dp[i-1][j-k]+a[i][k];
					pre[i][j]=k;
				}
			}
		}
	}
	cout<<dp[n][m]<<endl;
	stack<int >ss;
	int i=n,j=m;
	while(i!=0){
		ss.push(pre[i][j]);
		j-=pre[i][j];
		i--;
	}
	while(!ss.empty()){
		i++;
		cout<<i<<' '<<ss.top()<<endl;
		ss.pop();
	}
	return 0;
}
