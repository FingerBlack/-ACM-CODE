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
	const int N=1001;
	int f[N][N];
	int a[N];
	int dp[N];
	int k=1;
	int main()
	{
	#ifdef local
	freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
	freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
	#endif
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		dp[0]=a[0];
		int maxn=a[0];
		for(int i=1;i<n;i++){
			dp[i]=a[i];
			for(int j=0;j<i;j++){
				if(a[i]>a[j]){
					dp[i]=max(dp[i],dp[j]+a[i]);
				}
				if(dp[i]>maxn){
					maxn=dp[i];
				}
			}
		}
		cout<<maxn<<endl;
		return 0;
	}


