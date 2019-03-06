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
int n=100,m,num=0;
bool vis[N][N]={0};
int dir[8][2]={{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
struct node
{
	int x,y,level;
	node(int a,int b,int c){
		x=a;
		y=b;
		level=c;
	}
};
int ax,ay,bx,by;
void bfs(int x,int y){
	int flag=0;
	memset(vis,0,sizeof vis);
	vis[x][y]=1;
	queue < node >ss;
	ss.push(node(x,y,0));
	while(!ss.empty()){
		node p=ss.front();
		ss.pop();
		if(p.x==bx&&p.y==by){
			cout<<p.level<<endl;
			return;
		}
		//cout<<p.x<<' '<<p.y<<endl;
		//cout<<p.first<<" "<<p.second<<endl;
		for(int i=0;i<8;i++){
			int dx=p.x+dir[i][0];
			int dy=p.y+dir[i][1];
			if(dx>=0&&dx<n&&dy>=0&&dy<n&&!vis[dx][dy]){
				ss.push(node(dx,dy,p.level+1));
				vis[dx][dy]=1;
			}
		}
	}
	//cout<<-1<<endl;
}
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	int t;
	cin>>t;
	while(t--){
		cin>>n;
	//	cout<<n<<endl;
		cin>>ax>>ay>>bx>>by;
		bfs(ax,ay);
	}
	return 0;
}
