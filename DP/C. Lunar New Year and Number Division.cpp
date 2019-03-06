#include<iostream>
#include<string>
#include<stdio.h>
#include<algorithm>
using namespace  std;
typedef long long ll;
//#define local
const int N=3*1e5+10;
ll	a[N];
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a,a+n);
	ll sum=0;
	for(int i=0;i<n/2;i++){
		sum+=((a[i]+a[n-i-1])*(a[i]+a[n-i-1]));
	}
	cout<<sum<<endl;
	return 0;
}
