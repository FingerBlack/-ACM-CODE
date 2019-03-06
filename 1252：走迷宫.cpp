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
const int N=101;
int k,n,m;
bool vis[N][N]={0};
int dir[4][2]={1,0,0,1,-1,0,0,-1};
char f[N][N];
struct node
{
	int x,y,level;
	node(int a,int b,int d){
		x=a;
		y=b;
		level=d;
	}
};
void bfs(int x,int y){
	memset(vis,0,sizeof vis);
	vis[x][y]=1;
	queue <node>ss;
	ss.push(node(x,y,1));
	while(!ss.empty()){
		node p=ss.front();
		ss.pop();
		//cout<<p.level<<endl;
		//cout<<f[p.z][p.x][p.y]<<endl;
		if(p.x==n-1&&p.y==m-1){
			cout<<p.level<<endl;
			return;
		}
		//cout<<p.first<<" "<<p.second<<endl;
		for(int i=0;i<4;i++){
			int dx=p.x+dir[i][0];
			int dy=p.y+dir[i][1];
			if(dx>=0&&dx<n&&dy>=0&&dy<m&&f[dx][dy]!='#'&&!vis[dx][dy]){
				ss.push(node(dx,dy,p.level+1));
				vis[dx][dy]=1;
			}
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
	cin>>n>>m;
	int x,y;
	for(int i=0;i<n;i++){
		scanf("%s",f[i]);
	}
	bfs(0,0);
	return 0;
}
