#include<iostream>
#include<string>
using namespace  std;
#define local
typedef long long ll;
const int N=100;
int f[N][N]={0};
int n,sum=0;
int cx,cy;
int point[8][2];
void dfs(int x,int y,int level){
	/*for(int i=0;i<100;i++){
		for(int j=0;j<100;j++){
			if(f[i][j]){
				cout<<f[i][j]<<" ";
			}
		}
		cout<<endl;
	}*/
	if(level==n){
		sum++;
		return;
	}
	if(f[x-1][y]==false){
		f[x-1][y]=true;
		dfs(x-1,y,level+1);
		f[x-1][y]=false;
	}
	if(f[x][y-1]==false){
		f[x][y-1]=true;
		dfs(x,y-1,level+1);
		f[x][y-1]=false;
	}
	if(f[x][y+1]==false){
		f[x][y+1]=true;
		dfs(x,y+1,level+1);
		f[x][y+1]=false;
	}
}
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	cin>>n;
	//n--;
	f[50][50]=1;
	dfs(50,50,0);
	cout<<sum<<endl;
	return 0;
}
