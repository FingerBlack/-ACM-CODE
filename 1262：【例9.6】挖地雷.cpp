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
const int N=1001,inf=1e9;
//int f[N][N]={0};
int a[N];
int pre[N]={0};
int dp[N];
vector<int> edge[N];
int k=1;
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);	
		dp[i]=a[i];
		pre[i]=-1;
	}
	int f,t;
	while(scanf("%d%d",&f,&t)!=-1){
		if(!f&&!t)break;
		edge[t].push_back(f);
	}
	//cout<<dp[1]<<' ';
	for(int i=2;i<=n;i++){
		//cout<<edge[i].size()<<endl;
		for(int j=0;j<edge[i].size();j++){
			int u=edge[i][j];
			if(dp[u]+a[i]>dp[i]){
				dp[i]=dp[u]+a[i];
				pre[i]=u;
			}
		}
	//	cout<<dp[i]<<' ';
	}
	//cout<<endl;
	int maxn=-1,pp=0;
	for(int i=1;i<=n;i++){
		if(dp[i]>maxn){
			maxn=dp[i];
			pp=i;
		}
	}
	stack<int >ss;
	int i=pp;
	
	while(pre[i]!=-1){
		ss.push(i);
		i=pre[i];
	}
	ss.push(i);
	int flag=0;
	while(!ss.empty()){
		if(flag)cout<<'-';
		flag++;
		cout<<ss.top();
		ss.pop();
	}
	cout<<endl;
	cout<<maxn<<endl;
	return 0;
}
