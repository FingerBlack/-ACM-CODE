#include<iostream>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace  std;
#define local
const int N=10001;
int a[N];
int dp[N];
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		sort(a,a+n);
		dp[0]=a[0];
		dp[1]=a[1];
		dp[2]=a[0]+a[1]+a[2];
		for(int i=3;i<n;i++){
			dp[i]=min(dp[i-1]+a[0]+a[i],dp[i-2]+2*a[1]+a[i]+a[0]);
		//	cout<<dp[2]<<endl;
		}
		cout<<dp[n-1]<<endl;
	}
	return 0;
}
