#include<iostream>
#include<string>
using namespace  std;
#define local
const int N=100;
int f[N][N];
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	int t;
	int n,m;
	cin>>t;
	for(int i=1;i<=10;i++){
		f[0][i]=1;
	}
	for(int i=1;i<=10;i++){
		f[i][1]=1;
	}
	for(int i=1;i<=10;i++){
		for(int j=2;j<=10;j++){
			if(j>i){
				f[i][j]=f[i][i];
			}else{
				f[i][j]=f[i][j-1]+f[i-j][j];		
			}
		}
	}
	/*for(int i=0;i<=10;i++){
		for(int j=0;j<=10;j++){
			cout<<f[i][j]<<" ";
		}
		cout<<endl;
	}
	*/
	while(t--){
		cin>>n>>m;
		cout<<f[n][m]<<endl;
	}
	return 0;
}
