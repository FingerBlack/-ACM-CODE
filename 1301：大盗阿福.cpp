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
const int N=1e5;
int dp[N],a[N],maxx,n;
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	int t;
	cin>>t;
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			dp[i]=a[i];
		}
		int maxx=0;
		dp[0]=0;
		dp[1]=a[1];
		for(int i=2;i<=n;i++){
		//	for(int j=1;j<i-1;j++){
			dp[i]=max(dp[i-1],dp[i-2]+a[i]);
		//	}
			if(dp[i]>maxx){
				maxx=dp[i];
			}
		}
		cout<<maxx<<endl;
	}
	return 0;
}
