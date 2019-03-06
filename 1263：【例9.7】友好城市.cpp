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
const int N=5001,inf=1e9;
//int f[N][N]={0};
struct node
{
	int l, r;
	bool operator <(const node &n)const{
		return l<n.l;
	}
}nn[N];
int a[N];
int pre[N]={0};
int dp[N];
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%d%d",&nn[i].l,&nn[i].r);
		//if(nn[i].l>nn[i].r){
		//	int tem=nn[i].l;
		//	nn[i].l=nn[i].r;
		//	nn[i].r=tem;
		//}
	}
	sort(nn,nn+n);
	//for(int i=0;i<n;i++){
	//	cout<<nn[i].l<<' '<<nn[i].r<<endl;
	//}
	dp[0]=1;
	for(int i=1;i<n;i++){
		dp[i]=1;
		for(int j=0;j<i;j++){
			if(nn[j].r<nn[i].r){
				dp[i]=max(dp[i],dp[j]+1);
			}
		}
	}
	int maxn=-1,pp=0;
	for(int i=0;i<n;i++){
		if(dp[i]>maxn){
			maxn=dp[i];
			pp=i;
		}
		//cout<<dp[i]<<' ';
	}
	cout<<maxn<<endl;
	return 0;
}
