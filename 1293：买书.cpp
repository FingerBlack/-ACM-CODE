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
int w[10001];
void check(){
	//memset(dp,0x3f3f,sizeof dp);
	dp[0]=1;
	for(int i=0;i<4;i++){
		for(int j=w[i];j<=n;j++){
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
	cin>>n;
	w[0]=10;
	w[1]=20;
	w[2]=50;
	w[3]=100;
	check();
	cout<<dp[n]<<endl;
	return 0;
}
