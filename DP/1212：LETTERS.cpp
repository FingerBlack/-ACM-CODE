#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace  std;
#define local
const int N=100;
char a[N][N];
char q[N];
int n,m;
int sum=0;
int b[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
void dfs(int x,int y,char q[],int l){
//	q.push(a[i][j]);
	int flag1=0;
	for(int i=0;i<4;i++){
		int cx=x+b[i][0];
		int cy=y+b[i][1];
		if(cx>=0&&cx<n&&cy>=0&&cy<m){
			char c=a[cx][cy];
			int flag=0;
			for(int i=0;i<l;i++){
				if(q[i]==c){
					flag=1;
				}
			}
			if(!flag){
				flag1=1;
				q[l]=c;
				dfs(cx,cy,q,l+1);
			}
		}
	}
	if(!flag1){
		sum=max(sum,l);
		return;
	}
}
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
		}
	}
	q[0]=a[0][0];
	dfs(0,0,q,1);
	cout<<sum<<endl;
	return 0;
}
