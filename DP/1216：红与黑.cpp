#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace  std;
#define local
const int N=200;
char a[N][N];
bool vis[N][N]={0};
int n,m;
int xa,ya,xb,yb,flag;
int sum=0;
int b[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
void dfs(int x,int y){
//	q.push(a[i][j]);
	for(int i=0;i<4;i++){
		int cx=x+b[i][0];
		int cy=y+b[i][1];
		if(cx>=0&&cx<m&&cy>=0&&cy<n&&vis[cx][cy]==0&&a[cx][cy]=='.'){
			vis[cx][cy]=1;
			sum++;
			dfs(cx,cy); 
		}
	}
}
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	while(cin>>n>>m){
		if(n==0&&m==0){
			break;
		}
		int x,y;//cout<<1;
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				cin>>a[i][j];
				//cout<<a[i][j];
				if(a[i][j]=='@'){
				//	cout<<1<<endl;
					x=i;
					y=j;
				}
			}
			//cout<<endl;
		}
		cout<<x<<" "<<y<<endl;
		memset(vis,0,sizeof vis);
		sum=1;
		vis[x][y]=1;
		dfs(x,y);
		cout<<sum<<endl;
	}
	return 0;
}
