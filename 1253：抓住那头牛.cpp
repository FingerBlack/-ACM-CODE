#include<iostream>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<set>
#include<math.h>
#include<stack>
#include<queue>
using namespace  std;
#define local
const int N=100001;
int k,n,m,K;
bool vis[N]={0};
struct node
{
	int x,level;
	node(int a,int d){
		x=a;
		level=d;
	}
};
void bfs(int x){
	memset(vis,0,sizeof vis);
	vis[x]=1;
	queue <node>ss;
	ss.push(node(x,0));
	while(!ss.empty()){
		node p=ss.front();
		ss.pop();
		//cout<<p.level<<endl;
		//cout<<f[p.z][p.x][p.y]<<endl;
		if(p.x==K){
			cout<<p.level<<endl;
			return;
		}
		//cout<<p.first<<" "<<p.second<<endl;
		int dx;
		dx=p.x+1;
		if(dx>=0&&!vis[dx]){
			ss.push(node(dx,p.level+1));
			vis[dx]=1;
		}
		dx=p.x-1;
		if(dx>=0&&!vis[dx]){
			ss.push(node(dx,p.level+1));
			vis[dx]=1;
		}
		dx=2*p.x;
		if(dx>=0&&dx<N&&!vis[dx]){
			ss.push(node(dx,p.level+1));
			vis[dx]=1;
		}
	}
	cout<<-1<<endl;
}
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	cin>>n>>K;
	bfs(n);
	return 0;
}
