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
int f[N][N];
pair<int ,int >pre[N][N];
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
	int flag=0;
	vis[x][y]=1;
	queue <node>ss;
	ss.push(node(x,y,0));
	while(!ss.empty()){
		node p=ss.front();
		ss.pop();
		//cout<<p.level<<endl;
		//cout<<f[p.z][p.x][p.y]<<endl;
		if(p.x==4&&p.y==4){
			return ;
		}
		//cout<<p.first<<" "<<p.second<<endl;
		for(int i=0;i<4;i++){
			int dx=p.x+dir[i][0];
			int dy=p.y+dir[i][1];
			if(dx>=0&&dx<5&&dy>=0&&dy<5&&f[dx][dy]!=1&&!vis[dx][dy]){
				pre[dx][dy].first=p.x;
				pre[dx][dy].second=p.y;
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
		int x,y;
		for(int i=0;i<5;i++){
			for(int j=0;j<5;j++)
				scanf("%d",&f[i][j]);
				//cout<<f[i][j]<<endl;
		}
		bfs(0,0);
		stack<pair<int ,int > >ss;
		x=4,y=4;
		int dx,dy;
		while(x!=0||y!=0){
			ss.push(make_pair(x,y));
			dx=pre[x][y].first,dy=pre[x][y].second;
			x=dx;
			y=dy;
		}
		cout<<"(0, 0)"<<endl;
		while(!ss.empty()){
			cout<<'('<<ss.top().first<<", "<<ss.top().second<<')'<<endl;
			ss.pop();
		}
	return 0;
}
