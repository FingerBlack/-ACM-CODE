#include<iostream>
#include<string>
using namespace  std;
#define local
typedef long long ll;
const int N=100;
ll f[N][N];
int cx,cy;
int point[8][2];
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	int n,m;
	cin>>n>>m;
	memset(f,0,sizeof f);
	f[0][0]=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
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
/*	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			cout<<f[i][j]<<" ";
		}
		cout<<endl; 
	}
	*/
	cout<<f[n-1][m-1]<<endl;
	return 0;
}
