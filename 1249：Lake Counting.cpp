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
const int N=1001;
char f[N][N];
int n,m,num=0;
bool vis[N][N]={0};
int dir[8][2]={{1,0},{0,-1},{-1,0},{0,1},{1,1},{1,-1},{-1,1},{-1,-1}};
void bfs(int x,int y){
	int flag=0;
	if(vis[x][y]){
		return;
	}
	vis[x][y]=1;
	queue < pair<int,int > >ss;
	ss.push(make_pair(x,y));
	while(!ss.empty()){
		pair<int ,int > p=ss.front();
		ss.pop();
		//cout<<p.first<<" "<<p.second<<endl;
		for(int i=0;i<8;i++){
			int dx=p.first+dir[i][0];
			int dy=p.second+dir[i][1];
			if(dx>=0&&dx<n&&dy>=0&&dy<m&&f[dx][dy]=='W'&&!vis[dx][dy]){
				ss.push(make_pair(dx,dy));
				vis[dx][dy]=1;
			}
		}
	}
	num++;
}
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%s",f[i]);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(f[i][j]=='W'&&!vis[i][j]){
				bfs(i,j);
			}
		}
	}
	cout<<num<<endl;
	return 0;
}
