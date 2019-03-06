#include<iostream>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<set>
#include<math.h>
#include<queue>
using namespace  std;
#define local
const int N=30000;
const int inf=1e9;
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	int n,x;
	scanf("%d",&n);
	//sum[0]=0;
	priority_queue <int ,vector<int>,greater<int> >qq;
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		qq.push(x);
	}
	int l,r;
	int sum=0;
	while(qq.size()!=1){
		l=qq.top();
		qq.pop();
		r=qq.top();
		qq.pop();
		sum+=(l+r);
		qq.push(l+r);
	}
	//cout<<dp[1(][2]<<endl;
	cout<<sum<<endl;
	return 0;
}
