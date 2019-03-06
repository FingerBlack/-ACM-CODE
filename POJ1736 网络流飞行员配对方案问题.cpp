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
int first[N],cur[N],d[N],sign=0;
const int inf=1e8;
int s=0,t;
struct Edge{
	int u,v,w,next;
	Edge(){
		next=-1;
	}
};
Edge edge[10000];
void add_edge(int u,int v,int w){
//	edge[sign].u=u;
	edge[sign].v=v;
	edge[sign].w=w;
	edge[sign].next=first[u];
	first[u]=sign++;
	edge[sign].v=u;
	edge[sign].w=0;
	edge[sign].next=first[v];
	first[v]=sign++;
}
int bfs(int s){
	queue<int >qq;
	memset(d,0,sizeof d);
	d[s]=1;
	qq.push(s);
	int to;
	while(!qq.empty()){
		int top=qq.front();
		qq.pop();
		for(int i=first[top];~i;i=edge[i].next){
			to=edge[i].v;
			if(edge[i].w>0&&d[to]==0){
				d[to]=d[top]+1;
				qq.push(to);
				if(to==t){
					return 1;
				}
			}	
		}
	}
	return d[t]!=0;
}
int dfs(int s,int flow){
	if(s==t){
		return flow;
	}
	int x=0,ans=0;
	for(int i=cur[s];~i;i=edge[i].next){
		int to=edge[i].v;
		if(edge[i].w>0&&d[to]==d[s]+1){
			x=dfs(to,min(flow-ans,edge[i].w));
			edge[i].w-=x;
			edge[i^1].w+=x;	
			ans+=x;
		
		//	if(edge[i].w)
				cur[s]=i;
			if(ans==flow){
				return flow;
			}
		}
	}
	if(ans==0){
		d[s]=0;
	}
	return ans;
}
int dinic(int t){
	int ans=0;
//	cout<<1<<endl;
	while(bfs(s)){
//		cout<<1<<endl;
		for(int i=0;i<=t;i++){
			cur[i]=first[i];
		}
		ans+=dfs(s,inf);
//		cout<<1<<endl;
	}
//	cout<<1<<endl;
	return ans;
}
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif

	int n,m,x,y;
	scanf("%d%d",&m,&n);
	t=n+m+1;
	memset(first,-1,sizeof first);
	while(1){
		scanf("%d%d",&x,&y);
		if(x==-1&&y==-1){
			break;
		}
		add_edge(x,y,1);
	}
	for(int i=1;i<=m;i++){
		add_edge(s,i,1);
	}
	for(int i=m+1;i<=m+n;i++){
		add_edge(i,t,1);
	}
	int ans = dinic(t);
	printf("%d\n", ans);	
	if(ans==0){
		printf("No Solution!\n");
		return 0;
	}
	for(int i=m+1;i<=n+m;i++){
		for(int j=first[i];~j;j=edge[j].next){
			if(edge[j].v!=t&&edge[j].w==1){
				printf("%d %d\n",edge[j].v,i);
			}
		}	
	}
	return 0;
}