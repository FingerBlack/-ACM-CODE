#include<iostream>
#include<queue>
#include<string.h>
#include<vector>
using namespace  std;
#define local;
const int maxn =1e5+5;
const int inf=0x7f;
//int map[maxn][maxn];
int vis[maxn];
int dp[maxn];
int n,m;
struct edge
{
	int f,t,v;
	edge(int from, int to,int value){
		f=from;
		to=t;
		v=value;
	}
//	edge(){}
};
vector< edge > G[maxn];
int dijkstra(){
	memset(dp,0x7f,sizeof dp);
	dp[0]=0;
	while(){
		
	}

}
int main()
{
#ifdef local
freopen("in","r",stdin);
freopen("out","wt+",stdout);
#endif
	while(cin>>n>>m){
		int f,t,v;
		//memset(map,0,sizeof map);
		for(int i=0;i<=n;i++){
			G[i].clear();
		}
		for(int i=0;i<m;i++){
			scanf("%d%d%d",&f,&t,&v);
		//	map[f][t]=v;
			//edges.push(new edge(f,t,v));
			G[f].push_back(edge(f,t,v)); 
		}
		dijkstra();

	}	
	return 0;
}
