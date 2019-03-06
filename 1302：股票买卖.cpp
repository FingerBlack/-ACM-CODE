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
const int N=1e5+5;
int dp[N],a[N],maxx,n,f1[N],f2[N];
const int inf=1e8;
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
		}
		int minn=inf,maxx=-inf;
		f1[0]=0;
		for(int i=1;i<=n;i++){
			minn=min(minn,a[i]);
			f1[i]=max(f1[i-1],a[i]-minn);
		//	cout<<a[i]<<' '<<minn<<endl;
		}
		f2[n+1]=0;
		for(int i=n;i>=1;i--){
			maxx=max(maxx,a[i]);
			f2[i]=max(f2[i+1],maxx-a[i]);
			//cout<<a[i]<<' '<<maxx<<endl;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			ans=max(ans,f1[i]+f2[i]);
		//	cout<<f1[i]<<' '<<f2[i]<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
}
