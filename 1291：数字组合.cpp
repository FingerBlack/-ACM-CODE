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
long long dp[10005]={0}; 
int w[101];
void check(){
	//memset(dp,0x3f3f,sizeof dp);
	dp[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=m;j>=w[i];j--){
			dp[j]+=dp[j-w[i]];
		}
	//	cout<<endl;
	}
}
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&w[i]);
	}
	check();
	cout<<dp[m]<<endl;
	return 0;
}
