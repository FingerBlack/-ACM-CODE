	#include<iostream>
	#include<string>
	#include<string.h>
	using namespace  std;
	#define local
	typedef long long ll;
	const int N=100;
	int sum=0;
	bool vis[N][N];
	int point[8][2];
	int n,m;
	void init(){
		int xx=1,yy=2;
		for(int i=0;i<4;i++){
			point[i][0]=xx;
			point[i][1]=yy;
			if(i%2){
				xx=-xx;
			}else{
				yy=-yy;
			}
			//cout<<point[i][0]<<" "<<point[i][1]<<endl;
		}
		xx=2;
		yy=1;
		for(int i=4;i<8;i++){
			point[i][0]=xx;
			point[i][1]=yy;
			if(i%2){
				xx=-xx;
			}else{
				yy=-yy;
			}
			//cout<<xx<<endl;
			//cout<<point[i][0]<<" "<<point[i][1]<<endl;
		}
	}
	void dfs(int x,int y,int count){
		if(count==m*n){
			sum++;
			return;
		}
		for(int i=0;i<8;i++){
			int cx=x+point[i][0];
			int cy=y+point[i][1];
			if(cx>=0&&cx<n&&cy>=0&&cy<m&&!vis[cx][cy]){
				vis[cx][cy]=1;
				dfs(cx,cy,count+1);
				vis[cx][cy]=0;
			}
		}

	}
	int main()
	{
	#ifdef local
	freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
	freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
	#endif
		init();
		int t;
		cin>>t;
		int x,y;
		while(t--){
			sum=0;
			memset(vis,0,sizeof vis);
			cin>>n>>m>>x>>y;
			vis[x][y]=1;
			dfs(x,y,1);
			cout<<sum<<endl;
		}
	/*	for(int i=0;i<=n;i++){
			for(int j=0;j<=m;j++){
				cout<<f[i][j]<<" ";
			}
			cout<<endl; 
		}
		*/
		return 0;
	}
