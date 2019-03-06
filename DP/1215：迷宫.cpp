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
	if(x==xb&&y==yb){
		flag=1; 
	}
	for(int i=0;i<4;i++){
		if(flag){
			break;
		}
		int cx=x+b[i][0];
		int cy=y+b[i][1];
		if(cx>=0&&cx<n&&cy>=0&&cy<n&&vis[cx][cy]==0&&a[cx][cy]=='.'){
			vis[cx][cy]=1;
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
	int t;
	cin>>t;
	while(t--){
		cin>>n;//cout<<1;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>a[i][j];
			}
		}
		memset(vis,0,sizeof vis);
		cin>>xa>>ya>>xb>>yb;
		if(a[xa][ya]=='#'||a[xb][yb]=='#'){
			cout<<"NO"<<endl;
		}else{
			flag=0;
			vis[xa][ya]=1;
			dfs(xa,ya);
			if(flag){
				cout<<"YES"<<endl;
			}else{
				cout<<"NO"<<endl;
			}
		}
	}
	return 0;
}
