#include<iostream>
#include<queue>
#include<string.h>
#include<vector>
using namespace  std;
#define local;
const int maxn =1e5+5;
const int inf=0x3f3f3f3f;
//int map[maxn][maxn];
bool vis[maxn];
int d[maxn];
int n,m;
struct node
{
	int v,dis;
	node(int a, int b){
		v=a;
		dis=b;
	}
	bool operator <(const node &a)const{
		return dis>a.dis;
	}
};
struct edge
{
	int f,t,v;
	edge(int from, int to,int value){
		f=from;
		t=to;
		v=value;
	}
//	edge(){}
};
vector< edge > G[maxn];
priority_queue< node > que;
int dijkstra(){
	memset(d,inf,sizeof d);
	memset(vis,0,sizeof vis);
	d[0]=0;
	que.push(node(0,0));
	while(!que.empty()){
		node tem=que.top();
		que.pop();
		if(vis[tem.v]){
			continue;
		}
		int u=tem.v;
		vis[u]=1;
		for(int i=0;i<G[u].size();i++){

			int to=G[u][i].t;
			int w=G[u][i].v;
		//		for(int i=0;i<n;i++){
	//		cout<<vis[i]<<endl;
	//	}
		//	cout<<u<<" "<<w<<" "<<to<<endl;
			if(d[to]>d[u]+w&&!vis[to]){
				d[to]=d[u]+w;
				que.push(node(to,d[to]));
			}
		}
	}
	return d[n-1];
}
int main()
{
#ifdef local
freopen("in","r",stdin);
freopen("out","wt+",stdout);
#endif
	 int T;
	 cin>>T;
	while(T--){
		cin>>n>>m;
		int f,t,v;
		//memset(map,0,sizeof map);
		for(int i=0;i<=n;i++){
			G[i].clear();
		}
		for(int i=0;i<m;i++){
			scanf("%d%d%d",&f,&t,&v);
		//	cout<<f<<" "<<t<<" "<<v<<endl;
		//	map[f][t]=v;
			//edges.push(new edge(f,t,v));
			edge a(f-1,t-1,v);
		//	edge b(t-1,f-1,v);
			G[f-1].push_back(a);
		//	G[t-1].push_back(b); 
		}
	
		dijkstra();
		for(int i=0;i<n;i++){
			cout<<d[i]<<endl;
		}
	}	
	return 0;
}
