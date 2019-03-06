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
bool vis[N][N][N]={0};
int dir[6][3]={1,0,0,-1,0,0,0,1,0,0,-1,0,0,0,1,0,0,-1};
char f[N][N][N];
struct node
{
	int x,y,z,level;
	node(int a,int b,int c,int d){
		x=a;
		y=b;
		z=c;
		level=d;
	}
};
void bfs(int x,int y,int z){
	memset(vis,0,sizeof vis);
	int flag=0;
	vis[z][x][y]=1;
	queue <node>ss;
	ss.push(node(x,y,z,0));
	while(!ss.empty()){
		node p=ss.front();
		ss.pop();
		//cout<<p.level<<endl;
		//cout<<f[p.z][p.x][p.y]<<endl;
		if(f[p.z][p.x][p.y]=='E'){
			cout<<"Escaped in "<<p.level<<" minute(s)."<<endl;
			return;
		}
		//cout<<p.first<<" "<<p.second<<endl;
		for(int i=0;i<6;i++){
			int dx=p.x+dir[i][0];
			int dy=p.y+dir[i][1];
			int dz=p.z+dir[i][2];
			if(dx>=0&&dx<n&&dy>=0&&dy<m&&dz>=0&&dz<k&&f[dz][dx][dy]!='#'&&!vis[dz][dx][dy]){
				ss.push(node(dx,dy,dz,p.level+1));
				vis[dz][dx][dy]=1;
			}
		}
	}
	cout <<"Trapped!"<<endl; 
}
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	while(1){
		cin>>k>>n>>m;
		if(!k&&!n&&!m){
			break;
		}
		int x,y,z;
		for(int i=0;i<k;i++){
			for(int j=0;j<n;j++){ 
				scanf("%s",f[i][j]);
				for(int kk=0;kk<m;kk++){
					//cout<<f[i][j][k];
					if(f[i][j][kk]=='S'){
						z=i;
						x=j;
						y=kk;
					}
				}
				//cout<<f[i][j]<<endl;
			}
		}
		bfs(x,y,z);
	}
	return 0;
}
