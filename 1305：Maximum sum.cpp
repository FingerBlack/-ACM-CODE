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
const int N=51111,inf=1e8;
long long dp1[N]={0},dp2[N],dp1max[N],dp2max[N],n,m,k;
long long  a[N];
//int sum[N][N]={0};
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		long long  b=a[1];
		dp1[1]=a[1];
		dp1max[1]=a[1];
		for(int i=2;i<=n;i++){
			if(b<0){
				dp1[i]=a[i];
				b=a[i];
			}else{
				b+=a[i];
				dp1[i]=b;
			}
			if(dp1max[i-1]>dp1[i]){
				dp1max[i]=dp1max[i-1];
			}else{
				dp1max[i]=dp1[i];
			}
		}
		b=a[n];
		dp2[n]=a[n];
		dp2max[n]=a[n];
		for(int i=n-1;i>=1;i--){
			if(b<0){
				dp2[i]=a[i];
				b=a[i];
			}else{
				b+=a[i];
				dp2[i]=b;
			}
			if(dp2max[i+1]>dp2[i]){
				dp2max[i]=dp2max[i+1];
			}else{
				dp2max[i]=dp2[i];
			}
		}
		long long  maxx=dp1max[1]+dp2max[2];
		for(int i=1;i<n;i++){
			maxx=max(maxx,dp1max[i]+dp2max[i+1]);
		//	cout<<maxx<<' '<<dp1max[i]<<' '<<dp2max[i+1]<<endl;
		}
		cout<<maxx<<endl;
	}
		
	return 0;
}
