#include<iostream>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<set>
#include<math.h>
#include <stack>
using namespace  std;
#define local
const int N=511,inf=1e8;
int  dp[N][N]={0},n,m;
int sum[N]={0},pos[N][N];
int a[N][N];
void print(int i,int j)
{
    int x,t;
    if(i==0) return;
    if(i==1)
    {
    	cout<<j;
        return ;
    }
    print(i-1,pos[i][j]);           
    cout<<" "<<j;  
}
//int sum[N][N]={0};
int main()
{
#ifdef local
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/in","r",stdin);
freopen("/Users/chenjishuang/Documents/GitHub/-ACM-CODE/out","wt+",stdout);
#endif
	cin>>n>>m;
	//cout<<n<<m<<endl;
	//memset(dp,0x3f3f,sizeof dp);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
	//		cout<<i<<j<<' '<<a[i][j]<<endl;
		}
	}
	for(int i=1;i<=m;i++){
		dp[1][i]=a[1][i];
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j<=m;j++){
		//	dp[i][j]=inf;	
		//	cout<<a[i][j]<<endl;
			for(int k=i-1;k<j;k++){
				if(dp[i-1][k]+a[i][j]>dp[i][j]){
					dp[i][j]=dp[i-1][k]+a[i][j];
					pos[i][j]=k;
				}
			}
		}
	}
	int maxx=0,pp=n;
	for(int k=n;k<=m;k++){
		if(dp[n][k]>maxx){
			maxx=dp[n][k];
			pp=k;
		}
	}
	cout<<maxx<<endl;
	//cout<<dp[2][4]<<endl;
	print(n,pp);
	return 0;
}
