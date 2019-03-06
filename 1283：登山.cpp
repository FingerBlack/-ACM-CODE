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
//int f[N][N];
int dp1[N],dp2[N],dp[N];
int a[N],b[N],f[N];
int k1=1,k2=1;
int uppercase1(int kk){
	int l=0,r=k1,mid;
	while(l+1<r){
	//	cout<<l<<' '<<r<<endl;
		mid=(l+r)/2;
		if(dp1[mid]<kk){
			l=mid;
		}else{
			r=mid;
		}

	}
	//cout<<l<<' '<<r<<endl;
	return r;
}
int uppercase2(int kk){
	int l=0,r=k2,mid;
	while(l+1<r){
	// 	cout<<l<<' '<<r<<endl;
		mid=(l+r)/2;
		if(dp2[mid]<kk){
			l=mid;
		}else{
			r=mid;
		}

	}
	//cout<<l<<' '<<r<<endl;
	return r;
}
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	int n;
	int pp=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&f[i]);
	}
	a[1]=1;
	dp1[k1++]=f[1];
	for(int i=2;i<=n;i++){
	//	for(int i=1;i<=n;i++){
	//		cout<<a[i]<<' ';
	//	}
	//	cout<<k1<<endl;
		if(f[i]>dp1[k1-1]){
			dp1[k1++]=f[i];
			a[i]=k1-1;
			//cout<<1<<endl;
		}else{
			pp=uppercase1(f[i]);
			//cout<<pp<<endl;
			dp1[pp]=f[i];
			a[i]=pp;
		}
	}
	dp2[k2++]=f[n];
	b[n]=1;
	for(int i=n-1;i>=1;i--){
	//	for(int i=1;i<=n;i++){
	//		cout<<b[i]<<' ';
	//	}
	//	cout<<endl;
		if(f[i]>dp2[k2-1]){
			dp2[k2++]=f[i];
			b[i]=k2-1;
		}else{
			pp=uppercase2(f[i]);
			dp2[pp]=f[i];
			b[i]=pp;
		}
	}
	int maxn=-1;
	for(int i=1;i<=n;i++){
	//	cout<<a[i]<<" "<<b[i]<<endl;
		maxn=max(maxn,a[i]+b[i]-1);
	}
	cout<<maxn<<endl;
	return 0;
}
