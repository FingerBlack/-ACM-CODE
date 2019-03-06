#include<iostream>
#include<string>
using namespace  std;
#define local
typedef long long ll;
const int N=100;
ll f[N][N];
int cx,cy;
int point[8][2];
bool check(int x,int y){
	for(int i=0;i<9;i++){
		if(x==point[i][0]&&y==point[i][1])
			return false;
	}
	return true;
}
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	int n,m;
	cin>>n>>m>>cx>>cy;
	int xx=1,yy=2;
	for(int i=0;i<4;i++){
		point[i][0]=cx+xx;
		point[i][1]=cy+yy;
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
		point[i][0]=cx+xx;
		point[i][1]=cy+yy;
		if(i%2){
			xx=-xx;
		}else{
			yy=-yy;
		}
		//cout<<xx<<endl;
		//cout<<point[i][0]<<" "<<point[i][1]<<endl;
	}
	point[8][0]=cx;
	point[8][1]=cy;
	memset(f,0,sizeof f);
	f[0][0]=1;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(check(i,j)){
				if(i!=0&&j!=0){
					f[i][j]=f[i-1][j]+f[i][j-1];
				}else if(i==0&&j!=0){
					f[i][j]=f[i][j-1];
				}else if(i!=0&&j==0){
					f[i][j]=f[i-1][j];
				}else if(i==0&&j==0){
					continue;
				}
			}
		}
	}
/*	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			cout<<f[i][j]<<" ";
		}
		cout<<endl; 
	}
	*/
	cout<<f[n][m]<<endl;
	return 0;
}
