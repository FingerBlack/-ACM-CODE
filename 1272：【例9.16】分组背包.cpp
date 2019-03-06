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
const int N=1011;
int n,m,t,sum=0;
int dp[N]; 
int w,v,p;
struct node
{
	int w,v;
	node(int a,int b){
		w=a;
		v=b;
	}
};
vector<node>vv[11];
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	cin>>m>>n>>t;
	for(int i=0;i<n;i++){
		scanf("%d%d%d",&w,&v,&p);
		vv[p].push_back(node(w,v));
	}
	for(int i=1;i<=t;i++){
		for(int k=m;k>=0;k--){
			for(int j=0;j<vv[i].size();j++){
				if(k>=vv[i][j].w)
				dp[k]=max(dp[k],dp[k-vv[i][j].w]+vv[i][j].v);
			}
		}
	}
	cout<<dp[m]<<endl;
	return 0;
}
