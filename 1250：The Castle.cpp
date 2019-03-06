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
int n,m,maxn=-1,number=0;
bool vis[N][N]={0};
int a[N][N];
int dir[4][2]={{0,-1},{-1,0},{0,1},{1,0}};
struct node
{
	int x,y,level;
	node(int a,int b,int c){
		x=a;
		y=b;
		level=c;
	}
};
int bfs(int x,int y){
	int flag=0;
	vis[x][y]=1;
	queue < node >ss;
	ss.push(node(x,y,0));
	int num=0;
	while(!ss.empty()){
		node p=ss.front();
		ss.pop();
		num++;
		//cout<<num<<endl;
		//cout<<p.first<<" "<<p.second<<endl;

		for(int i=0;i<4;i++){
		//	cout<<a[p.x][p.y]<<endl;
			if((a[p.x][p.y]&1)==1){
				a[p.x][p.y]>>=1;
				continue;
			}
			a[p.x][p.y]>>=1;
			int dx=p.x+dir[i][0];
			int dy=p.y+dir[i][1];
			//cout<<dx<<dy<<endl;

			if(dx>=0&&dx<n&&dy>=0&&dy<m&&!vis[dx][dy]){
				ss.push(node(dx,dy,p.level+1));
				vis[dx][dy]=1;
			}
		}
	}
	/*for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<vis[i][j]<<' ';
		}
		cout<<endl;
	}*/
	if(num>maxn){
		maxn=num;
	}
	number++;
	return 0; 
}
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	cin>>n>>m;
	//cout<<n<<m<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&a[i][j]);
	//		cout<<a[i][j]<<endl;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(!vis[i][j]){
				bfs(i,j);
			}
		}
	}
	cout<<number<<endl;
	cout<<maxn<<endl;
	return 0;
}
