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
const int N=10001;
int n,m;
int first[N],w[N],d[N],sign=0;
struct Edge
{
	int u,v,w,next;
};
Edge edge[1000];
void add_edge(int x,int y){
	edge[sign].v=y;
	edge[sign].w=1;
	edge[sign].next=first[x];
	first[x]=sign++;

	edge[sign].v=x;
	edge[sign].w=1;
	edge[sign].next=first[y];
	first[y]=sign++;
}
int bfs(int s){
	queue<int >qq;
	qq.push(s);
	memset(d,0,sizeof d);
	d[s]=0;
	while(!qq.empty()){
		int top=qq.front();
		qq.pop();
		for(int i=first[top];~i;i=edge[i].next){
			int to=edge[i].v;
			if(!d[to]&&to!=s){
				d[to]=d[top]+1;
				qq.push(to);
			}
		}
	}
	int sum=0;
	for(int i=1;i<=n;i++){
	//	cout<<d[i]<<endl;
		sum+=d[i]*w[i];
	}
	return sum;
}
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	int x,y;
	scanf("%d",&n);
	memset(first,-1,sizeof first);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&w[i],&x,&y);
		if(x!=0)
		add_edge(i,x);
		if(y!=0)
		add_edge(i,y);
	}
	int minn=1e8;
	for(int i=1;i<=n;i++){
		minn=min(minn,bfs(i));
	}
	//cout<<bfs(3)<<endl;
	cout<<minn<<endl;
	return 0;
}